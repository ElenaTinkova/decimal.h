#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "s21_decimal.h"

//-----------Вывод decimal в консоль-----------//
void s21_print_decimal(s21_decimal *value) {
  int size_decimal = sizeof(s21_decimal) / 4 - 1;  //Кол-во bits в структуре
  for (int i = size_decimal; i >= 0; i--) {  //Цикл bits
    for (int j = 31; j >= 0; j--) {  //Цикл byte в bits
      if (value->bits[i] & (1 << j)) {
        printf("1");
      } else {
        printf("0");
      }
    }
    printf("\n");
  }
}

//-----------Вывод big decimal в консоль-----------//
void s21_print_big_decimal(s21_big_decimal *value) {
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;  //Кол-во bits в структуре
  for (int i = size_decimal; i >= 0; i--) {  //Цикл bits
    for (int j = 31; j >= 0; j--) {  //Цикл byte в bits
      if (value->bits[i] & (1 << j)) {
        printf("1");
      } else {
        printf("0");
      }
    }
    printf("\n");
  }
}

//-----------Получение бита в big decimal-----------//
int s21_get_big_bit(s21_big_decimal *value, int index) {
  int num_bit = index / 32;  // определяем в каком bits структуры работаем
  int position =
      index % 32;  // определяем позицию бита, который хотим проверить
  return (value->bits[num_bit] & (1 << position)) >>
         position;  // возвращаем значение искомого бита
}

//-----------Получение бита в decimal-----------//
int s21_get_bit(s21_decimal *value, int index) {
  int num_bit = index / 32; // определяем в каком bits структуры работаем
  int position = index % 32; // определяем позицию бита, который хотим проверить 
  return (value->bits[num_bit] & (1 << position)) >> position; // возвращаем значение искомого бита
}

//-----------Изменение бита в big decimal-----------//
void s21_set_big_bit(s21_big_decimal *value, int index, int bit) {
  int num_bit = index / 32;
  int position = index % 32;
  if (bit)
    value->bits[num_bit] |= (1 << position);  // меняем интересующий бит на 1
  else
    value->bits[num_bit] &= ~(1 << position);  // меняем на 0
}
//-----------Изменение бита в decimal-----------//
void s21_set_bit(s21_decimal *value, int index, int bit) {
  int num_bit = index / 32;
  int position = index % 32;
  if (bit)
    value->bits[num_bit] |= (1 << position); // меняем интересующий бит на 1
  else
    value->bits[num_bit] &= ~(1 << position); // меняем на 0
}

//-----------Получение знака big decimal-----------//
int s21_get_big_sign(s21_big_decimal *value) {
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;  //Кол-во bits в структуре
  int check_sign = value->bits[size_decimal] >> 31;
  return check_sign;
}

//-----------Получение знака decimal-----------//
int s21_get_sign(s21_decimal *value) {
  return (value->bits[3] & MASK_MINUS);
}

//-----------Изменение знака big decimal-----------//
void s21_set_big_sign(s21_big_decimal *value, int bit) {
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;  //Кол-во bits в структуре
  if (bit) {
    value->bits[size_decimal] |= MASK_MINUS;
  } else {
    value->bits[size_decimal] &= ~MASK_MINUS;
  }
}

//-----------Изменение знака decimal-----------//
void s21_set_sign(s21_decimal *value, int sign) {
  if (sign)
    value->bits[3] |= MASK_MINUS;
  else
    value->bits[3] &= ~(MASK_MINUS);
}

//-----------Получение степени decimal-----------//
int s21_get_big_pow(s21_big_decimal *value) {
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;
  int pow = 0;
  if (s21_get_big_sign(value)) {
    pow = (value->bits[size_decimal] ^ MASK_MINUS) >> 16 ;
  } else {
    pow = value->bits[size_decimal] >> 16;
  }
  return pow;
}

int s21_get_pow(s21_decimal *value){
  int size_decimal = sizeof(s21_decimal) / 4 - 1;
  int pow = 0;
  if (s21_get_sign(value)) {
    pow = (value->bits[size_decimal] ^ MASK_MINUS) >> 16 ;
  } else {
    pow = value->bits[size_decimal] >> 16;
  }
  return pow;
}

