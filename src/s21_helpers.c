#include "s21_decimal.h"
#include <stdio.h>

//-----------Вывод decimal в консоль-----------//
void s21_print_decimal(s21_decimal *value){
  int size_decimal = sizeof(s21_decimal) / 4 - 1; //Кол-во bits в структуре
  for(int i = size_decimal; i >= 0; i--){
    printf("bits[%d] ", i);
    for(int j = 31; j >= 0; j--){
      printf("%d", value->bits[i] & (1 << j));
    }
    printf("\n");
  }
}

//-----------Получение бита-----------//
int s21_get_bit(s21_decimal *value, int index) {
  int num_bit = index / 32; // определяем в каком bits структуры работаем
  int position = index % 32; // определяем позицию бита, который хотим проверить 
  return (value->bits[num_bit] & (1 << position)) >> position; // возвращаем значение искомого бита
}

//-----------Изменение бита-----------//
void s21_set_bit(s21_decimal *value, int index, int bit) {
  int num_bit = index / 32;
  int position = index % 32;
  if (bit)
    value->bits[num_bit] |= (1 << position); // меняем интересующий бит на 1
  else
    value->bits[num_bit] &= ~(1 << position); // меняем на 0
}

//-----------Получение знака decimal-----------//
int s21_get_sign(s21_decimal *value){
  int check_sign = s21_get_bit(value, 127);
  return check_sign;
}

//-----------Изменение знака decimal-----------//
void s21_set_sign(s21_decimal *value, int bit){
  s21_set_bit(value, 127, bit);
}

//-----------Получение степени decimal-----------//
int s21_get_pow(s21_decimal *value){
  int pow;
  if(s21_get_sign(value)){
    pow = (value->bits[3] ^ MASK_MINUS) >> 16;
  }else{
    pow = value->bits[3] >> 16;
  }
  return pow;
}

//-----------Разница степеней decimal-----------//
int s21_difference_pow(s21_decimal *value1, s21_decimal *value2){
  
  //if return 0 ? степени одинаковые 
  //if return > 0 ? степень value1 больше, чем value2 в return раз
  //if return < 0 ? степень value1 меньше, чем value2 в return раз

  return (s21_get_pow(value1)) - (s21_get_pow(value2));
}

//-----------Увеличение степени в n раз-----------//
void s21_levelup_pow(s21_decimal *value, int difference_number){

  //Заполнение массива под степень
  int pow_mas[8] = {0};
  int count_pow = 112; //Позиция степени

  for(int i = 0; i < 8; i++){ 
    pow_mas[i] = s21_get_bit(value, count_pow);
    count_pow++;  
  }

  //Перевод разницы в двоичную систему счисления
  int deff_mas[8] = {0};
  int i = 0;
  int flag = 0;
  
  do{
    deff_mas[i] = difference_number % 2;
    i++;
    difference_number /= 2;
    if(!difference_number){
      flag = 1;
    }
  }while(!flag);

  int result_pow[8] = {0};
  int buff = 0;

  for(int i = 0; i < 8; i++){
    if(pow_mas[i] == 0 && deff_mas[i] == 0 && !buff){
      result_pow[i] = 0;
    }else if(pow_mas[i] == 0 && deff_mas[i] == 0 && buff){
      result_pow[i] = 1;
      buff = 0;
    }else if(pow_mas[i] == 1 && deff_mas[i] == 0 && !buff){
      result_pow[i] = 1;
    }else if(pow_mas[i] == 0 && deff_mas[i] == 1 && !buff){
      result_pow[i] = 1;
    }else if(pow_mas[i] == 0 && deff_mas[i] == 1 && buff){
      result_pow[i] = 0;
      buff = 0;
    }else if(pow_mas[i] == 1 && deff_mas[i] == 0 && buff){
      result_pow[i] = 0;
      buff = 1;
    }else if(pow_mas[i] == 1 && deff_mas[i] == 1 && buff){
      result_pow[i] = 1;
      buff = 1;
    }else if(pow_mas[i] == 1 && deff_mas[i] == 1 && !buff){
      result_pow[i] = 0;
      buff = 1;
    }
  }

  //Изменение старой степени на новую
  count_pow = 112; //Позиция степени

  for(int i = 0; i < 8; i++){ 
    s21_set_bit(value, count_pow, result_pow[i]);
    count_pow++;  
  }
}

