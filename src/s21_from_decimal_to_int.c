#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
    int error = 0;
    int sign = get_bit_decimal(src, 127);
    int sign1 = get_bit_decimal(src, 31);
    int scale = get_scale(src);
    double rez = src.bits[0] / pow(10, scale);
    if (src.bits[0] <= 2147483647){
      *dst = src.bits[0];
      if (sign || sign1){
        *dst *= -1;
      }   
    } else error = 1;
    if (src.bits[1] || src.bits[2]){
        error = 1;
    }
    if((scale) > 0){
        *dst = trunc(rez);
    }
    return error;
    return 0;
}

