#include <stdio.h>

#include "s21_decimal.h"

int main() {  // -15 : (-3) = 5

  s21_decimal value_1 = {{0x5c71c2da, 0x1b9eabb9, 0xe5c5bb8, 0x1c0000}};
  s21_decimal value_2 = {{0xa, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{0xcc71c6af, 0xda81ad26, 0x21bf7123, 0x1b0000}};
  s21_add(value_1, value_2, &result);
  s21_print_decimal(&result);
  printf("\n");
  s21_print_decimal(&check);
  return 0;
}