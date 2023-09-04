#include <stdio.h>
#include "s21_decimal.h"

int main(){
    s21_decimal dec = {4513,0,0,0};

    printf("View Decimal:\n");
    s21_print_decimal(&dec);


    return 0;
}