#include "s21_decimal.h"

int s21_get_bit(s21_decimal *value, int index) {
  int num_bit = index / 32; // определяем в каком bits структуры работаем
  int position = index % 32; // определяем позицию бита, который хотим проверить 
  return (value->bits[num_bit] & (1 << position)) >> position; // возвращаем значение искомого бита
}

void s21_set_bit(s21_decimal *value, int index, int bit) {
  int num_bit = index / 32;
  int position = index % 32;
  if (bit)
    value->bits[num_bit] |= (1 << position); // меняем интересующий бит на 1
  else
    value->bits[num_bit] &= ~(1 << position); // меняем на 0
}

int s21_get_sign(s21_decimal *value) {
  return (value->bits[3] & MASK_MINUS);
}

void s21_set_sign(s21_decimal *value, int sign) {
  if (sign)
    value->bits[3] |= MASK_MINUS;
  else
    value->bits[3] &= ~(MASK_MINUS);
}
