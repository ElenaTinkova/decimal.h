#include "s21_decimal.h"
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

void writeExponent(s21_decimal *dst, int exponent) {
    // Учитываем знак экспоненты
    int sign = (exponent < 0) ? 1 : 0;
    exponent = (exponent < 0) ? -exponent : exponent;

    // Масштабируем s21_decimal на основе экспоненты
    for (int i = 0; i < exponent; i++) {
        if (sign) {
            // Деление на 10 для отрицательной экспоненты
            for (int j = 3; j >= 0; j--) {
                int64_t product = (int64_t)dst->bits[j] * 10;
                dst->bits[j] = (int32_t)(product & 0xFFFFFFFF);
                if (j > 0) {
                    dst->bits[j - 1] += (int32_t)(product >> 32);
                }
            }
        } else {
            // Умножение на 10 для положительной экспоненты
            int carry = 0;
            for (int j = 3; j >= 0; j--) {
                int64_t product = (int64_t)dst->bits[j] * 10 + carry;
                dst->bits[j] = (int32_t)(product & 0xFFFFFFFF);
                carry = (int32_t)(product >> 32);
            }
        }
    }
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    if (!dst)
        return 1;
    
    // Если число бесконечное, не числовое (NaN) или вне допустимого диапазона
    if (isinf(src) || isnan(src) || (fabsf(src) > 79228162514264337593543950335.0f) ||
       ((fabsf(src) > 0) && (fabsf(src) < 1e-28)))
        return 1;

    // Преобразование float в строку с экспонентой
    char str_float[64];
    sprintf(str_float, "%+e", src);

    // Извлечение мантиссы и экспоненты из строки
    int mantissa = str_float[1] - '0';
    for (int i = 0; i < 6; i++) {
        mantissa *= 10;
        mantissa += str_float[i + 3] - '0';
    }

    int exponent = 0;
    for (int i = 11; str_float[i] != '\0'; i++) {
        exponent *= 10;
        exponent += str_float[i] - '0';
    }
    if (str_float[10] == '-') {
        exponent *= -1;
    }
    exponent -= 6;

    // Преобразование мантиссы в s21_decimal
    s21_from_int_to_decimal(mantissa, dst);

    // Применение экспоненты к s21_decimal (масштабирование)
    if (exponent >= 0) {
        for (int i = 0; i < exponent; i++) {
            // Умножаем на 10 для положительной экспоненты
            s21_from_int_to_decimal(10, dst);
        }
    } else {
        for (int i = 0; i < -exponent; i++) {
            // Делим на 10 для отрицательной экспоненты
            writeExponent(dst, -exponent);
        }
    }

    return 0;
}

// int s21_from_float_to_decimal(float src, s21_decimal *dst) {
//     if (!dst) {
//         return -1; // Возвращаем ошибку, если указатель на dst равен NULL
//     }

//     // Проверяем, не выходит ли исходное число за пределы Decimal
//     if (isinf(src) || isnan(src) || (fabsf(src) > 79228162514264337593543950335.0f) ||
//       ((fabsf(src) > 0) && (fabsf(src) < 1e-28))) {
//         return 1; // Если выходит, возвращаем ошибку
//     }

//     // Разбиваем число на целую и дробную части
//     int integer_part = (int)src;
//     float fractional_part = src - integer_part;

//     // Определяем знак числа
//     int sign = (src >= 0) ? 0 : 1;

//     // Вычисляем коэффициент масштабирования
//     int scale_factor = 0;
//     while (fractional_part != (int)fractional_part) {
//         fractional_part *= 10;
//         scale_factor++;
//     }

//     // Записываем целую часть в структуру Decimal
//     dst->bits[0] = integer_part;
//     dst->bits[1] = 0;
//     dst->bits[2] = 0;
//     dst->bits[3] = (scale_factor << 16) | (sign << 31);

//     // Записываем дробную часть в структуру Decimal
//     int i;
//     for (i = 0; i < 28; i++) {
//         fractional_part *= 10;
//         dst->bits[i / 9] += ((int)fractional_part % 10) << (i % 9 * 4 + 8);
//     }

//     return 0; // Возвращаем успешное выполнение функции
// }

// int s21_from_float_to_decimal(float src, s21_decimal *dst) {
//     int is_error = 0; // 0 - нет ошибки, 1 - есть

//     if (!dst) {
//         is_error = 1;
//         return is_error;
//     }

//     // Если число бесконечное или не числовое (NaN)
//     if (isinf(src) || isnan(src)) {
//         is_error = 1;
//         return is_error;
//     }

//     // Если число слишком большое или слишком маленькое
//     if (fabsf(src) > 79228162514264337593543950335.0f || 
//        ((fabsf(src) > 0) && (fabsf(src) < 1e-28))) {
//         is_error = 1;
//         return is_error;
//     }

//     // Разбиваем float на знак, целую часть и дробную часть
//     int sign = (src < 0) ? 1 : 0;
//     float abs_value = (src < 0) ? -src : src;
//     int int_part = (int)abs_value;
//     float frac_part = abs_value - (float)int_part;

//     // Определение показателя степени (коэффициента масштабирования)
//     int exponent = 0;
//     while (frac_part != 0.0f && exponent < 28) {
//         frac_part *= 10.0f;
//         exponent++;
//     }

//     // Заполнение bits[0], bits[1], bits[2] с учетом целой части
//     dst->bits[0] = int_part;
//     dst->bits[1] = int_part >> 32;
//     dst->bits[2] = int_part >> 64;

//     // Заполнение показателя степени и знака в bits[3]
//     dst->bits[3] = (sign << 31) | (exponent << 16);

//     return is_error;
// }

int main(void) {
  float src1 = 12345678.12345678;
  s21_decimal dst1;
  s21_from_float_to_decimal(src1, &dst1);
  printf("src1: %f\n", src1);
  s21_print_decimal(&dst1);

  return 0;
}