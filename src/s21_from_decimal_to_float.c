#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    float rez = 0;
    for (int i = 0; i <= 95; i++) {
        rez = rez + get_bit_decimal (src, i) * pow(2, i);
        }
        rez = rez / pow(10, get_scale(src));
        if (sign_decimal(src)) {
        rez = rez * (-1);
    }
    if ((fabs(*dst) < 1e-28) && (fabs(*dst) > 0)) {
    return 1;
    }
    *dst = rez;
    printf("float - %f", *dst);
    
  return 0;
}