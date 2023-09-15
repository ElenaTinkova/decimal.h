#include <stdio.h>
#include "s21_decimal.h"

int main(){
    s21_big_decimal dec = {3,0,0,0,0,0,0,0};
    s21_big_decimal dec2 = {5,0,0,0,0,0,0,0};
    s21_big_decimal res = {0,0,0,0,0,0,0,0};

    // s21_set_pow(&dec, 2);
    // s21_set_pow(&dec2, 1);

    s21_set_sign(&dec, 1);
    s21_set_sign(&dec2, 1);
    
    printf("\n***** DECIMAL 1 *****\n\n");
    s21_print_decimal(&dec);

    printf("\n***** DECIMAL 2 *****\n\n");
    s21_print_decimal(&dec2);

    //5 + 3 ok
    //3 + 5 ok
    //-5 + 3 fail
    //-3 + 5 ok
    //5 + -3 ok
    //3 + -5 fail
    //-5 + -3 ok
    //-3 + -5 ok

    int ok = s21_add(dec, dec2, &res);
    // printf("\n");
    // s21_print_decimal(&dec2); 


    printf("\n***** RESULT *****\n\n");
    s21_print_decimal(&res); 

    return 0;
}