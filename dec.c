#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 155

typedef struct {
  unsigned int byte[4];
} s21_decimal;

typedef struct {
  unsigned int bits[7];
} big_decimal;

int get_bit_decimal(s21_decimal num, int bit);
void print_decimal(s21_decimal src);


//0 00000000 [00000000 0000001 00001111]
//вернет 1 если на битном байте стоит 1

int get_bit_decimal(s21_decimal num, int bit){
  int byte = bit / 32; // кол-во интов
  bit %= 32; // номер бита в инте
  if ((num.byte[byte]) & abs(1) << bit) {
   return 1;
  } else
  return 0;
}

void print_decimal(s21_decimal src) {
  for (int i = 127, j = 0; i >= 0; i--) {
    if (j % 8 == 0) printf (" ");
    j++;
    printf("%d", get_bit_decimal(src, i));
    if (i % 32 == 0) {
      printf(" = %s%d%s\n", "byte[",(i / 32), "]" );
    }
  }
}

//              byte[0],[1],[2],[3]
//s21_decimal num = {3,  2,  1,  0};
  int main(){
    s21_decimal num = {3,15,1,0};
    if ((get_bit_decimal(num, 3)) == 1) //ищет в 0 байте
        printf("%d\n\n", 1);
    else
      printf("%d\n\n", 0);

    print_decimal(num);
    return 0;
  }

