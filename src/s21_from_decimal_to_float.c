#include <math.h>
#include "s21_decimal.h"
//Из decimal в float

// int s21_from_decimal_to_float(s21_decimal src, float *dst) {
//   double tmp = 0;
//     for (int i = 0; i <= 95; i++) {
//         tmp = tmp + s21_get_bit(&src, i) * pow(2, i);
//         }
//         tmp = tmp / pow(10, s21_get_pow(&src));
//         if (s21_get_sign(&src)) {
//         tmp = tmp * (-1);
//     }
//     if ((fabs(tmp) < 1e-28) && (fabs(tmp) > 0)) {
//       return 1;
//     }
//     *dst = (float)tmp;
//     return 0;
// }

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  double temp = 0.0;
  char temp_s[100] = {0};
  float temp_f = 0.0;
    for (int i = 0; i <= 95; i++) {
        temp += s21_get_bit(&src, i) * pow(2, i);
          sprintf(temp_s, "%+e", temp);
          sscanf(temp_s, "%e", &temp_f);
    } 
    *dst = temp_f / pow(10, s21_get_pow(&src));
    if (s21_get_sign(&src)) {
        *dst *= (-1);
    }
    if ((fabs(temp) < 1e-28) && (fabs(temp) > 0)) {
      return 1;
    }
    return 0;

}


// int s21_from_decimal_to_float(s21_decimal src, float *dst) {
//   double temp = 0.0;
//   char temp_s[100] = {0};
//   float temp_f = 0.0;
//     for (int i = 0; i <= 95; i++) {
//         temp += s21_get_bit(&src, i) * pow(2, i);
//           sprintf(temp_s, "%+e", temp);
//           sscanf(temp_s, "%e", &temp_f);
//     } 
//     if (s21_get_sign(&src)) {
//         temp = temp * (-1);
//     }
//     *dst = temp_f / pow(10, s21_get_pow(&src));
//     if ((fabs(temp) < 1e-28) && (fabs(temp) > 0)) {
//       return 1;
//     }
    
   
    
//     return 0;
// }