//-----------Занесение степени decimal-----------//
void s21_set_big_pow(s21_big_decimal *value, int pow_value) {
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;
  int pow;
  int sign = s21_get_big_sign(value);
  if (sign) {
    pow = (value->bits[size_decimal] ^ MASK_MINUS) >> 16;
    pow = pow_value;
    pow = pow_value << 16;
  } else {
    pow = value->bits[size_decimal] >> 16;
    pow = pow_value;
    pow = pow_value << 16;
  }
  value->bits[size_decimal] = pow;
  if (sign) s21_set_big_sign(value, 1);
}

//-----------Разница степеней decimal-----------//
int s21_difference_big_pow(s21_big_decimal *value1, s21_big_decimal *value2) {
  int dif = (s21_get_big_pow(value1)) - (s21_get_big_pow(value2));
  return dif;
}

//-----------Увеличение степени на n раз-----------//
void s21_levelup_big_pow(s21_big_decimal *value, int difference_number) {
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1;
  int value_pow = 0;
  //Заполнение массива под степень
  if (s21_get_big_sign(value)) {
    value_pow = (value->bits[size_decimal] ^ MASK_MINUS) >> 16;
    value_pow += difference_number;
    value->bits[size_decimal] = value_pow << 16;
    s21_set_big_sign(value, 1);
  } else {
    value_pow = value->bits[size_decimal] >> 16;
    value_pow += difference_number;
    value->bits[size_decimal] = value_pow << 16;
  }
}

//-----------Функция умножения-----------//
void s21_mul_ten_big(s21_big_decimal value1, s21_big_decimal value2, s21_big_decimal *result) {
  memset(result, 0, sizeof(s21_big_decimal));
  
  for (int i = 0; i <= 223; i++) {
    int temp = s21_get_big_bit(&value2, i); //бит второго множителя
    s21_big_decimal vremia = {0, 0, 0, 0, 0, 0, 0, 0}; //временный децимал для сложения в результат
    if (temp) {
      for (int j = 0; j <= 223; j++) {
        if (s21_get_big_bit(&value1, j)) { //если бит первого множителя равен 1
          s21_set_big_bit(&vremia, i + j, 1); //запись 1 со смещением
        }
      }
      s21_add_function(vremia, *result, result); //сложение результата умножения каждого разряда
    }
  }
}

//-----------Функция сложения-----------//
void s21_add_function(s21_big_decimal value1, s21_big_decimal value2, s21_big_decimal *result) {
  int check = 0;
  int buff = 0; //то что в уме)))
  memset(result, 0, sizeof(s21_big_decimal));
  for (int i = 0; i <= 223; i++) {
    check = s21_get_big_bit(&value1, i) + s21_get_big_bit(&value2, i);
    if (check == 0) {
      if (buff) {
        s21_set_big_bit(result, i, 1);
        buff = 0;
      } else {
        s21_set_big_bit(result, i, 0);
      }
    } else if (check == 1) {
      if (buff) {
        s21_set_big_bit(result, i, 0);
      } else {
        s21_set_big_bit(result, i, 1);
      }
    } else if (check == 2) {
      if (buff) {
        s21_set_big_bit(result, i, 1);
      } else {
        s21_set_big_bit(result, i,0);
        buff = 1;
      }
    }
  }
}

//-----------Функция вычитания-----------//
void s21_sub_function(s21_big_decimal value1, s21_big_decimal value2, s21_big_decimal *result) {
  int check = 0;
  int buff = 0;
  memset(result, 0, sizeof(s21_big_decimal));
  for(int i = 0; i <= 223; i++){
    check = s21_get_big_bit(&value1, i) - s21_get_big_bit(&value2, i);
    if(check == 0){
      if(buff){
        s21_set_big_bit(result, i, 1);
      }else{
        s21_set_big_bit(result, i, 0);
      }
    }else if(check == 1){
      if(buff){
        s21_set_big_bit(result, i, 0);
        buff = 0;
      }else{
        s21_set_big_bit(result, i, 1);
      }
    }else if(check == -1){
      if(buff){
        s21_set_big_bit(result, i, 0);
      }else{
        s21_set_big_bit(result, i, 1);
        buff = 1;
      }
    }
  }

}

