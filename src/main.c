#include <stdio.h>
#include "s21_decimal.h"

int main(){
    s21_decimal dec = {{33,0,0,0b10000000000000010000000000000000}}; //0b10000000000000000000000000000000
    s21_decimal dec2 = {{0,0,0,0}};
    s21_decimal res = {{0,0,0,0,}};    

    s21_sub(dec, dec2, &res);

    printf("\n***** DECIMAL 1 *****\n\n");
    s21_print_decimal(&dec);

    printf("\n***** DECIMAL 2 *****\n\n");
    s21_print_decimal(&dec2);

    s21_floor(dec, &res);

    printf("\n***** RESULT *****\n\n"); 
    s21_print_decimal(&res); 

    return 0;
}