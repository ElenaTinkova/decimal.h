#include <math.h>
#include "s21_decimal.h"
//Из decimal в float

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
    for (int i = 0; i <= 95; i++) {
        *dst = *dst + s21_get_bit(&src, i) * pow(2, i);
        }
        *dst = *dst / pow(10, s21_get_pow(&src));
        if (s21_get_sign(&src)) {
        *dst = *dst * (-1);
    }
    if ((fabs(*dst) < 1e-28) && (fabs(*dst) > 0)) {
      return 1;
    }
    return 0;
}