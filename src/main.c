#include <stdio.h>
#include "s21_decimal.h"

int main(){
    
    s21_decimal dec = {{30, 0, 0, 0b10000000000000100000000000000000}}; //0b10000000000000000000000000000000
    s21_decimal dec2 = {{6, 0, 0, 0b10000000000001100000000000000000}}; // 0b10000000000001100000000000000000
    s21_decimal res = {{0, 0, 0, 0}};

    printf("\n***** DECIMAL 1 *****\n\n");
    s21_print_decimal(&dec);

    printf("\n***** DECIMAL 2 *****\n\n");
    s21_print_decimal(&dec2);

    int ok = s21_div(dec, dec2, &res);

    printf("\n***** RESULT *****\n"); 
    s21_print_decimal(&res); 
    
    printf("\nResult error:\n");
    printf("%d\n", ok); 

    return 0;
}