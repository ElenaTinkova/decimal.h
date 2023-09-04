#include "dec_starter.h"

// ДЛЯ ПРОВЕРКИ РАБОТЫ
int main(){
    s21_decimal number;    
    number.bits[0] = 1;
    number.bits[1] = 4;
    number.bits[2] = 16;
    number.bits[3] = 0b00000000000000000000000000000000;
    s21_big_decimal bigD = s21_enlarge_D(number);


    for (int j = 3; j >=0; j--) {
    for(int i = 31; i >= 0; --i) {
        printf("%d", s21_get_bit(number.bits[j], i));
        if (i == 0) printf (" ");
    }
    }
    printf("\n");

    printf("with simple get bit\n");
    for (int j = 7; j >=0; j--) {
    for(int i = 31; i >= 0; --i) {
        printf("%d", s21_get_bit(bigD.B_bits[j], i));
        if (i == 0) printf (" ");
    }
    }
    printf("\n");

    printf("with bigD get bit\n");
    for(int i = 255; i >= 0; --i) {
        printf("%d", s21_get_bit_from_big_D(bigD, i));
        if (i == 0 || i == 32 || i == 64 || i == 96 || i == 128 || i == 160 || i == 192 || i == 224) printf (" ");
    }
    printf("\n");

    printf("%d\n", s21_get_sign(number));
    printf("%d\n", s21_get_sign_BD(bigD));

    s21_change_sign(number);
    s21_change_sign_BD(bigD);
    

    for (int j = 3; j >=0; j--) {
    for(int i = 31; i >= 0; --i) {
        printf("%d", s21_get_bit(number.bits[j], i));
        if (i == 0) printf (" ");
    }
    }
    printf("\n");

    printf("with simple get bit\n");
    for (int j = 7; j >=0; j--) {
    for(int i = 31; i >= 0; --i) {
        printf("%d", s21_get_bit(bigD.B_bits[j], i));
        if (i == 0) printf (" ");
    }
    }
    printf("\n");

    printf("with bigD get bit\n");
    for(int i = 255; i >= 0; --i) {
        printf("%d", s21_get_bit_from_big_D(bigD, i));
        if (i == 0 || i == 32 || i == 64 || i == 96 || i == 128 || i == 160 || i == 192 || i == 224) printf (" ");
    }
    printf("\n");

    return 0;
}

// ЗАПИСЬ ИЗ ДЕЦИМАЛА В БИГ ДЕЦИМАЛ
s21_big_decimal s21_enlarge_D(s21_decimal number) {
    s21_big_decimal res = {number.bits[0], number.bits[1], number.bits[2], 0 ,0, 0, 0, number.bits[3]};
    return res;
}

// ПОЛУЧНИЕ БИТА В КОНКРЕТНОМ БАЙТЕ
int s21_get_bit(int voobsheto_eto_bit, int index) {
    return (voobsheto_eto_bit & (1 << index)) != 0;
}

// УСТАНОВКА БИТА В КОНКРЕТНОМ БАЙТЕ
void s21_set_bit(int *voobsheto_eto_bit, int index, int val) {
    int shift = 1 << index;
    if (val) {
        *voobsheto_eto_bit |= shift;
    } 
    else {
        *voobsheto_eto_bit &= ~shift;
    }
}

// ПОЛУЧЕНИЕ БИТА ИЗ БИГ ДЕЦИМАЛА
int s21_get_bit_from_big_D(s21_big_decimal number, int index) {
    int res = 0;
    res = s21_get_bit(number.B_bits[index / 32], index % 32);
    return res;
}

// УСТАНОВКА БИТА В БИГ ДЕЦИМАЛ
void s21_set_bit_to_big_D(s21_big_decimal number, int index, int val) {
    s21_set_bit(&number.B_bits[index / 32], index % 32, val);
}

// ПРОВЕРКА ЗНАКА В ДЕЦИМАЛЕ
int s21_get_sign(s21_decimal number) {
    int sign = 0;
    return sign = ((s21_get_bit(number.bits[3], 31)) == 1) ? 1 : 0;
}

// ПРОВЕРКА ЗНАКА В БИГ ДЕЦИМАЛЕ
int s21_get_sign_BD(s21_big_decimal big_number) {
    int sign = 0;
    return sign = ((s21_get_bit(big_number.B_bits[7], 31)) == 1) ? 1 : 0;
}

// СМЕНА ЗНАКА В ДЕЦИМАЛЕ
void s21_change_sign(s21_decimal number){
    if (s21_get_sign(number) == 1) {
        s21_set_bit(&number.bits[3], 31, 0);
    } else {
        s21_set_bit(&number.bits[3], 31, 1);
    }
}

// СМЕНА ЗНАКА В БИГ ДЕЦИМАЛЕ
void s21_change_sign_BD(s21_big_decimal big_number){
    if (s21_get_sign_BD(big_number) == 1) {
        s21_set_bit(&big_number.B_bits[7], 31, 0);
    } else {
        s21_set_bit(&big_number.B_bits[7], 31, 1);
    }
}