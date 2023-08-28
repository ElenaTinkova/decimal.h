#include "s21_decimal.h"
#include <stdio.h>

// Это вспомогательная функция, с помощью которой можно вывести все элементы структуры
// и проверить работу маленьких функций

int main(){
    s21_decimal dec = {0, 0, 0, 0};
    s21_set_bit(&dec, 120, 1);
    printf("sign %d\n", s21_get_sign(&dec));
    for (int k = 0; k < 4; k++){
        for (int d = 0; d < 32; d++) {
            printf("%d", ((dec.bits[k] >> d) & 1));
        }
        printf("\n");
    }
    s21_set_sign(&dec, 1);
    printf("\n");
    for (int k = 0; k < 4; k++){
        for (int d = 0; d < 32; d++) {
            printf("%d", ((dec.bits[k] >> d) & 1));
        }
        printf("\n");
    }
    return 0;
}
// int s = 0b00000000000000000000000000000001;
// int x = 0b10000000000000000010000000000000;
// int w = 0b10000000000000000000000000000000;
// int a = 0b00000000000000000000000000000000;
// int z = 0b10000000000000000000000000000000;
