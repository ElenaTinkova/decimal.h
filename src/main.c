#include <stdio.h>
#include "s21_decimal.h"

int main(){  // -15 : (-3) = 5

  s21_decimal value_1 = {{15, 0, 0, 0b00000000000000000000000000000000}};
  s21_decimal value_2 = {{3, 0, 0, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
    s21_div(value_1, value_2, &result);
    s21_print_decimal(&result);

    return 0;
}