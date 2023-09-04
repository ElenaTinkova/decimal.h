#include <stdio.h>
#include "s21_decimal.h"

int main(){
    // s21_decimal dec = {4294967295,,0,0};
    s21_big_decimal dec = {4294967294,0,0,0,0,0,0,0};
    s21_big_decimal dec2 = {3,0,0,0,0,0,0,0};
    s21_big_decimal res = {0,0,0,0,0,0,0,0};
    // s21_add_function(dec, dec2, &res);
    
    s21_print_decimal(&dec);
    printf("\n");
    s21_print_decimal(&dec2);
    printf("\n");

    s21_mul_ten(dec, dec2, &res );
    s21_print_decimal(&res);

    return 0;
}