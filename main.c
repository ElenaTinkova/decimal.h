#include <stdio.h>
#include <math.h>
#define MAX_UN_INT 4294967295 

typedef struct s21_decimal{
    int byte[4];
}s21_decimal;

void print_decimal(s21_decimal dec);


int get_bit(s21_decimal dec, int bit);
int set_bit(s21_decimal *dec, int number_of_bit, int bit);

int int_to_decimal(s21_decimal *dec, int chislo);

// Функции для знака
int check_sign(s21_decimal dec);
int set_sign(s21_decimal *dec, int sign);

// Функции для степени
int check_scale_bit(s21_decimal dec);
int set_scale_int(s21_decimal *dec, int scale);
int check_scale_int(s21_decimal dec);

int difference_scales(int scale_1, int scale_2);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);


int main(){
    s21_decimal dec_1 = {50, 0, 0, 0};
    print_decimal(dec_1);
    printf("\n");
    s21_decimal dec_2 = {14, 0, 0, 0};
    print_decimal(dec_2);
    printf("\n");
    s21_decimal result = {0};
    s21_add(dec_1, dec_2, &result);
    printf("\n");
    print_decimal(result);
    printf("%d\n", result.byte[0]);


    // print_decimal(dec);
    // printf("\nscale_bit before edit = ");
    // check_scale_bit(dec);
    // printf("\nscale_int before edit = %d",check_scale_int(dec));

    // int scale = 25;
    // set_scale_int(&dec, scale);

    // int scale_1 = 10;
    // int scale_2 = 10;

    // printf("\n\nDifference scales = %d", difference_scales(scale_1, scale_2));

    // printf("\n\nscale_bit after edit = ");
    // check_scale_bit(dec);
    // printf("\nscale_int before edit = %d",check_scale_int(dec));
    // printf("\n\n");


    return 0;
}

// int get_bit(s21_decimal){

// }
void print_decimal(s21_decimal dec){
    int size_of_dec = sizeof(s21_decimal);
    //int i = size_of_dec / 4 - 1;
    for(int i = size_of_dec / 4 - 1; i >= 0; i--){
        printf("byte[%d] = ", i);
        for(int j = 31; j >= 0 ; j--){
            if(dec.byte[i] & 1 << j){
                printf("1");
            }
            else
                printf("0");
                
        }
        printf("\n");
    }
}

int get_bit(s21_decimal dec, int number_of_bit){
    int num_bytes = number_of_bit / 32;
    if(dec.byte[num_bytes] & 1 << (number_of_bit - 32 * num_bytes))
        return 1;
    else
        return 0;
}

int get_bit_int(int chislo, int bit){
    if(chislo & 1 << bit)
        return 1;
    else
        return 0;
}

int set_bit(s21_decimal *dec, int number_of_bit, int bit){
    int num_bytes = number_of_bit / 32;
    if(dec->byte[num_bytes] |= bit << (number_of_bit - (32 * num_bytes)))
        return 1;
    else

        return 0;
}

int check_sign(s21_decimal dec){
    int num_byte = sizeof(s21_decimal)/4 - 1;
    if(dec.byte[num_byte] & 1 << 31)
        return 1;
    else
        return 0;
}

int set_sign(s21_decimal *dec, int sign){
    int num_byte = sizeof(s21_decimal)/4 - 1;
    if(dec->byte[num_byte] |= sign << 31)
        return 1;
    else
        return 0;
}

int check_scale_bit(s21_decimal dec){
    int num_byte = sizeof(s21_decimal)/4 - 1;
    //int flag = 0;
    for(int i = 23; i >= 16; i--){
        if(dec.byte[num_byte] & 1 << i)
            printf("1");
        else
            printf("0");
    }
    return 0;
}

int check_scale_int(s21_decimal dec){
    int scale_int = 0;
    int num_byte = sizeof(s21_decimal)/4 - 1;
    
    for(int i = 24, j = 7; i >= 17; i--, j--){
        if(dec.byte[num_byte] & 1 << i)
            scale_int |= 1 << j;
        else
            scale_int |= 0 << j;
    }
    return scale_int;
}

int set_scale_int(s21_decimal *dec, int scale){
    int num_byte = sizeof(s21_decimal)/4 - 1;
    int check_scale_bit = 0;
    for(int i = 24, j = 7; i >= 17; i--, j--){
        if(scale & 1 << j){
            check_scale_bit = 1;
        }
        else
            check_scale_bit = 0;
        dec->byte[num_byte] |= check_scale_bit << i;
    }
    return 0;
}

int difference_scales(int scale_1, int scale_2){
    int result_scale = 0;
    if(scale_1 > scale_2){
        result_scale = scale_1 - scale_2;
    } else if (scale_2 > scale_1){
        result_scale = scale_2 - scale_1;
    } else {
        result_scale = 0;
    }
    return result_scale;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result){
    int num_byte = sizeof(s21_decimal)/4 - 2;
    int temp_add_bit = 0;
    int temp_byte_value_1 = 0;
    int temp_byte_value_2 = 0;
    for(int i = 0; i < num_byte; i++){
        temp_byte_value_1 = value_1.byte[i];
        temp_byte_value_2 = value_2.byte[i];

        for(int j = 0; j < 30; j++){

            if(!get_bit_int(temp_byte_value_1, j) && !get_bit_int(temp_byte_value_2, j)){ // 0 + 0
                if (temp_add_bit == 1){
                    result->byte[i] |= 1 << j;
                    temp_add_bit = 0;
                }
                else{
                    result->byte[i] |= 0 << j;
                }
            }
            else if(get_bit_int(temp_byte_value_1, j) && !get_bit_int(temp_byte_value_2, j)){ // 1 + 0
                if(temp_add_bit == 1){
                    result->byte[i] |= 0 << j;
                    temp_add_bit == 1;
                }
                else
                    result->byte[i] |= 1 << j;
            }
            else if(!get_bit_int(temp_byte_value_1, j) && get_bit_int(temp_byte_value_2, j)){ // 0 + 1
                if(temp_add_bit == 1){
                    result->byte[i] |= 0 << j;
                    temp_add_bit == 1;
                }
                else
                    result->byte[i] |= 1 << j;
            }
            else if(get_bit_int(temp_byte_value_1, j) && get_bit_int(temp_byte_value_2, j)){ // 1 + 1
                if(temp_add_bit == 1){
                    result->byte[i] |= 1 << j;
                    temp_add_bit = 1;
                }
                else{
                    result->byte[i] |= 0 << j;
                    temp_add_bit = 1;
                }
            }
        }
    }
    return 0;
}

int int_to_decimal(s21_decimal *dec, int chislo){
    if (chislo < 0){
        chislo = chislo * -1;
        set_sign(dec, 1);
    }
    dec->byte[0] = chislo;
    return 0;
}

