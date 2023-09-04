#include "s21_decimal.h"
#include <stdio.h>

//-----------Вывод decimal в консоль-----------//
void s21_print_decimal(s21_big_decimal *value){
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1; //Кол-во bits в структуре
  for(int i = size_decimal; i >= 0; i--){ //Цикл bits
    printf("bits[%d] ", i);
    for(int j = 31; j >= 0; j--){ //Цикл byte в bits
      if(value->bits[i] & (1 << j)){
        printf("1");
      }else{
        printf("0");
      }
    }
    printf("\n");
  }
}

//-----------Получение бита-----------//
int s21_get_bit(s21_big_decimal *value, int index) {
  int num_bit = index / 32; // определяем в каком bits структуры работаем
  int position = index % 32; // определяем позицию бита, который хотим проверить 
  return (value->bits[num_bit] & (1 << position)) >> position; // возвращаем значение искомого бита
}

//-----------Изменение бита-----------//
void s21_set_bit(s21_big_decimal *value, int index, int bit) {
  int num_bit = index / 32;
  int position = index % 32;
  if (bit)
    value->bits[num_bit] |= (1 << position); // меняем интересующий бит на 1
  else
    value->bits[num_bit] &= ~(1 << position); // меняем на 0
}

//-----------Получение знака decimal-----------//
int s21_get_sign(s21_big_decimal *value){
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1; //Кол-во bits в структуре
  int check_sign = value->bits[size_decimal] >> 31;
  return check_sign;
}

//-----------Изменение знака decimal-----------//
void s21_set_sign(s21_big_decimal *value, int bit){
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1; //Кол-во bits в структуре
  // int check_sign = value->bits[size_decimal] >> 31;
  // s21_set_bit(value, 127, bit);
 if (bit){
  value->bits[size_decimal] |= MASK_MINUS;
 } else {
  value->bits[size_decimal] &= ~ MASK_MINUS;
 }

}

//-----------Получение степени decimal-----------//
int s21_get_pow(s21_big_decimal *value){
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;
  int pow;
  if(s21_get_sign(value)){
    pow = (value->bits[size_decimal] ^ MASK_MINUS) >> 16;
  }else{
    pow = value->bits[size_decimal] >> 16;
  }
  return pow;
}

//-----------Разница степеней decimal-----------//
int s21_difference_pow(s21_big_decimal *value1, s21_big_decimal *value2){
  
  //if return 0 ? степени одинаковые 
  //if return > 0 ? степень value1 больше, чем value2 в return раз
  //if return < 0 ? степень value1 меньше, чем value2 в return раз

  return (s21_get_pow(value1)) - (s21_get_pow(value2));
}


//-----------Увеличение степени на n раз-----------//
void s21_levelup_pow(s21_big_decimal *value, int difference_number){
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;
  int value_pow;
  //Заполнение массива под степень
  if(s21_get_sign(value)){
    value_pow = (value->bits[size_decimal] ^ MASK_MINUS) >> 16;
    value_pow += difference_number;
    value->bits[size_decimal] = value_pow << 16;
    s21_set_sign(value, 1);
  }else{
   value_pow = value->bits[size_decimal] >> 16;
   value_pow += difference_number;
   value->bits[size_decimal] = value_pow << 16;
  }
   
 // for(int i = 0; i < 8; i++){
  //   if(pow_mas[i] == 0 && deff_mas[i] == 0 && !buff){
  //     result_pow[i] = 0;
  //   }else if(pow_mas[i] == 0 && deff_mas[i] == 0 && buff){
  //     result_pow[i] = 1;
  //     buff = 0;
  //   }else if(pow_mas[i] == 1 && deff_mas[i] == 0 && !buff){
  //     result_pow[i] = 1;
  //   }else if(pow_mas[i] == 0 && deff_mas[i] == 1 && !buff){
  //     result_pow[i] = 1;
  //   }else if(pow_mas[i] == 0 && deff_mas[i] == 1 && buff){
  //     result_pow[i] = 0;
  //     buff = 0;
  //   }else if(pow_mas[i] == 1 && deff_mas[i] == 0 && buff){
  //     result_pow[i] = 0;
  //     buff = 1;
  //   }else if(pow_mas[i] == 1 && deff_mas[i] == 1 && buff){
  //     result_pow[i] = 1;
  //     buff = 1;
  //   }else if(pow_mas[i] == 1 && deff_mas[i] == 1 && !buff){
  //     result_pow[i] = 0;
  //     buff = 1;
  //   }
  // }

}

void s21_mul_ten(s21_big_decimal *value, int difference_number){
  int value_mant = value->bits[0];
  int result = 0;
  while(difference_number !=0){
    if (result != 0) result = 0;
    for(int i = 0; i < 10; i++){
    result += value_mant;
    }
    value_mant = result;
    difference_number--;
  }
  printf("\n%d\n", result);
  value->bits[0] = result;
}

