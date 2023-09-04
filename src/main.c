#include <stdio.h>
#include "s21_decimal.h"

int main(){
    // s21_decimal dec = {4294967295,,0,0};
    s21_big_decimal dec = {4294967295,1,0,0,0,0,0,0};
    
    s21_set_sign(&dec, 1);
    s21_set_bit(&dec, 247,1);
    s21_set_bit(&dec, 246,1);
    s21_set_bit(&dec, 245,0);
    s21_set_bit(&dec, 244,1);
    s21_set_bit(&dec, 243,1);
    s21_set_bit(&dec, 242,0);
    s21_set_bit(&dec, 241,1);
    s21_set_bit(&dec, 240,1);


    printf("\nView Decimal:\n");
    printf("Pow dec - %d\n\n", s21_get_pow(&dec));
    s21_print_decimal(&dec);

    s21_levelup_pow(&dec, 2);
    // s21_mul_ten(&dec, 5);

    // while(n != 0){}

    printf("\n\nView Decimal:\n");
    printf("Pow dec - %d\n\n", s21_get_pow(&dec));
    s21_print_decimal(&dec);

    return 0;
}