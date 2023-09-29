#include <stdio.h>
#include "s21_decimal.h"

int main(){
    float a = 0;
    
    s21_decimal dec = {{333,0,0,0}}; //0b10000000000000000000000000000000
    s21_set_pow(&dec, 29); 

    int error;
    error = s21_from_decimal_to_float(dec, &a);

    // s21_decimal dec2 = {{0,0,0,0}};
    // s21_decimal res = {{0,0,0,0}};

    // s21_set_pow(&dec, 27);  
    // s21_set_pow(&dec2, 0);   
    // s21_set_sign(&dec, 0);  
    // s21_set_sign(&dec2, 0);  

    printf("\n***** DECIMAL 1 *****\n\n");
    s21_print_decimal(&dec);

    printf("\n%f\n", a);

    // printf("\n***** DECIMAL 2 *****\n\n");
    // s21_print_decimal(&dec2);

   

    // printf("\n***** RESULT *****\n"); 
    // s21_print_decimal(&res); 
    
    printf("\nResult error:\n");
    printf("%d\n", error); 

    return 0;
}