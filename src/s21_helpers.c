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