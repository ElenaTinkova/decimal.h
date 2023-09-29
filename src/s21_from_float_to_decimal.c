#include "s21_decimal.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

void s21_print_decimal(s21_decimal *value) {
  int size_decimal = sizeof(s21_decimal) / 4 - 1;  //Кол-во bits в структуре
  int i;
  for (i = size_decimal; i >= 0; i--) {  //Цикл bits
    // printf("bits[%d] ", i);
    int j;
    for (j = 31; j >= 0; j--) {  //Цикл byte в bits
      if (value->bits[i] & (1 << j)) {
        printf("1");
      } else {
        printf("0");
      }
    }
    printf("\n");
  }
}

//-----------Получение бита-----------//
int s21_get_bit(s21_big_decimal *value, int index) {
  int num_bit = index / 32;  // определяем в каком bits структуры работаем
  int position =
      index % 32;  // определяем позицию бита, который хотим проверить
  return (value->bits[num_bit] & (1 << position)) >>
         position;  // возвращаем значение искомого бита
}

//-----------Получение знака decimal-----------//
int s21_get_sign(s21_big_decimal *value) {
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;  //Кол-во bits в структуре
  int check_sign = value->bits[size_decimal] >> 31;
  return check_sign;
}

//-----------Изменение бита-----------//
void s21_set_bit(s21_big_decimal *value, int index, int bit) {
  int num_bit = index / 32;
  int position = index % 32;
  if (bit)
    value->bits[num_bit] |= (1 << position);  // меняем интересующий бит на 1
  else
    value->bits[num_bit] &= ~(1 << position);  // меняем на 0
}

//-----------Изменение знака decimal-----------//
void s21_set_sign(s21_big_decimal *value, int bit) {
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;  //Кол-во bits в структуре
  if (bit) {
    value->bits[size_decimal] |= MASK_MINUS;
  } else {
    value->bits[size_decimal] &= ~MASK_MINUS;
  }
}

//-----------Занесение степени decimal-----------//
void s21_set_pow(s21_big_decimal *value, int pow_value) {
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;
  int pow;
  if (s21_get_sign(value)) {
    pow = (value->bits[size_decimal] ^ MASK_MINUS) >> 16;
    pow = pow_value;
    pow = pow_value << 16;
    s21_set_sign(value, 1);
  } else {
    pow = value->bits[size_decimal] >> 16;
    pow = pow_value;
    pow = pow_value << 16;
  }

  value->bits[size_decimal] = pow;
}

s21_big_decimal s21_enlarge_D(s21_decimal number) {
    s21_big_decimal res = {{number.bits[0], number.bits[1], number.bits[2], 0, 0, 0, 0, number.bits[3]}};
    return res;
}

s21_decimal s21_cut_D(s21_big_decimal number) {
    s21_decimal res = {{number.bits[0], number.bits[1], number.bits[2], number.bits[7]}};
    return res;
}

//====================== НОВЫЕ ФУНКЦИИ =======================

int s21_atoi(const char* str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (str[i] == '-')
        sign = -1;
    i++;

    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

int s21_get_exp_sign(const char* str) {
    const char* exp_char = strchr(str, 'E'); // позиция символа 'E' в строке
    int exponent;
    if (exp_char == NULL) {
        exponent = 0;
    } else {
      int exp_index = exp_char - str;
      const char* exp_str = &str[exp_index + 1]; // подстрока, содержащая степень числа
      exponent = s21_atoi(exp_str);
    }
    return exponent;
}

// Умножение s21_decimal на целое число
s21_decimal s21_decimal_multiply_int(s21_decimal decimal, int multiplier) {
    for (int i = 0; i < 3; i++) {
        decimal.bits[i] *= multiplier;
    }
    return decimal;
}

// Сложение s21_decimal с целым числом
s21_decimal s21_decimal_add_int(s21_decimal decimal, int addend) {
    for (int i = 0; i < 3; i++) {
        decimal.bits[i] += addend;
    }
    return decimal;
}

// Умножение s21_decimal на 10 в указанной степени
s21_decimal s21_decimal_multiply_pow10(s21_decimal decimal, int exponent) {
    if (exponent >= 0) {
        for (int i = 0; i < 3; i++) {
            decimal.bits[i] *= pow(10, exponent);
        }
    } else {
        for (int i = 0; i < 3; i++) {
            decimal.bits[i] /= pow(10, -exponent);
        }
    }
    return decimal;
}

// Деление s21_decimal на 10 в указанной степени
s21_decimal s21_decimal_divide_pow10(s21_decimal decimal, int exponent) {
    if (exponent >= 0) {
        for (int i = 0; i < 3; i++) {
            decimal.bits[i] /= pow(10, exponent);
        }
    } else {
        for (int i = 0; i < 3; i++) {
            decimal.bits[i] *= pow(10, -exponent);
        }
    }
    return decimal;
}

s21_decimal s21_float_string_to_decimal(const char* str) {
    s21_decimal result;
    for (int i = 0; i < 4; i++)
      result.bits[i] = 0;
    int exponent;

    const char* exp_char = strchr(str, 'E');
    if (exp_char == NULL) {
        exponent = 0;
    }
    
    int exp_index = exp_char - str;
    const char* exp_str = &str[exp_index + 1];
    exponent = s21_atoi(exp_str); // 1.0402E+04 -> 4
  
    // обрабатываем каждую цифру перед символом 'E'
    for (int i = 0; i < exp_index; i++) {
        if (str[i] != '.') {
            int digit = str[i] - '0';
            result = s21_decimal_multiply_int(result, 10);
            result = s21_decimal_add_int(result, digit);
        }
    }
    s21_print_decimal(&result);
  
    // корректируем decimal в зависимости от степени числа
    if (exponent >= 0) {
        result = s21_decimal_multiply_pow10(result, exponent);
    } else {
        result = s21_decimal_divide_pow10(result, -exponent);
    }

    return result;
}


int s21_from_float_to_decimal(float src, s21_decimal *dst) {
    int is_error = 0; // 0 - нет ошибки, 1 - есть

    if (!dst)
        is_error = 1;
    
    // если число бесконечное или none или слишком большое или слишком маленькое
    if (isinf(src) || isnan(src) || (fabsf(src) > 79228162514264337593543950335.0f) ||
      ((fabsf(src) > 0) && (fabsf(src) < 1e-28))) {
        is_error = 1;
    }

    s21_decimal result;
    char str_float[64];
    sprintf(str_float, "%.6E", fabsf(src));
    int exp = s21_get_exp_sign(str_float); // вернет 1.0402E+04 -> 4
    if (exp <= -23) {
        int float_precision = exp + 28;
        sprintf(str_float, "%.*E", float_precision, fabsf(src));
    }
    result = s21_float_string_to_decimal(str_float);
    //s21_print_decimal(&result);
    if (signbit(src) != 0) {
        s21_big_decimal big_result = s21_enlarge_D(result);
        s21_set_sign(&big_result, 1);
        result = s21_cut_D(big_result);
    }
    *dst = result;

    return is_error;
}

int main(void) {
  float src1 = 12345678.12345678;
  s21_decimal dst1;
  s21_from_float_to_decimal(src1, &dst1);
  printf("src1: %f\n", src1);
  s21_print_decimal(&dst1);

  return 0;
}