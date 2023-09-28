#include "s21_decimal.h"
#include <stdio.h>

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
    int error = 0;
    s21_big_decimal value1 = s21_enlarge_D(value_1);
    s21_big_decimal value2 = s21_enlarge_D(value_2);
    s21_big_decimal result1 = s21_enlarge_D(*result);

    s21_big_div(value1, value2, &result1);
    
    int check = s21_overflow(&result1);
    if(!check){
        *result = s21_cut_D(result1);
    }
    error = check; //Присвоение вывод overflow к error переменной

    return error;
}