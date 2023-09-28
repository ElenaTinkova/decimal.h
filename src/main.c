#include <stdio.h>
#include "s21_decimal.h"

int main(){

    //--------------- Fun + ---------------//
    
    // s21_decimal dec = {4294967295,0,0,0};
    // s21_decimal dec2 = {4294967295,0,0,0};
    // s21_decimal res = {0,0,0,0};

    // int ok = s21_add(dec, dec2, &res);

    // printf("\n***** DECIMAL 1 *****\n\n");
    // s21_print_decimal(&dec);

    // printf("\n***** DECIMAL 2 *****\n\n");
    // s21_print_decimal(&dec2);

    // printf("\n***** RESULT *****\n\n"); 
    // s21_print_decimal(&res);

    
    //--------------- Fun - ---------------//
    
    s21_decimal dec = {3,0,0,0b10000000000000000000000000000000};
    s21_decimal dec2 = {1,0,0,0b00000000000000000000000000000000};
    s21_decimal res = {0,0,0,0};

    int ok = s21_sub(dec, dec2, &res);

    printf("\n***** DECIMAL 1 *****\n\n");
    s21_print_decimal(&dec);

    printf("\n***** DECIMAL 2 *****\n\n");
    s21_print_decimal(&dec2);

    printf("\n***** RESULT *****\n\n"); 
    s21_print_decimal(&res);

    //--------------- Fun * ---------------//
    
    // s21_decimal dec = {6,0,0,0b00000000000000011000000000000000};
    // s21_decimal dec2 = {2,0,0,0};
    // s21_decimal res = {0,0,0,0};

    
    // int ok = s21_add(dec, dec2, &res);

    // printf("\n***** DECIMAL 1 *****\n\n");
    // s21_print_decimal(&dec);

    // printf("\n***** DECIMAL 2 *****\n\n");
    // s21_print_decimal(&dec2);

    // printf("\n***** RESULT *****\n\n"); 
    // s21_print_decimal(&res);

    //--------------- Fun Truncate* ---------------//

    // s21_decimal dec = {360,0,0,0b00000000000000100000000000000000};
    // s21_decimal res = {0,0,0,0};

    // printf("\n***** DECIMAL 1 *****\n\n");
    // s21_print_decimal(&dec);

    // s21_truncate(dec, &res);

    // printf("\n***** RESULT *****\n\n"); 
    // s21_print_decimal(&res);
    

    //--------------- Fun Floor* ---------------//
    // s21_decimal dec = {360,0,0,0b10000000000000100000000000000000};
    // s21_decimal res = {0,0,0,0};

    // printf("\n***** DECIMAL 1 *****\n\n");
    // s21_print_decimal(&dec);

    // s21_floor(dec, &res);

    // printf("\n***** RESULT *****\n\n"); 
    // s21_print_decimal(&res);


    return 0;
}