#include <stdio.h>
#include "s21_decimal.h"

int main(){

    s21_decimal dec = {0,0,0,0};
    s21_set_bit(&dec, 1, 1);
    s21_set_sign(&dec, 1);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 32; j++) {
            if (dec.bits[i] > 0) {
                printf("%d", ((dec.bits[i]) >> j) &1);
            }else
                printf("%d", ((dec.bits[i]) >> j) &1);
        }
        printf("\n");
    }

    return 0;
}