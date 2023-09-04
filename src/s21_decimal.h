#ifndef S21_DECIMAL_H_
#define S21_DECIMAL_H_

#define MASK_MINUS 0x80000000 // 0b10000000000000000000000000000000
#define MASK_SCALE 0x00ff0000 // 0b00000000111111110000000000000000
//4294967295
#define MAX_UN_INT 0xffffffff // 0b11111111111111111111111111111111

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

void s21_print_decimal(s21_big_decimal *value);
int s21_get_bit(s21_big_decimal *value, int index);
void s21_set_bit(s21_big_decimal *value, int index, int bit);
int s21_get_sign(s21_big_decimal *value);
void s21_set_sign(s21_big_decimal *value, int bit);
int s21_get_pow(s21_big_decimal *value);
void s21_levelup_pow(s21_big_decimal *value, int difference_number);

void s21_mul_ten(s21_big_decimal value1, s21_big_decimal value2, s21_big_decimal *result);
void s21_add_function(s21_big_decimal value1, s21_big_decimal value2, s21_big_decimal *result);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal, s21_decimal);
int s21_is_less_or_equal(s21_decimal, s21_decimal);
int s21_is_greater(s21_decimal, s21_decimal);
int s21_is_greater_or_equal(s21_decimal, s21_decimal);
int s21_is_equal(s21_decimal, s21_decimal);
int s21_is_not_equal(s21_decimal, s21_decimal);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

#endif
