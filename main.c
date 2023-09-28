#include <stdio.h>
#include "s21_decimal.h"

int main(){
    s21_decimal dec = {{5,0,0,0}};
    s21_decimal dec2 = {{5,0,0,0}};
    s21_decimal res = {{0,0,0,0,}};
    
    s21_sub(dec, dec2, &res);

    printf("\n***** DECIMAL 1 *****\n\n");
    s21_print_decimal(&dec);

    printf("\n***** DECIMAL 2 *****\n\n");
    s21_print_decimal(&dec2);

    printf("\n***** RESULT *****\n\n"); 
    s21_print_decimal(&res); 

    return 0;
}