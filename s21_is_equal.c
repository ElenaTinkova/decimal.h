#include "s21_decimal.h"

int s21_is_equal(s21_big_decimal value_1, s21_big_decimal value_2) {
    int flag = 1;
    if(s21_get_sign(&value_1) != s21_get_sign(&value_2)){
        flag = 0;
    }else if(s21_get_pow(&value_1) != s21_get_pow(&value_2)){
        flag = 0;
    }else{
        for(int i = 223; i>=0; i--){
            int one = s21_get_bit(&value_1, i);
            int two = s21_get_bit(&value_2, i);
            if(one != two){
                flag = 0;
                break;
            }
        }
    }
    return flag;
}