//-----------Функция деления на 10-----------//
void s21_div_ten(s21_big_decimal *value){
    int ten = 10; //делитель
    unsigned long int rem = 0; //остаток
    unsigned long int x = 0;
    for (int i = 6; i >= 0; --i) {
        x = value->bits[i];
        x += rem << 32;
        rem = x % ten;
        x /= ten;
        value->bits[i] = x;
    }
}

//-----------Функция перевода из decimal в big decimal-----------//
s21_big_decimal s21_enlarge_D(s21_decimal number) {
    s21_big_decimal res = {number.bits[0], number.bits[1], number.bits[2], 0 ,0, 0, 0, number.bits[3]};
    return res;
}

//-----------Функция перевода из big decimal в decimal-----------//
s21_decimal s21_cut_D(s21_big_decimal number) {
    s21_decimal res = {number.bits[0], number.bits[1], number.bits[2], number.bits[7]};
    return res;
}

//-----------Функция переполнение мантиссы-----------//
int s21_overflow(s21_big_decimal *value){
  int flag = 0; //error flag
  for(int i = 3; i < 7; i++){
    unsigned int bits = value->bits[i];
    if(bits > 0){
      while(bits > 0){
        if(s21_get_big_pow(value) < 28){
          s21_div_ten(value);
          s21_levelup_big_pow(value, 1);
        }else{
          if(!s21_get_big_sign(value)){
            flag = 1;
          }else{
            flag = 2;
          }
          break; 
        }
        bits = value->bits[i];
      }
    }
  }
  return flag;
}

int s21_add_big_decimal(s21_big_decimal value_1, s21_big_decimal value_2, s21_big_decimal *result) {
  // Проверка степени перед операцией сложения
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1; //bits где лежит степень
  
  int dif = s21_difference_big_pow(&value_1, &value_2);  // dif > 0 = value_1 > value_2; dif < 0 = value_2 > value_1;
  if (dif != 0) {
    while (dif != 0) {
      s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
      if (dif > 0) { 
        s21_levelup_big_pow(&value_2, 1); //увеличение степени на 1 второго децимал
        s21_mul_ten_big(value_2, ten, &value_2); //умножение мантиссы на 10
        dif--;
       }else if(dif < 0){
         s21_levelup_big_pow(&value_1, 1); //увеличение степени на 1 первого децимал
         s21_mul_ten_big(value_1, ten, &value_1);
         dif++;
       }
    }
    result->bits[size_decimal] = value_1.bits[size_decimal]; //запись общей степени в результат
  }

  int sign1 = s21_get_big_sign(&value_1);
  int sign2 = s21_get_big_sign(&value_2);

  if (!sign1 && !sign2) { //если оба знака +
    s21_add_function(value_1, value_2, result);
  } else if (sign1 && !sign2) { // если первый знак -
    s21_set_big_sign(&value_1, 0);
    int vvs = s21_is_big_greater(value_1, value_2); //первое значение больше второго?
    if(vvs){
      s21_sub_function(value_1, value_2, result);
      s21_set_big_sign(result, 1);
    }else{
      s21_sub_function(value_2, value_1, result);
    }
  } else if (!sign1 && sign2) { // если второй знак -
    s21_set_big_sign(&value_2, 0);
    int vvs = s21_is_big_greater(value_1, value_2);
    if(vvs){
      s21_sub_function(value_1, value_2, result);
    }else{
      s21_sub_function(value_2, value_1, result);
      s21_set_big_sign(result, 1);
    }
  } else if (sign1 && sign2) { // если оба отрицательные
    s21_set_big_sign(&value_2, 0);
    s21_set_big_sign(&value_1, 0);
    s21_add_function(value_2, value_1, result);
    s21_set_big_sign(result, 1);
  }

  return 1;
}

