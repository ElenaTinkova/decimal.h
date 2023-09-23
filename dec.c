#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <gmp.h>

#define NUM 155
#define MASK_MINUS 0x80000000 // 0b10000000000000000000000000000000
#define MASK_SCALE 0x00ff0000 // 0b00000000111111110000000000000000

#define INT_MAX 2147483647


typedef struct {
   int byte[4];
} s21_decimal;

typedef struct {
  unsigned int bits[7];
} big_decimal;

int get_bit_decimal(s21_decimal num, int bit);
void print_decimal(s21_decimal src);
int sign_decimal(s21_decimal num);
int get_scale (s21_decimal num);
//s21_decimal dec(int byte0, int byte1, int byte2, int byte3, int scale);
//int get_index(int byte);
int get_bit(s21_decimal num, int bit);
s21_decimal set_bit(s21_decimal num, int bit);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int one_in_mantissa(s21_decimal num);
int s21_truncate(s21_decimal value, s21_decimal *result);
float decimal_in_float(s21_decimal num, float *dst);
int s21_round(s21_decimal value, s21_decimal *result);

//0 00000000 [00000000 0000001 00001111]
//вернет 1 если на битном байте стоит 1

int get_bit_decimal(s21_decimal num, int bit){
  int byte = bit / 32; // номер интов
  bit = bit % 32; // номер бита в инте
  if ((num.byte[byte]) & abs(1) << bit) {
   return 1;
  } else
  return 0;
}

void print_decimal(s21_decimal src) {
  for (int i = 127, j = 0; i >= 0; i--) {
    if (j == 7 || j == 1 || j == 16 ) printf (" ");
    j++;
    printf("%d", get_bit_decimal(src, i));
    if (i % 32 == 0) {
      printf(" = %s%d%s\n", "byte[",(i / 32), "]" );
    }
  }
}

int sign_decimal(s21_decimal sing){
  return get_bit_decimal(sing, 127);
}

int get_scale(s21_decimal num){
  int pow = 1;
  int rez = 0;
  for (int i = 16; i < 24; i ++){
    int bit = get_bit_decimal(num, i+3*32);
    rez = rez + pow * bit;
    pow = pow * 2;
  }
  return rez;
}

int one_in_mantissa(s21_decimal num){
  int rez = 0;
  for (int i = 0; i <= 96; i++){
    if (get_bit_decimal(num,i)){
     rez = 1;
     return i; // возвращать индекс для замены или 1 если нашел?
     break; 
    }
  }
  return rez;
}


void clear_dec(s21_decimal num){
  for(int i = 0; i < 4; i++){
    num.byte[i] = 0;
  }
}


  // s21_decimal dec(int byte0, int byte1, int byte2, int byte3, int scale){
  //   s21_decimal num = {0};
  //   num.byte[0] = byte0;
  //   num.byte[1] = byte1;
  //   num.byte[2] = byte2;
  //   num.byte[3] = byte3;
  //   if(scale) get_scale(num);
  //   return num;
  // }


  s21_decimal set_bit(s21_decimal num, int bit){
    if (!(get_bit_decimal (num, bit))){ //1
      if (num.byte[0] |(1 << bit) ){
        num.byte[0] = (num.byte[0] |(1 << bit) );
        return num;
      }
    } else {
      return num; 
    }
    return num; 
  }

  int s21_from_decimal_to_int(s21_decimal src, int *dst){
    int sign = get_bit_decimal(src, 127);
    int sign1 = get_bit_decimal(src, 31);
    if (src.byte[0] <= INT_MAX){
      *dst = src.byte[0];
      if (sign || sign1){
        *dst *= -1;
      } return *dst;
    } else 
      return 0;
  }


int sravnenie_celogo_polozhitelnogo (s21_decimal num, s21_decimal number){
  int decimal_1 = 0;
  int decimal_2 = 0;
  for (int i = 95; i >= 0; --i) {
    decimal_1 = get_bit_decimal (num, i);
    decimal_2 = get_bit_decimal(number, i);
    if (decimal_1 > decimal_2) {
      return 1;
    } else if (decimal_1 < decimal_2) {
      return 0;
    }
  }
  return 99;
}

// decimal на -1.
// int otricatelnyi_decimal(s21_decimal value, s21_decimal *result) {
//   if (sign_decimal(value)) {
//     if (get_bit_decimal(value, 127)){
//       !set_bit(value, 127);
//     }
//   return 0;
//   }
// }

float decimal_in_float(s21_decimal num, float *dst){
  float rez = 0;
  int znak = 0;
  for (int i = 0; i <= 95; i++) {
      rez = rez + get_bit_decimal (num, i) * pow(2, i);
    }
    rez = rez / pow(10, get_scale(num));
    if (sign_decimal(num)) {
      rez = rez * (-1);
  }
  while (znak != 7){
    rez /= 10;
    znak++;
  }
  return rez;
}
// vydat' oshibku esli bolshe 7 znakov
//2.55 / 100
int s21_truncate(s21_decimal value, s21_decimal *result){
  float x = 0.;
  float numb = decimal_in_float(value, &x);
  int number = trunc(numb);
  printf("\nnumber - %d     %d\n", numb, number);
  return 0;
}

//Округляет Decimal до ближайшего целого числа.
int s21_round(s21_decimal value, s21_decimal *result){
  float x = 0;
  float numb = decimal_in_float(value, &x);
  int number = round(numb);
  printf("\n round number - %d    %d\n", numb, number);
  return 0;
}

   // 01011101
   // 00000010
   // 01011111
  int main(){
    int dst = 0;
    float dst_float = 0.;
    s21_decimal num;
    num.byte[0] = 0b1000000000000001;
    num.byte[1] = 0b1000000000000001;
    num.byte[2] = 0b0000000000000000;
    num.byte[3] = 0b10000000000000000000000000000000;
    s21_decimal number = {4};
    //0,0000015
    //int number = 93;
    int test = 0b01011101;
    int bit_idnex = 127;
    print_decimal(num);
    printf("scale - %d\n", get_scale (num));
    printf("sign - %d\n", sign_decimal (num));
    //printf("index - %d\n\n", get_index(bit_idnex));
    printf("bit - %d\n",get_bit_decimal(num, bit_idnex));    
    //printf("get_bit - %d\n", get_bit(num, bit_idnex));
    //printf("set_bit - %d\n", set_bit(num, bit_idnex));
    printf ("\ndec to int - %d", s21_from_decimal_to_int(num, &dst));

    printf("\ndec to float - %f\n", decimal_in_float (num, &dst_float));
    printf("\ntruncate - %d\n", s21_truncate(num, &num));
    printf("\nround - %d\n",s21_round(num, &num));
    

    return 0;
  }

