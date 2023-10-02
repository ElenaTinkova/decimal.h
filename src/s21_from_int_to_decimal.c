#include "s21_decimal.h"
//Из int в decimal

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  if ((src > -2147483647) && (src < 2147483647)) {
    if (src < 0) {
      src = src * -1;
      s21_set_sign(dst, 1);
    }
    dst->bits[0] = src;
    return 0;  // OK
  } else {
    return 1;  // 1 - ошибка конвертации
  }
}