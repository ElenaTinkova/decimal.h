#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 155
#define MASK_MINUS 0x80000000 // 0b10000000000000000000000000000000
#define MASK_SCALE 0x00ff0000 // 0b00000000111111110000000000000000


typedef struct {
   int byte[4];
} s21_decimal;

typedef struct {
  unsigned int bits[7];
} big_decimal;

int get_bit_decimal(s21_decimal num, int bit);
void print_decimal(s21_decimal src);
int sign_decimal(s21_decimal sign);
int get_scale (s21_decimal num);
//s21_decimal dec(int byte0, int byte1, int byte2, int byte3, int scale);
//int get_index(int byte);
int get_bit(s21_decimal num, int bit);
s21_decimal set_bit(s21_decimal num, int bit);

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
    if (j == 7 || j == 1 || j == 14 ) printf (" ");
    j++;
    printf("%d", get_bit_decimal(src, i));
    if (i % 32 == 0) {
      printf(" = %s%d%s\n", "byte[",(i / 32), "]" );
    }
  }
}

int sign_decimal(s21_decimal sign){
  return get_bit_decimal(sign, 127);
}

int get_scale(s21_decimal num){
  int pow;
  if(sign_decimal(num)){
    pow = (num.byte[3] ^ MASK_MINUS) >> 16;
  }else{
    pow = num.byte[3] >> 16;
  }
  return pow;
}

void clear_dec(s21_decimal num){
  for(int i = 0; i < 4; i++){
    num.byte[i] = 0;
  }
}

// int get_index(int byte){
//   int index = -1;
//   for (int i = 0; i != byte; i++){
//     index++;
//   }
//   return index;
// }

//void shift_left(s21_decimal num, int shift, int n)

  // s21_decimal dec(int byte0, int byte1, int byte2, int byte3, int scale){
  //   s21_decimal num = {0};
  //   num.byte[0] = byte0;
  //   num.byte[1] = byte1;
  //   num.byte[2] = byte2;
  //   num.byte[3] = byte3;
  //   if(scale) get_scale(num);
  //   return num;
  // }

  int get_bit(s21_decimal num, int bit){
   if (num.byte[0] &(1 << bit)) {
    return 1;
  } else
  return 0;
}

  s21_decimal set_bit(s21_decimal num, int bit){
    if (!(get_bit(num, bit))){ //1
      if (num.byte[0] |(1 << bit) ){
        num.byte[0] = (num.byte[0] |(1 << bit) );
        return num;
      }
    } else {
      return num; 
    }
  }
   // 01011101
   // 00000010
   // 01011111
  int main(){
    s21_decimal num = {93};
    unsigned int number = 93;
    int bit_idnex = 5;
    print_decimal(num);
    printf("scale - %d\n", get_scale (num));
    //printf("index - %d\n\n", get_index(bit_idnex));
    printf("bit - %d\n",get_bit_decimal(num, bit_idnex));    
    printf("get_bit - %d\n", get_bit(num, bit_idnex));
    printf("set_bit - %d\n", set_bit(num, bit_idnex));
    print_decimal(set_bit(num, bit_idnex));
    return 0;
  }

