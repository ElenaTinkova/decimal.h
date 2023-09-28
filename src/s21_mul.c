#include "s21_decimal.h"
#include <stdio.h>

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0; //Код ошибки
  s21_big_decimal value1 = s21_enlarge_D(value_1);
  s21_big_decimal value2 = s21_enlarge_D(value_2);
  s21_big_decimal result1 = s21_enlarge_D(*result);


  // Проверка степени перед операцией сложения
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1; //bits где лежит степень
  int dif = s21_difference_pow(&value1, &value2);  // dif > 0 = value_1 > value_2; dif < 0 = value_2 > value_1;
  if (dif != 0) {
    while (dif != 0) {
      if(s21_get_pow(&value1) <= 28 || s21_get_pow(&value2) <= 28){
        s21_big_decimal ten = {10, 0, 0, 0, 0, 0, 0, 0};
        if (dif > 0) { 
          s21_levelup_pow(&value2, 1);
          s21_mul_ten(value2, ten, &value2);
          dif--;
        }else if(dif < 0){
          s21_levelup_pow(&value1, 1);
          s21_mul_ten(value1, ten, &value1);
          dif++;
        }
      }
    }
    result1.bits[size_decimal] = value1.bits[size_decimal];
  }

  int sign1 = s21_get_sign(&value1);
  int sign2 = s21_get_sign(&value2);

  if ((!sign1 && !sign2) || (sign1 && sign2)) { //если оба знака +
    s21_mul_ten(value1,value2,&result1);
  } else if (sign1 || sign2) { // если первый или второй знак -
    s21_set_sign(&value1, 0);
    s21_set_sign(&value2, 0);
    s21_mul_ten(value1,value2,&result1);
    s21_set_sign(&result1, 1);
  }
  
  //Проверка на переполнение мантиссы
  int check = s21_overflow(&result1);
  if(!check){
    *result = s21_cut_D(result1);
  }
  error = check; //Присвоение вывод overflow к error переменной

  return error;
}