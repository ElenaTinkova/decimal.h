#include "s21_decimal.h"
#include <stdio.h>

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_big_decimal value1 = s21_enlarge_D(value_1);
  s21_big_decimal value2 = s21_enlarge_D(value_2);
  s21_big_decimal result1 = s21_enlarge_D(*result);
  // Проверка степени перед операцией сложения
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1; //bits где лежит степень
  
  int dif = s21_difference_pow(&value1, &value2);  // dif > 0 = value_1 > value_2; dif < 0 = value_2 > value_1;
  if (dif != 0) {
    while (dif != 0) {
      s21_big_decimal ten = {10, 0, 0, 0, 0, 0, 0, 0};
      if (dif > 0) { 
        s21_levelup_pow(&value2, 1); //увеличение степени на 1 второго децимал
        s21_mul_ten(value2, ten, &value2); //умножение мантиссы на 10
        dif--;
       }else if(dif < 0){
         s21_levelup_pow(&value1, 1); //увеличение степени на 1 первого децимал
         s21_mul_ten(value1, ten, &value1);
         dif++;
       }
    }
    result1.bits[size_decimal] = value1.bits[size_decimal]; //запись общей степени в результат
  }

  int sign1 = s21_get_sign(&value1);
  int sign2 = s21_get_sign(&value2);

  if (!sign1 && !sign2) { //если оба знака +
    s21_add_function(value1, value2, &result1);
  } else if (sign1 && !sign2) { // если первый знак -
    s21_set_sign(&value1, 0);
    int vvs = s21_is_greater(value1, value2); //первое значение больше второго?
    if(vvs){
      s21_sub_function(value1, value2, &result1);
      s21_set_sign(&result1, 1);
    }else{
      s21_sub_function(value2, value1, &result1);
    }
  } else if (!sign1 && sign2) { // если второй знак -
    s21_set_sign(&value2, 0);
    int vvs = s21_is_greater(value1, value2);
    if(vvs){
      s21_sub_function(value1, value2, &result1);
    }else{
      s21_sub_function(value2, value1, &result1);
      s21_set_sign(&result1, 1);
    }
  } else if (sign1 && sign2) { // если оба отрицательные
    s21_set_sign(&value2, 0);
    s21_set_sign(&value1, 0);
    s21_add_function(value2, value1, &result1);
    s21_set_sign(&result1, 1);
  }
  *result = s21_cut_D(result1);
  s21_print_decimal(result);
  return 1;
}