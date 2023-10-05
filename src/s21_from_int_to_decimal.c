#include     "s21_decimal.h"
//Из int в decimal

int s21_from_int_to_decimal(int src, s21_decimal *dst){
    int error = 0;
    if((src >= -2147483648)){
        dst->bits[3] = 0;
        if (src < 0){
            src = src * -1;
            s21_set_sign(dst, 1);
        }
        dst->bits[0] = src;
        dst->bits[1] = 0;
        dst->bits[2] = 0;
        
    }else{
        error = 1; //1 - ошибка конвертации
    }
    return error;
}
