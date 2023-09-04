#ifndef DEC_STARTER_H_
#define DEC_STARTER_H_

#include <stdio.h>

#define MASK_MINUS 0b10000000000000000000000000000000
#define MASK_MAX_SCALE

typedef struct 
{
    unsigned int bits[4];
} s21_decimal;

typedef struct 
{
    unsigned int B_bits[8];
} s21_big_decimal;

s21_big_decimal s21_enlarge_D(s21_decimal number);

void s21_set_bit(int *voobsheto_eto_bit, int index, int val);
void s21_set_bit_to_big_D(s21_big_decimal number, int index, int val);
int s21_get_bit(int voobsheto_eto_bit, int index); 
int s21_get_bit_from_big_D(s21_big_decimal number, int index);
int s21_get_sign(s21_decimal number);
int s21_get_sign_BD(s21_big_decimal number);
void s21_change_sign(s21_decimal number);
void s21_change_sign_BD(s21_big_decimal number);

// int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
// int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// int s21_is_less(s21_decimal, s21_decimal);
// int s21_is_less_or_equal(s21_decimal, s21_decimal);
// int s21_is_greater(s21_decimal, s21_decimal);
// int s21_is_greater_or_equal(s21_decimal, s21_decimal);
// int s21_is_equal(s21_decimal, s21_decimal);
// int s21_is_not_equal(s21_decimal, s21_decimal);

// int s21_from_int_to_decimal(int src, s21_decimal *dst);
// int s21_from_float_to_decimal(float src, s21_decimal *dst);
// int s21_from_decimal_to_int(s21_decimal src, int *dst);
// int s21_from_decimal_to_float(s21_decimal src, float *dst);

// int s21_floor(s21_decimal value, s21_decimal *result);
// int s21_round(s21_decimal value, s21_decimal *result);
// int s21_truncate(s21_decimal value, s21_decimal *result);
// int s21_negate(s21_decimal value, s21_decimal *result);

#endif
