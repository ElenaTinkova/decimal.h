#include <stdio.h>
#include "s21_decimal.h"

int main(){

  s21_decimal value_1 = {{0xffffffff, 0xffffffff, 0xffffffff, 0}};
  s21_decimal value_2 = {{0x32, 0, 0, 0x20000}};
  s21_decimal result = {0};
  s21_add(value_1, value_2, &result);
    return 0;
}