#include <stdio.h>
#include <string.h>

#include "s21_decimal.h"

//-----------Вывод decimal в консоль-----------//
void s21_print_decimal(s21_big_decimal *value) {
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;  //Кол-во bits в структуре
  for (int i = size_decimal; i >= 0; i--) {  //Цикл bits
    // printf("bits[%d] ", i);
    for (int j = 31; j >= 0; j--) {  //Цикл byte в bits
      if (value->bits[i] & (1 << j)) {
        printf("1");
      } else {
        printf("0");
      }
    }
    printf("\n");
  }
}

//-----------Получение бита-----------//
int s21_get_bit(s21_big_decimal *value, int index) {
  int num_bit = index / 32;  // определяем в каком bits структуры работаем
  int position =
      index % 32;  // определяем позицию бита, который хотим проверить
  return (value->bits[num_bit] & (1 << position)) >>
         position;  // возвращаем значение искомого бита
}

//-----------Изменение бита-----------//
void s21_set_bit(s21_big_decimal *value, int index, int bit) {
  int num_bit = index / 32;
  int position = index % 32;
  if (bit)
    value->bits[num_bit] |= (1 << position);  // меняем интересующий бит на 1
  else
    value->bits[num_bit] &= ~(1 << position);  // меняем на 0
}

//-----------Получение знака decimal-----------//
int s21_get_sign(s21_big_decimal *value) {
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;  //Кол-во bits в структуре
  int check_sign = value->bits[size_decimal] >> 31;
  return check_sign;
}

//-----------Изменение знака decimal-----------//
void s21_set_sign(s21_big_decimal *value, int bit) {
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;  //Кол-во bits в структуре
  if (bit) {
    value->bits[size_decimal] |= MASK_MINUS;
  } else {
    value->bits[size_decimal] &= ~MASK_MINUS;
  }
}

//-----------Получение степени decimal-----------//
int s21_get_pow(s21_big_decimal *value) {
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;
  int pow;
  if (s21_get_sign(value)) {
    pow = (value->bits[size_decimal] ^ MASK_MINUS) >> 16;
  } else {
    pow = value->bits[size_decimal] >> 16;
  }
  return pow;
}

//-----------Занесение степени decimal-----------//
void s21_set_pow(s21_big_decimal *value, int pow_value) {
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;
  int pow;
  if (s21_get_sign(value)) {
    pow = (value->bits[size_decimal] ^ MASK_MINUS) >> 16;
    pow = pow_value;
    pow = pow_value << 16;
    s21_set_sign(value, 1);
  } else {
    pow = value->bits[size_decimal] >> 16;
    pow = pow_value;
    pow = pow_value << 16;
  }

  value->bits[size_decimal] = pow;
}

//-----------Разница степеней decimal-----------//
int s21_difference_pow(s21_big_decimal *value1, s21_big_decimal *value2) {
  // if return 0 ? степени одинаковые
  // if return > 0 ? степень value1 больше, чем value2 в return раз
  // if return < 0 ? степень value1 меньше, чем value2 в return раз

  return (s21_get_pow(value1)) - (s21_get_pow(value2));
}

//-----------Увеличение степени на n раз-----------//
void s21_levelup_pow(s21_big_decimal *value, int difference_number) {
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;
  int value_pow = 0;
  //Заполнение массива под степень
  if (s21_get_sign(value)) {
    value_pow = (value->bits[size_decimal] ^ MASK_MINUS) >> 16;
    value_pow += difference_number;
    value->bits[size_decimal] = value_pow << 16;
    s21_set_sign(value, 1);
  } else {
    value_pow = value->bits[size_decimal] >> 16;
    value_pow += difference_number;
    value->bits[size_decimal] = value_pow << 16;
  }
}

//-----------Функция умножения-----------//
void s21_mul_ten(s21_big_decimal value1, s21_big_decimal value2, s21_big_decimal *result) {
  for (int i = 0; i < 256; i++) {
    int temp = s21_get_bit(&value2, i);

    s21_big_decimal vremia = {0, 0, 0, 0, 0, 0, 0, 0};
    if (temp) {
      for (int j = 0; j < 256; j++) {
        if (s21_get_bit(&value1, j)) {
          s21_set_bit(&vremia, i + j, 1);
        }
      }
      s21_add_function(vremia, *result, result);
    }
  }
}

//-----------Функция сложения-----------//
void s21_add_function(s21_big_decimal value1, s21_big_decimal value2, s21_big_decimal *result) {
  int check = 0;
  int buff = 0;
  memset(result, 0, sizeof(result));
  for (int i = 0; i <= 223; i++) {
    check = s21_get_bit(&value1, i) + s21_get_bit(&value2, i);
    if (check == 0) {
      if (buff) {
        s21_set_bit(result, i, 1);
        buff = 0;
      } else {
        s21_set_bit(result, i, 0);
      }
    } else if (check == 1) {
      if (buff) {
        s21_set_bit(result, i, 0);
      } else {
        s21_set_bit(result, i, 1);
      }
    } else if (check == 2) {
      if (buff) {
        s21_set_bit(result, i, 1);
      } else {
        s21_set_bit(result, i,0);
        buff = 1;
      }
    }
  }
}

//-----------Функция вычитания-----------//
void s21_sub_function(s21_big_decimal value1, s21_big_decimal value2, s21_big_decimal *result) {
  int check = 0;
  int buff = 0;
  memset(result, 0, sizeof(result));
  for(int i = 0; i <= 255; i++){
    check = s21_get_bit(&value1, i) - s21_get_bit(&value2, i);
    if(check == 0){
      if(buff){
        s21_set_bit(result, i, 1);
      }else{
        s21_set_bit(result, i, 0);
      }
    }else if(check == 1){
      if(buff){
        s21_set_bit(result, i, 0);
        buff = 0;
      }else{
        s21_set_bit(result, i, 1);
      }
    }else if(check == -1){
      if(buff){
        s21_set_bit(result, i, 0);
      }else{
        s21_set_bit(result, i, 1);
        buff = 1;
      }
    }
  }
}