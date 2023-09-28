#include "s21_decimal.h"

int s21_is_less(s21_big_decimal value_1, s21_big_decimal value_2) {
  int flag = 0;
  int size_decimal = sizeof(s21_big_decimal) / 4 - 1; //bits где лежит степень
  int dif = s21_difference_pow(&value_1, &value_2);  // dif > 0 = value_1 > value_2; dif < 0 = value_2 > value_1;
  
  if (dif != 0) {
    while (dif != 0) {
      
      s21_big_decimal ten = {10, 0, 0, 0, 0, 0, 0, 0};
      if (dif > 0) { 
        s21_levelup_pow(&value_2, 1);
        s21_mul_ten(value_2, ten, &value_2);
        dif--;
       }else if(dif < 0){
         s21_levelup_pow(&value_1, 1);
         s21_mul_ten(value_1, ten, &value_1);
         dif++;
       }
    }
  }

    if(s21_get_sign(&value_1) && !s21_get_sign(&value_2)){ // - < +
         flag = 1;
    }else if(!s21_get_sign(&value_1) && s21_get_sign(&value_2)) // + < -
        flag = 0;
    else if(!s21_get_sign(&value_1) && !s21_get_sign(&value_2)){  // + < +
        for(int i = 223; i>=0; i--){
            int one = s21_get_bit(&value_1, i);
            int two = s21_get_bit(&value_2, i);
            if(!one && two){
                flag = 1;
                break;
            }else if(one && !two){
                break;
            }
        }
    }else{ // - < -
        for(int i = 223; i>=0; i--){
            int one = s21_get_bit(&value_1, i);
            int two = s21_get_bit(&value_2, i);
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
