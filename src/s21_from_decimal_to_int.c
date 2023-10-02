#include <math.h>

#include "s21_decimal.h"

//Из decimal в int

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int error = 0;
  int sign = s21_get_bit(&src, 127);
  int sign1 = s21_get_bit(&src, 31);
  int scale = s21_get_pow(&src);
  double rez = src.bits[0] / pow(10, scale);
  if (src.bits[0] <= 2147483647) {
    *dst = src.bits[0];
    if (sign || sign1) {
      *dst *= -1;
    }
  } else
    error = 1;
  if (src.bits[1] || src.bits[2]) {
    error = 1;
  }
  if ((scale) > 0) {
    *dst = trunc(rez);
  }
  return error;
  return 0;
}
