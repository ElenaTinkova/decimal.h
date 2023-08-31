#include <stdio.h>
#include "s21_decimal.h"

int main(){
    s21_decimal dec = {0,0,0,0};
    s21_set_sign(&dec, 1);

    s21_set_bit(&dec, 112, 0);
    s21_set_bit(&dec, 113, 0);
    s21_set_bit(&dec, 114, 1);
    s21_set_bit(&dec, 115, 0);
    s21_set_bit(&dec, 116, 1);
    s21_set_bit(&dec, 117, 0);
    s21_set_bit(&dec, 118, 0);
    s21_set_bit(&dec, 119, 0);
    

    int res = s21_get_pow(&dec);
    printf("\nView Decimal Memory: \n\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 32; j++) {
            printf("%d", ((dec.bits[i]) >> j) &1);
        }
        printf("\n");
    }
    printf("\nPow Decimal - %d\n", res);

    s21_levelup_pow(&dec, 8);

    res = s21_get_pow(&dec);

    printf("\nView Decimal Memory after edited: \n\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 32; j++) {
            printf("%d", ((dec.bits[i]) >> j) &1);
        }
        printf("\n");
    }
    printf("\nPow Decimal - %d\n\n", res);

    return 0;
}