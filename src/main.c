#include <stdio.h>
#include "s21_decimal.h"

int main(){    
    s21_decimal dec1 = {{56, 0, 0, 0xffffffff}}; //0b00000000000000010000000000000000
    s21_decimal dec2 = {{21, 0, 0, 0b00000000000000110000000000000000}};
    s21_decimal res = {{0, 0, 0, 0}};    
    
    printf("\n***** DECIMAL 1 *****\n\n");
    s21_print_decimal(&dec1);

    printf("\n***** DECIMAL 2 *****\n\n");
    s21_print_decimal(&dec2);

    //int error = s21_div(dec, dec2, &res);

    int error = s21_sub(dec1, dec2, &res);

    printf("\n***** RESULT *****\n"); 
    s21_print_decimal(&res); 

    printf("\nResult error:\n");
    printf("%d\n", error); 

    return 0;
}