int s21_is_big_greater(s21_big_decimal value_1, s21_big_decimal value_2) {
    // Проверка степени
    int flag = 0;
    int dif = s21_difference_big_pow(&value_1, &value_2);  // dif > 0 = value_1 > value_2; dif < 0 = value_2 > value_1;
  
    if (dif != 0) {
        while (dif != 0) {
        s21_big_decimal ten = {10, 0, 0, 0, 0, 0, 0, 0};
        if (dif > 0) { 
            s21_levelup_big_pow(&value_2, 1);
            s21_mul_ten_big(value_2, ten, &value_2);
            dif--;
        }else if(dif < 0){
            s21_levelup_big_pow(&value_1, 1);
            s21_mul_ten_big(value_1, ten, &value_1);
            dif++;
        }
        }
    }
    if(s21_get_big_sign(&value_1) && !s21_get_big_sign(&value_2)){ // - > +
        flag = 0;
    }else if(!s21_get_big_sign(&value_1) && s21_get_big_sign(&value_2)) // + > -
        flag = 1;
    else if(!s21_get_big_sign(&value_1) && !s21_get_big_sign(&value_2)){ // + > +
        for(int i = 223; i>=0; i--){
            int one = s21_get_big_bit(&value_1, i);
            int two = s21_get_big_bit(&value_2, i);
            if(one && !two){
                flag = 1;
                break;
            }else if(!one && two){
                break;
            }
        }
    }else{ // - > -
        for(int i = 223; i>=0; i--){
            int one = s21_get_big_bit(&value_1, i);
            int two = s21_get_big_bit(&value_2, i);
            if(!one && two){
                flag = 1;
                break;
            }else if(one && !two){
                break;
            }
        }
    }
    return flag;
}

