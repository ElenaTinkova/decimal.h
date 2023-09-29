#include "s21_decimal.h"
#include <stdio.h>
//Округляет указанное Decimal число до ближайшего целого числа 
//в сторону отрицательной бесконечности.

int s21_floor(s21_decimal value, s21_decimal *result) {
    s21_big_decimal value1 = s21_enlarge_D(value);
    s21_big_decimal result1 = s21_enlarge_D(*result);
    
    //Зануление резутата
    for(int i = 0; i < 4; i++){
        result->bits[i] = 0;
    }
    
    //Число decimal без дробной части
    s21_truncate(value, result);

    s21_decimal dec_for_sub = {1,0,0,0};

    //Если число отрицательное     и   число decimal без дробной части не равно числу с дробной
    if(s21_get_big_sign(&value1) && !(s21_is_big_equal(value1, result1))){
        s21_sub(*result, dec_for_sub, result);
    }

    return 0;
}