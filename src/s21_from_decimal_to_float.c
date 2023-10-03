#include <math.h>
#include "s21_decimal.h"
//Из decimal в float

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  double tmp = 0;
    for (int i = 0; i <= 95; i++) {
        tmp = tmp + s21_get_bit(&src, i) * pow(2, i);
        }
        tmp = tmp / pow(10, s21_get_pow(&src));
        if (s21_get_sign(&src)) {
        tmp = tmp * (-1);
    }
    if ((fabs(tmp) < 1e-28) && (fabs(tmp) > 0)) {
      return 1;
    }
    *dst = (float)tmp;
    return 0;
}
