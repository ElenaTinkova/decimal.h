#include <stdio.h>
#include "s21_decimal.h"

int main(){

    s21_decimal value_1 = {{12, 0, 0, 0b0000000000000000000000000000000}};
    s21_set_pow(&value_1, 2);

    s21_decimal value_2 = {{123, 0, 0, 0b00000000000000000000000000000000}};
    
    s21_decimal result = {0};
    s21_mul(value_1, value_2, &result);
    return 0;
}