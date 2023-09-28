#ifndef S21_DECIMAL_H_
#define S21_DECIMAL_H_
#include <string.h>

#define MASK_MINUS 0x80000000 // 0b10000000000000000000000000000000
#define MASK_SCALE 0x00ff0000 // 0b00000000111111110000000000000000
//4294967295
#define MAX_UN_INT 0xffffffff // 0b11111111111111111111111111111111

#define MASK_MINUS 0x80000000 // 0b10000000000000000000000000000000
#define MASK_SCALE 0x00ff0000 // 0b00000000111111110000000000000000

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

void s21_print_decimal(s21_decimal *value);
void s21_print_big_decimal(s21_big_decimal *value);
int s21_get_bit(s21_big_decimal *value, int index);
void s21_set_bit(s21_big_decimal *value, int index, int bit);
int s21_get_sign(s21_big_decimal *value);
void s21_set_sign(s21_big_decimal *value, int bit);
void s21_set_small_sign(s21_decimal *value, int bit);
int s21_get_pow(s21_big_decimal *value);
void s21_levelup_pow(s21_big_decimal *value, int difference_number);
int s21_difference_pow(s21_big_decimal *value1, s21_big_decimal *value2);
void s21_set_pow(s21_big_decimal *value, int pow_value);
s21_big_decimal s21_enlarge_D(s21_decimal number);
s21_decimal s21_cut_D(s21_big_decimal number);
void s21_div_ten(s21_big_decimal *value);
int s21_overflow(s21_big_decimal *value);

void s21_mul_ten(s21_big_decimal value1, s21_big_decimal value2, s21_big_decimal *result);
void s21_add_function(s21_big_decimal value1, s21_big_decimal value2, s21_big_decimal *result);
void s21_sub_function(s21_big_decimal value1, s21_big_decimal value2, s21_big_decimal *result);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result); 
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result); 
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_big_decimal value_1, s21_big_decimal value_2); // переделать потом 
int s21_is_less_or_equal(s21_big_decimal value_1, s21_big_decimal value_2); // переделать потом 
int s21_is_greater(s21_big_decimal value_1, s21_big_decimal value_2); //переделать пототм
int s21_is_greater_or_equal(s21_big_decimal value_1, s21_big_decimal value_2); //переделать пототм
int s21_is_equal(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_is_not_equal(s21_big_decimal value_1, s21_big_decimal value_2);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

#endif
