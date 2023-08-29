#include <stdio.h>
#include "s21_decimal.h"

int main(){
    s21_decimal dec = {0,0,0,0};
    s21_set_sign(&dec, 1);

    s21_set_bit(&dec, 112, 1);
    s21_set_bit(&dec, 113, 1);
    s21_set_bit(&dec, 114, 1);
    s21_set_bit(&dec, 115, 1);

    int res = s21_get_pow(&dec);
    printf("\n%d\n", res);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 32; j++) {
            printf("%d", ((dec.bits[i]) >> j) &1);
        }
        printf("\n");
    }
    return 0;
}