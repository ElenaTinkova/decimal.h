#include <stdio.h>
#include "s21_decimal.h"

int main(){
    s21_big_decimal dec = {4294967295,0,0,0,0,0,0,0};
    s21_big_decimal dec2 = {0,4294967295,0,0,0,0,0,0};
    s21_big_decimal res = {0,0,0,0,0,0,0,0};
    
    printf("\n***** DECIMAL 1 *****\n\n");
    s21_print_decimal(&dec);

    printf("\n***** DECIMAL 2 *****\n\n");
    s21_print_decimal(&dec2);

    s21_mul_ten(dec, dec2, &res);
    // s21_add_function(dec, dec2, &res);

    printf("\n***** RESULT *****\n\n");
    s21_print_decimal(&res); 

    return 0;
}