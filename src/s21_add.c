#include "s21_decimal.h"
#include <stdio.h>

int s21_add(s21_big_decimal value_1, s21_big_decimal value_2, s21_big_decimal *result) {
  
  // Проверка степени перед операцией сложения
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1; //bits где лежит степень
  
  int dif = s21_difference_pow(&value_1, &value_2);  // dif > 0 = value_1 > value_2; dif < 0 = value_2 > value_1;
  if (dif != 0) {
    while (dif != 0) {
      s21_big_decimal ten = {10, 0, 0, 0, 0, 0, 0, 0};
      if (dif > 0) { 
        s21_levelup_pow(&value_2, 1); //увеличение степени на 1 второго децимал
        s21_mul_ten(value_2, ten, &value_2); //умножение мантиссы на 10
        dif--;
       }else if(dif < 0){
         s21_levelup_pow(&value_1, 1); //увеличение степени на 1 первого децимал
         s21_mul_ten(value_1, ten, &value_1);
         dif++;
       }
    }
    result->bits[size_decimal] = value_1.bits[size_decimal]; //запись общей степени в результат
  }

  int sign1 = s21_get_sign(&value_1);
  int sign2 = s21_get_sign(&value_2);

  if (!sign1 && !sign2) { //если оба знака +
    s21_add_function(value_1, value_2, result);
  } else if (sign1 && !sign2) { // если первый знак -
    s21_set_sign(&value_1, 0);
    int vvs = s21_is_greater(value_1, value_2); //первое значение больше второго?
    if(vvs){
      s21_sub_function(value_1, value_2, result);
      s21_set_sign(result, 1);
    }else{
      s21_sub_function(value_2, value_1, result);
    }
  } else if (!sign1 && sign2) { // если второй знак -
    s21_set_sign(&value_2, 0);
    int vvs = s21_is_greater(value_1, value_2);
    if(vvs){
      s21_sub_function(value_1, value_2, result);
    }else{
      s21_sub_function(value_2, value_1, result);
      s21_set_sign(result, 1);
    }
  } else if (sign1 && sign2) { // если оба отрицательные
    s21_set_sign(&value_2, 0);
    s21_set_sign(&value_1, 0);
    s21_add_function(value_2, value_1, result);
    s21_set_sign(result, 1);
  }

  return 1;
}