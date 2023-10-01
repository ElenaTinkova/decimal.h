#include "s21_decimal.h"
#include <stdio.h>

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0; //Код ошибки
  s21_big_decimal value1 = s21_enlarge_D(value_1);
  s21_big_decimal value2 = s21_enlarge_D(value_2);
  s21_big_decimal result1 = s21_enlarge_D(*result);

  // Проверка степени перед операцией сложения
  s21_normalization_with_result(&value1, &value2, &result1);

  int sign1 = s21_get_big_sign(&value1);
  int sign2 = s21_get_big_sign(&value2);

  if ((!sign1 && !sign2) || (sign1 && sign2)) { //если оба знака +
    s21_mul_big(value1, value2, &result1);
  } else if (sign1 || sign2) { // если первый или второй знак -
    s21_set_big_sign(&value1, 0);
    s21_set_big_sign(&value2, 0);
    s21_mul_big(value1, value2, &result1);
    s21_set_big_sign(&result1, 1);
  }

  //Проверка на переполнение мантиссы
  int check = s21_overflow(&result1);
  if(!check){
    *result = s21_cut_D(result1);
  }
  error = check; //Присвоение вывод overflow к error переменной

  return error;
}