int s21_is_big_equal(s21_big_decimal value_1, s21_big_decimal value_2) {
    int flag = 1;
    if(s21_get_big_sign(&value_1) != s21_get_big_sign(&value_2)){
        flag = 0;
    }else if(s21_get_big_pow(&value_1) != s21_get_big_pow(&value_2)){
        flag = 0;
    }else{
        for(int i = 223; i>=0; i--){
            int one = s21_get_big_bit(&value_1, i);
            int two = s21_get_big_bit(&value_2, i);
            if(one != two){
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

int s21_is_big_less(s21_big_decimal value_1, s21_big_decimal value_2) {
  int flag = 0;
  int dif = s21_difference_big_pow(&value_1, &value_2);  // dif > 0 = value_1 > value_2; dif < 0 = value_2 > value_1;
  
  if (dif != 0) {
    while (dif != 0) {
      
      s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
      if (dif > 0) { 
        s21_levelup_big_pow(&value_2, 1);
        s21_mul_ten_big(value_2, ten, &value_2);
        dif--;
       }else if(dif < 0){
         s21_levelup_big_pow(&value_1, 1);
         s21_mul_ten_big(value_1, ten, &value_1);
         dif++;
       }
    }
  }

    if(s21_get_big_sign(&value_1) && !s21_get_big_sign(&value_2)){ // - < +
         flag = 1;
    }else if(!s21_get_big_sign(&value_1) && s21_get_big_sign(&value_2)) // + < -
        flag = 0;
    else if(!s21_get_big_sign(&value_1) && !s21_get_big_sign(&value_2)){  // + < +
        for(int i = 223; i>=0; i--){
            int one = s21_get_big_bit(&value_1, i);
            int two = s21_get_big_bit(&value_2, i);
            if(!one && two){
                flag = 1;
                break;
            }else if(one && !two){
                break;
            }
        }
    }else{ // - < -
        for(int i = 223; i>=0; i--){
            int one = s21_get_big_bit(&value_1, i);
            int two = s21_get_big_bit(&value_2, i);
            if(one && !two){
                flag = 1;
                break;
            }else if(!one && two){
                break;
            }
        }
    }
    return flag;
}

int s21_sub_big(s21_big_decimal value_1, s21_big_decimal value_2, s21_big_decimal *result) {
  // Проверка степени перед операцией сложения
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1; //bits где лежит степень
  int dif = s21_difference_big_pow(&value_1, &value_2);  // dif > 0 = value_1 > value_2; dif < 0 = value_2 > value_1;
  
  if (dif != 0) {
    while (dif != 0) {
      s21_big_decimal ten = {{10, 0, 0, 0, 0, 0, 0, 0}};
      if (dif > 0) { 
        s21_levelup_big_pow(&value_2, 1);
        s21_mul_ten_big(value_2, ten, &value_2);
        dif--;
       }else if(dif < 0){
         s21_levelup_big_pow(&value_1, 1);
         s21_mul_ten_big(value_1, ten, &value_1);
         dif++;
       }
    }
    result->bits[size_decimal] = value_1.bits[size_decimal];
  }
  int sign1 = s21_get_big_sign(&value_1);
  int sign2 = s21_get_big_sign(&value_2);

  if (!sign1 && !sign2) { //если оба знака +
    int vvs = s21_is_big_greater(value_1, value_2);
    if(vvs){
      s21_sub_function(value_1, value_2, result);
    }else{
      s21_sub_function(value_2, value_1, result);
      s21_set_big_sign(result, 1);
    }
  } else if (sign1 && !sign2) { // если первый знак -
    s21_set_big_sign(&value_1, 0);
    s21_add_big_decimal(value_1, value_2, result);
    s21_set_big_sign(result, 1);
  } else if (!sign1 && sign2) { // если второй знак -
    s21_set_big_sign(&value_2, 0);
    s21_add_big_decimal(value_1,value_2, result);
    s21_set_big_sign(result, 0);
  } else if (sign1 && sign2) { // если оба отрицательные
    int vvs = s21_is_big_greater(value_1, value_2);
    if(vvs){
      s21_sub_function(value_2, value_1, result);
    }else{
      s21_sub_function(value_1, value_2, result);
      s21_set_big_sign(result, 1);
    }
  }
  return 0;
}

int s21_big_div(s21_big_decimal value_1, s21_big_decimal value_2, s21_big_decimal *result) {
  
  s21_big_decimal temp = {0};
  s21_big_decimal diff = {0};
  int error_code = 3;
  if (s21_is_zero(value_2)) return error_code;

  int val1_sign = s21_get_big_bit(&value_1, 255), val2_sign = s21_get_big_bit(&value_2, 255);
  if (val1_sign) s21_set_big_sign(val1_sign, 0);
  if (val2_sign) s21_set_big_sign(val2_sign, 0);

  int val1_scale = s21_get_big_pow(&value_1), val2_scale = s21_get_big_pow(&value_2);
  int res_scale = val1_scale - val2_scale;
  
  while (!s21_is_big_greater(value_2, value_1)) {
      int compare = s21_is_big_greater(value_1, value_2);
      uint8_t bit_num_result = 0; // номер бита в result, на который нужно установить значение 1
      diff = value_2; //времен. делитель
      while (compare) {
          temp = diff; // подгоняем вр.делитель под вычитание из делимого
          s21_shift_left_big_decimal(&temp); // сдвигаем
          compare = (s21_is_big_greater(value_1, temp) || (s21_is_big_equal(value_1, temp))) ? 1 : 0; // достигаем макс значения для вычитания
          if (compare) {
              bit_num_result++; // сколько раз можно вычесть 
              diff = temp;
          }
      }
      s21_set_big_bit(result, bit_num_result, 1);
      s21_sub_big(value_1, diff, &value_1);
  }
  // дополнить result знаком
  return 0;
} 

void s21_shift_left_big_decimal(s21_big_decimal *value) {
  uint8_t moved_bit = 0;
  for (int i = 0; i < 7; i++) {
      uint64_t temp = value->bits[i];
      temp <<= 1;
      temp |= moved_bit;
      moved_bit = (uint8_t) (temp >> 32);
      value->bits[i] = (uint32_t)(temp & MAX_UN_INT);
  }
}

int s21_is_zero(s21_big_decimal decimal) {
  int is_zero = 1;
  for (int byte_num = 0; byte_num < 7; byte_num++) {
    if (decimal.bits[byte_num] != 0) is_zero = 0;
  }
  return is_zero;
}
