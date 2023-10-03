#include "s21_dec_tests.h"

//-----------Другие функции-----------//

//десятичные числа в диапазоне от положительных 79,228,162,514,264,337,593,543,950,335 до отрицательных

//коды ошибок: 
// 0 - OK
// 1 - ошибка вычисления

// floor function
START_TEST(s21_floor_1) {
  s21_decimal dec1;
  dec1.bits[0] = 0b10010011111100000001110001010010;
  dec1.bits[1] = 0b00000000000000000000000100100000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000010100000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000001111011;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_floor(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_2) {
  s21_decimal dec1;
  dec1.bits[0] = 0b00000000000000000000000010100101;
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000010000;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_floor(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_3) {
  s21_decimal dec1;
  dec1.bits[0] = 0b10010011111111111111110001010010;  // 2483027.026
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000110000000000000000;  // 3
  s21_decimal result;
  result.bits[0] = 0b00000000001001011110001101010011;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_floor(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_4) {
  s21_decimal dec1;
  dec1.bits[0] = 0b10010011111111111111110001010011;
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b10000000000000110000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000001001011110001101010100;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal res1;
  s21_floor(dec1, &res1);
  ck_assert_float_eq_tol(res1.bits[0], result.bits[0], 1e5);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_5) {
  s21_decimal dec1;

  dec1.bits[0] = 0b00001111111111111111111111111111;
  dec1.bits[1] = 0b00111110001001010000001001100001;
  dec1.bits[2] = 0b00100000010011111100111001011110;
  dec1.bits[3] = 0b00000000000010100000000000000000;
  s21_decimal res1;
  s21_floor(dec1, &res1);
  s21_decimal result;
  result.bits[0] = 0b10100111011000111111111111111111;
  result.bits[1] = 0b00001101111000001011011010110011;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_6) {
  s21_decimal dec1;

  dec1.bits[0] = 0b00001111111111111111111111111111;
  dec1.bits[1] = 0b00111110001001010000001001100001;
  dec1.bits[2] = 0b00100000010011111100111001011110;
  dec1.bits[3] = 0b10000000000010100000000000000000;
  s21_decimal res1;
  s21_floor(dec1, &res1);
  s21_decimal result;
  result.bits[0] = 0b10100111011001000000000000000000;
  result.bits[1] = 0b00001101111000001011011010110011;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_7) {
  s21_decimal dec1;

  dec1.bits[0] = 0b10111101001001111000010001010010;
  dec1.bits[1] = 0b00000000000000000000000000011100;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b10000000000010010000000000000000;
  s21_decimal res1;
  s21_floor(dec1, &res1);
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000001111100;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_8) {
  s21_decimal dec1;

  dec1.bits[0] = 0b10010011111100000001110001010010;
  dec1.bits[1] = 0b00000000000000000000000100100000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000010100000000000000000;
  s21_decimal res1;
  s21_floor(dec1, &res1);
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000001111011;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_9) {
  s21_decimal dec1;

  dec1.bits[0] = 0b01010101001110101110101110110001;
  dec1.bits[1] = 0b00001101101101001101101001011111;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b10000000000100100000000000000000;
  s21_decimal res1;
  s21_floor(dec1, &res1);
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000000001;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_10) {
  s21_decimal dec1;

  dec1.bits[0] = 0b01010101001110101110101110110001;
  dec1.bits[1] = 0b00001101101101001101101001011111;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000100100000000000000000;
  s21_decimal res1;
  s21_floor(dec1, &res1);
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000000000;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_floor_11) {
  s21_decimal dec1;

  dec1.bits[0] = 0b10010111011100111001111111111111;
  dec1.bits[1] = 0b00111100000010000011000110001101;
  dec1.bits[2] = 0b00000000000000000000000000000001;
  dec1.bits[3] = 0b00000000000001110000000000000000;
  s21_decimal result;
  s21_floor(dec1, &result);
  s21_decimal result_origin;
  result_origin.bits[3] = 0;
  result_origin.bits[2] = 0;
  result_origin.bits[1] = 0b00000000000000000000001000010010;
  result_origin.bits[0] = 0b00110110101101101000110000111111;
  ck_assert_int_eq(result_origin.bits[3], result.bits[3]);
  ck_assert_int_eq(result_origin.bits[2], result.bits[2]);
  ck_assert_int_eq(result_origin.bits[1], result.bits[1]);
  ck_assert_int_eq(result_origin.bits[0], result.bits[0]);
}
END_TEST

// // round function
// START_TEST(s21_round_1) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b10010011111100000001110001010010;
//   dec1.bits[1] = 0b00000000000000000000000100100000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000010100000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000001111100;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_2) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b00000000000000000000000010100101;  // -16.5
//   dec1.bits[1] = 0b00000000000000000000000000000000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b10000000000000010000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000000010000;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b10000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_3) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b11111111111111111111111111111111;  // 18014398509481.983
//   dec1.bits[1] = 0b00000000001111111111111111111111;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000000110000000000000000;
//   s21_decimal result;

//   result.bits[0] = 0b01001101110100101111000110101001;  // 18014398509481
//   result.bits[1] = 0b00000000000000000001000001100010;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_4) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b00000000000011110111001001110100;  // -10123.40
//   dec1.bits[1] = 0b00000000000000000000000000000000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b10000000000000110000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000001111110100;  // -1012
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b10000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_5) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b10000000000000000000001111110100;  // 112590205.4327284
//   dec1.bits[1] = 0b00000000000001000000000000000000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b10000000000001110000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000110101101011111110101111101;  // 112590205
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b10000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_6) {
//   s21_decimal dec1;
//   dec1.bits[0] = 0b10000000000000000000001111110100;  // 2147484660
//   dec1.bits[1] = 0b00000000000000000000000000000000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b10000000000000000000001111110100;  // 2147484660
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_7) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b01100011000011111111111111111111;
//   dec1.bits[1] = 0b01101011110001110101111000101101;
//   dec1.bits[2] = 0b00000000000000000000000000000101;
//   dec1.bits[3] = 0b10000000000010100000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b01010100000010111110010000000000;
//   result.bits[1] = 0b00000000000000000000000000000010;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b10000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_8) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b01010101001110101110101110110001;
//   dec1.bits[1] = 0b00001101101101001101101001011111;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b10000000000100100000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000000000001;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b10000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_9) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b10010011111100000001110001010010;
//   dec1.bits[1] = 0b00000000000000000000000100100000;
//   dec1.bits[2] = 0b00000000000000000000000000000000;
//   dec1.bits[3] = 0b00000000000010100000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b00000000000000000000000001111100;
//   result.bits[1] = 0b00000000000000000000000000000000;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_10) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b11001101110001110111110001000000;
//   dec1.bits[1] = 0b00111110001001010000001001100000;
//   dec1.bits[2] = 0b00100000010011111100111001011110;
//   dec1.bits[3] = 0b10000000000001000000000000000000;
//   s21_decimal result;
//   result.bits[0] = 0b10100000111111100100111000000100;
//   result.bits[1] = 0b00011011110011101100110011101101;
//   result.bits[2] = 0b00000000000000001101001111000010;
//   result.bits[3] = 0b10000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_11) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b10100000111111100100111000000100;
//   dec1.bits[1] = 0b00011011110011101100110011101101;
//   dec1.bits[2] = 0b00000000000000001101001111000010;
//   dec1.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   s21_decimal result;
//   result.bits[0] = 0b10100000111111100100111000000100;
//   result.bits[1] = 0b00011011110011101100110011101101;
//   result.bits[2] = 0b00000000000000001101001111000010;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_12) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b10010111011100111001111111111111;
//   dec1.bits[1] = 0b00111100000010000011000110001101;
//   dec1.bits[2] = 0b00000000000000000000000000000001;
//   dec1.bits[3] = 0b00000000000001110000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   s21_decimal result;
//   result.bits[0] = 0b00110110101101101000110001000000;
//   result.bits[1] = 0b00000000000000000000001000010010;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_round_13) {
//   s21_decimal dec1;

//   dec1.bits[0] = 0b10010111011100111001111111111111;
//   dec1.bits[1] = 0b00111100000010000011000110001101;
//   dec1.bits[2] = 0b00000000000000000000000000000001;
//   dec1.bits[3] = 0b10000000000001110000000000000000;
//   s21_decimal res1;
//   s21_round(dec1, &res1);
//   s21_decimal result;
//   result.bits[0] = 0b00110110101101101000110001000000;
//   result.bits[1] = 0b00000000000000000000001000010010;
//   result.bits[2] = 0b00000000000000000000000000000000;
//   result.bits[3] = 0b10000000000000000000000000000000;

//   ck_assert_float_eq(res1.bits[0], result.bits[0]);
//   ck_assert_float_eq(res1.bits[1], result.bits[1]);
//   ck_assert_float_eq(res1.bits[2], result.bits[2]);
//   ck_assert_float_eq(res1.bits[3], result.bits[3]);
// }
// END_TEST

// START_TEST(s21_roundTest1) {
//   s21_decimal src1, origin;
//   // src1 = 2;

//   src1.bits[0] = 2;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 2;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest2) {
//   s21_decimal src1, origin;
//   // src1 = 3.5;

//   src1.bits[0] = 0b00000000000000000000000000100011;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000010000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b00000000000000000000000000000100;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest3) {
//   s21_decimal src1, origin;
//   // src1 = -3.5;

//   src1.bits[0] = 0b00000000000000000000000000100011;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000010000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b00000000000000000000000000000100;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest4) {
//   s21_decimal src1, origin;
//   // src1 = 0;

//   src1.bits[0] = 0b00000000000000000000000000000000;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b00000000000000000000000000000000;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest5) {
//   s21_decimal src1, origin;
//   // src1 = -9878798789;

//   src1.bits[0] = 0b01001100110100101000000111000101;
//   src1.bits[1] = 0b00000000000000000000000000000010;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000000000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b01001100110100101000000111000101;
//   origin.bits[1] = 0b00000000000000000000000000000010;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest6) {
//   s21_decimal src1, origin;
//   // src1 = -545454512454545.35265;

//   src1.bits[0] = 0b11011110101101001010101001100001;
//   src1.bits[1] = 0b11110100111110000101111011101001;
//   src1.bits[2] = 0b00000000000000000000000000000010;
//   src1.bits[3] = 0b10000000000001010000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b10000110011101001011101110010001;
//   origin.bits[1] = 0b00000000000000011111000000010110;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest7) {
//   s21_decimal src1, origin;
//   // src1 = -5.492654545456454545645464;

//   src1.bits[0] = 0b00000111100110110001111110011000;
//   src1.bits[1] = 0b01100110010010001001000110100011;
//   src1.bits[2] = 0b00000000000001001000101100011101;
//   src1.bits[3] = 0b10000000000110000000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b00000000000000000000000000000101;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest8) {
//   s21_decimal src1, origin;
//   // src1 = 7961327845421.879754123131254;

//   src1.bits[0] = 0b01001110111001000011100101110110;
//   src1.bits[1] = 0b01001011001101011010000111011001;
//   src1.bits[2] = 0b00011001101110010111010010111111;
//   src1.bits[3] = 0b00000000000011110000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b10100100000111100100000000101110;
//   origin.bits[1] = 0b00000000000000000000011100111101;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest9) {
//   s21_decimal src1, origin;
//   // src1 = -12345677.187654345678987654346;

//   src1.bits[0] = 0b01111000100010101111010011001010;
//   src1.bits[1] = 0b01100010000010101110010010000111;
//   src1.bits[2] = 0b00100111111001000001101011010101;
//   src1.bits[3] = 0b10000000000101010000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b00000000101111000110000101001101;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest10) {
//   s21_decimal src1, origin;
//   // src1 = 2.5986531268974139743;

//   src1.bits[0] = 0b10101111110010001101100101011111;
//   src1.bits[1] = 0b01101000101000101011010010000001;
//   src1.bits[2] = 0b00000000000000000000000000000001;
//   src1.bits[3] = 0b00000000000100110000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b00000000000000000000000000000010;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest11) {
//   s21_decimal src1, origin;
//   // src1 = 1;

//   src1.bits[0] = 0b00000000000000000000000000000001;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000000000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b00000000000000000000000000000001;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest12) {
//   s21_decimal src1, origin;
//   // src1 = 1.1;

//   src1.bits[0] = 0b00000000000000000000000000001011;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000010000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b00000000000000000000000000000001;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest13) {
//   s21_decimal src1, origin;
//   // src1 = -1.1;

//   src1.bits[0] = 0b00000000000000000000000000001011;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000010000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b00000000000000000000000000000001;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest14) {
//   s21_decimal src1, origin;
//   // src1 = 24.56;

//   src1.bits[0] = 0b00000000000000000000100110011000;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b00000000000000100000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b00000000000000000000000000011000;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b00000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST

// START_TEST(s21_roundTest15) {
//   s21_decimal src1, origin;
//   // src1 = -2.124;

//   src1.bits[0] = 0b00000000000000000000100001001100;
//   src1.bits[1] = 0b00000000000000000000000000000000;
//   src1.bits[2] = 0b00000000000000000000000000000000;
//   src1.bits[3] = 0b10000000000000110000000000000000;
//   s21_decimal result = {{0, 0, 0, 0}};
//   s21_round(src1, &result);
//   origin.bits[0] = 0b00000000000000000000000000000010;
//   origin.bits[1] = 0b00000000000000000000000000000000;
//   origin.bits[2] = 0b00000000000000000000000000000000;
//   origin.bits[3] = 0b10000000000000000000000000000000;
//   ck_assert_int_eq(origin.bits[3], result.bits[3]);
//   ck_assert_int_eq(origin.bits[2], result.bits[2]);
//   ck_assert_int_eq(origin.bits[1], result.bits[1]);
//   ck_assert_int_eq(origin.bits[0], result.bits[0]);
// }
// END_TEST


// truncate function
START_TEST(s21_trun_1) {
  s21_decimal dec1;
  dec1.bits[0] = 0b00000000000000000000000011010011;  // 21.1
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000010101;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_trun_2) {
  s21_decimal dec1;
  dec1.bits[0] = 0b00000000000000000000000010100101;
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000010000;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_trun_3) {
  s21_decimal dec1;
  dec1.bits[0] =
      0b11111111111111111111111111111111;  // 7922816251426433759354395033.5
  dec1.bits[1] = 0b11111111111111111111111111111111;
  dec1.bits[2] = 0b11111111111111111111111111111111;
  dec1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result;
  result.bits[0] = 0b10011001100110011001100110011001;
  result.bits[1] = 0b10011001100110011001100110011001;
  result.bits[2] = 0b00011001100110011001100110011001;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_trun_4) {
  s21_decimal dec1;
  dec1.bits[0] = 0b10000000000000000000000010100101;  // 214.7483813
  dec1.bits[1] = 0b00000000000000000000000000000000;
  dec1.bits[2] = 0b00000000000000000000000000000000;
  dec1.bits[3] = 0b00000000000001110000000000000000;
  float num = 0.0;
  s21_from_decimal_to_float(dec1, &num);
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000011010110;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_1) {
  s21_decimal dec1;

  dec1.bits[3] = 0x000A0000;
  dec1.bits[2] = 0x0;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  s21_decimal result;
  result.bits[3] = 0x0;
  result.bits[2] = 0x0;
  result.bits[1] = 0x0;
  result.bits[0] = 0x6DF37F67;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_2) {
  s21_decimal dec1;

  dec1.bits[3] = 0b10000000000011000000000000000000;
  dec1.bits[2] = 0x0;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  s21_decimal result;
  result.bits[3] = 0b10000000000000000000000000000000;
  result.bits[2] = 0x0;
  result.bits[1] = 0x0;
  result.bits[0] = 0x1197998;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_3) {
  s21_decimal dec1;

  dec1.bits[3] = 0x80000000;
  dec1.bits[2] = 0x0;
  dec1.bits[1] = 0xFFFFFFFF;
  dec1.bits[0] = 0xFFFFFFFF;
  s21_decimal result;
  result.bits[3] = 0x80000000;
  result.bits[2] = 0x0;
  result.bits[1] = 0xFFFFFFFF;
  result.bits[0] = 0xFFFFFFFF;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_4) {
  s21_decimal dec1;

  dec1.bits[0] = 0b00000000000000000000000001101101;
  dec1.bits[1] = 0b00000000000011000110010101011011;
  dec1.bits[2] = 0b00000000000000000011000000111001;
  dec1.bits[3] = 0b00000000000011100000000000000000;
  s21_decimal result;
  result.bits[0] = 0b10000111101111000001011000011110;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_5) {
  s21_decimal dec1;

  dec1.bits[0] = 0b11011110101001001000000010110110;
  dec1.bits[1] = 0b01011111101001011101111110100000;
  dec1.bits[2] = 0b00011111111010011010111101100000;
  dec1.bits[3] = 0b00000000000010010000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00110100101011011100000100111110;
  result.bits[1] = 0b10001001000100001000011110111001;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncate_6) {
  s21_decimal dec1;

  dec1.bits[3] = 0x80090000;
  dec1.bits[2] = 0;
  dec1.bits[1] = 0xFFFFEA34;
  dec1.bits[0] = 0xFF837E4F;
  s21_decimal result;
  s21_truncate(dec1, &result);
  s21_decimal res1;

  res1.bits[3] = 0x80000000;
  res1.bits[2] = 0;
  res1.bits[1] = 0x4;
  res1.bits[0] = 0x4B829C70;
  ck_assert_int_eq(res1.bits[3], result.bits[3]);
  ck_assert_int_eq(res1.bits[2], result.bits[2]);
  ck_assert_int_eq(res1.bits[1], result.bits[1]);
  ck_assert_int_eq(res1.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncate_7) {
  s21_decimal dec1;

  dec1.bits[0] = 0b11010000101000110011000001101101;
  dec1.bits[1] = 0b00011111100110100110101101011000;
  dec1.bits[2] = 0;
  dec1.bits[3] = 0b00000000000010010000000000000000;
  s21_decimal result;
  s21_truncate(dec1, &result);
  s21_decimal result_origin;
  result_origin.bits[3] = 0;
  result_origin.bits[2] = 0;
  result_origin.bits[1] = 0;
  result_origin.bits[0] = 0b10000111101111000001011000011110;
  ck_assert_int_eq(result_origin.bits[3], result.bits[3]);
  ck_assert_int_eq(result_origin.bits[2], result.bits[2]);
  ck_assert_int_eq(result_origin.bits[1], result.bits[1]);
  ck_assert_int_eq(result_origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncate_8) {
  s21_decimal dec1;

  dec1.bits[0] = 0b01111000101001111011110011000110;
  dec1.bits[1] = 0b10011111111111001111101010000100;
  dec1.bits[2] = 0b00011111111010011010111101101101;
  dec1.bits[3] = 0b00000000000111000000000000000000;
  s21_decimal result;
  result.bits[0] = 0b00000000000000000000000000000000;
  result.bits[1] = 0b00000000000000000000000000000000;
  result.bits[2] = 0b00000000000000000000000000000000;
  result.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal res1;
  s21_truncate(dec1, &res1);
  ck_assert_float_eq(res1.bits[0], result.bits[0]);
  ck_assert_float_eq(res1.bits[1], result.bits[1]);
  ck_assert_float_eq(res1.bits[2], result.bits[2]);
  ck_assert_float_eq(res1.bits[3], result.bits[3]);
}
END_TEST

START_TEST(s21_truncateTest1) {
  s21_decimal src1, origin;
  // src1 = 2;

  src1.bits[0] = 0b00000000000000000000000000000010;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncateTest2) {
  s21_decimal src1, origin;
  // src1 = 3.5;

  src1.bits[0] = 0b00000000000000000000000000100011;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000010000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncateTest3) {
  s21_decimal src1, origin;
  // src1 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncateTest4) {
  s21_decimal src1, origin;
  // src1 = 0;

  src1.bits[0] = 0b00000000000000000000000000000000;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncateTest5) {
  s21_decimal src1, origin;
  // src1 = -9878798789;

  src1.bits[0] = 0b01001100110100101000000111000101;
  src1.bits[1] = 0b00000000000000000000000000000010;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b10000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[0] = 0b01001100110100101000000111000101;
  origin.bits[1] = 0b00000000000000000000000000000010;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncateTest6) {
  s21_decimal src1, origin;
  // src1 = -545454512454545.35265454545645;

  src1.bits[0] = 0b10000010111000100101101011101101;
  src1.bits[1] = 0b11111001111010000010010110101101;
  src1.bits[2] = 0b10110000001111101111000010010100;
  src1.bits[3] = 0b10000000000011100000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[0] = 0b10000110011101001011101110010001;
  origin.bits[1] = 0b00000000000000011111000000010110;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncateTest7) {
  s21_decimal src1, origin;
  // src1 = -5.492654545456454545645464;

  src1.bits[0] = 0b00000111100110110001111110011000;
  src1.bits[1] = 0b01100110010010001001000110100011;
  src1.bits[2] = 0b00000000000001001000101100011101;
  src1.bits[3] = 0b10000000000110000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncateTest8) {
  s21_decimal src1, origin;
  // src1 = 7961327845421.879754123131254;

  src1.bits[0] = 0b01001110111001000011100101110110;
  src1.bits[1] = 0b01001011001101011010000111011001;
  src1.bits[2] = 0b00011001101110010111010010111111;
  src1.bits[3] = 0b00000000000011110000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[0] = 0b10100100000111100100000000101101;
  origin.bits[1] = 0b00000000000000000000011100111101;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncateTest9) {
  s21_decimal src1, origin;
  // src1 = -12345677.187654345678987654346;

  src1.bits[0] = 0b01111000100010101111010011001010;
  src1.bits[1] = 0b01100010000010101110010010000111;
  src1.bits[2] = 0b00100111111001000001101011010101;
  src1.bits[3] = 0b10000000000101010000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[0] = 0b00000000101111000110000101001101;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncateTest10) {
  s21_decimal src1, origin;
  // src1 = 2.5086531268974139743;

  src1.bits[0] = 0b01100101111011101101100101011111;
  src1.bits[1] = 0b01011100001001010100001101000110;
  src1.bits[2] = 0b00000000000000000000000000000001;
  src1.bits[3] = 0b00000000000100110000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST

START_TEST(s21_truncateTest11) {
  s21_decimal src1, origin;
  // src1 = 1;

  src1.bits[0] = 0b00000000000000000000000000000001;
  src1.bits[1] = 0b00000000000000000000000000000000;
  src1.bits[2] = 0b00000000000000000000000000000000;
  src1.bits[3] = 0b00000000000000000000000000000000;
  s21_decimal result = {{0, 0, 0, 0}};
  s21_truncate(src1, &result);

  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
}
END_TEST



// negate function
START_TEST(s21_negate_1) {
  s21_decimal value_1 = {{1, 1, 1, 0}};
  s21_decimal check = {{1, 1, 1, 0b10000000000000000000000000000000}};
  s21_decimal result = {0};
  int return_value = s21_negate(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_negate_2) {
  s21_decimal value_1 = {{1, 1, 1, 0b10000000000000000000000000000000}};
  s21_decimal check = {{1, 1, 1, 0b00000000000000000000000000000000}};
  s21_decimal result = {0};
  int return_value = s21_negate(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

START_TEST(s21_negate_3) {
  s21_decimal value_1 = {{1, 1, 1, 0b10000000000000000000000000000000}};
  s21_set_pow(&value_1, 12);
  s21_decimal check = {{1, 1, 1, 0b00000000000000000000000000000000}};
  s21_set_pow(&check, 12);
  s21_decimal result = {0};
  int return_value = s21_negate(value_1, &result);
  ck_assert_int_eq(s21_is_equal(result, check), 1);
  ck_assert_int_eq(return_value, 0);
}
END_TEST

// START_TEST(s21_negate_2) {
//   float a = 10.1234e5;
//   float res_a = 0;
//   s21_decimal src = {0};
//   s21_from_float_to_decimal(a, &src);
//   s21_decimal res = {0};
//   s21_negate(src, &res);
//   s21_from_decimal_to_float(res, &res_a);
//   ck_assert_float_eq(-10.1234e5, res_a);
// }
// END_TEST

//----------------INT_TO_DEC--------------------------

START_TEST(int_to_dec_1) {
  s21_decimal result, origin;
  int src = 1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_2) {
  s21_decimal result, origin;
  int src = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_3) {
  s21_decimal result, origin;
  int src = -1;
  origin.bits[0] = 0b00000000000000000000000000000001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_4) {
  s21_decimal result, origin;
  int src = 2147483647;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_5) {
  s21_decimal result, origin;
  int src = -2147483647;
  origin.bits[0] = 0b01111111111111111111111111111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_6) {
  s21_decimal result, origin;
  int src = -12345;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_7) {
  s21_decimal result, origin;
  int src = -12345;
  origin.bits[0] = 0b00000000000000000011000000111001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_8) {
  s21_decimal result, origin;
  int src = 0;
  origin.bits[0] = 0b00000000000000000000000000000000;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_9) {
  s21_decimal result, origin;
  int src = 45678;
  origin.bits[0] = 0b00000000000000001011001001101110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_10) {
  s21_decimal result, origin;
  int src = -45678;
  origin.bits[0] = 0b00000000000000001011001001101110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_11) {
  s21_decimal result, origin;
  int src = 5555555;
  origin.bits[0] = 0b00000000010101001100010101100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_12) {
  s21_decimal result, origin;
  int src = -5555555;
  origin.bits[0] = 0b00000000010101001100010101100011;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_13) {
  s21_decimal result, origin;
  int src = 127;
  origin.bits[0] = 0b00000000000000000000000001111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_14) {
  s21_decimal result, origin;
  int src = -127;
  origin.bits[0] = 0b00000000000000000000000001111111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_15) {
  s21_decimal result, origin;
  int src = 34567898;
  origin.bits[0] = 0b00000010000011110111011011011010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_16) {
  s21_decimal result, origin;
  int src = -34567898;
  origin.bits[0] = 0b00000010000011110111011011011010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_17) {
  s21_decimal result, origin;
  int src = 999;
  origin.bits[0] = 0b00000000000000000000001111100111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_18) {
  s21_decimal result, origin;
  int src = -999;
  origin.bits[0] = 0b00000000000000000000001111100111;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_19) {
  s21_decimal result, origin;
  int src = -3254754;
  origin.bits[0] = 0b00000000001100011010100111100010;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b10000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_20) {
  s21_decimal result, origin;
  int src = 3436425;
  origin.bits[0] = 0b00000000001101000110111110001001;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

START_TEST(int_to_dec_21) {
  s21_decimal result, origin;
  int src = 222222222;
  origin.bits[0] = 0b00001101001111101101011110001110;
  origin.bits[1] = 0b00000000000000000000000000000000;
  origin.bits[2] = 0b00000000000000000000000000000000;
  origin.bits[3] = 0b00000000000000000000000000000000;
  int result_error = 0;
  int my_error = s21_from_int_to_decimal(src, &result);
  ck_assert_int_eq(origin.bits[3], result.bits[3]);
  ck_assert_int_eq(origin.bits[2], result.bits[2]);
  ck_assert_int_eq(origin.bits[1], result.bits[1]);
  ck_assert_int_eq(origin.bits[0], result.bits[0]);
  ck_assert_int_eq(result_error, my_error);
}
END_TEST

//-----------------DEC_TO_INT--------------

START_TEST(dec_to_int_2) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000100010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 3;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_3) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 0;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_4) {
  s21_decimal src;
  src.bits[0] = 0b00000001011100111100000111000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000001110000000000000000;
  int result = 0;
  int origin = -2;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_5) {
  s21_decimal src;
  src.bits[0] = 0b00000000000000000000000000000000;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000010000000000000000;
  int result = 0;
  int origin = 0;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_7) {
  s21_decimal src;
  src.bits[0] = 0b00000011111000110110011011000111;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000001010000000000000000;
  int result = 0;
  int origin = 652;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_8) {
  s21_decimal src;
  src.bits[0] = 0b00011101101010010010000100011011;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010000000000000000000;
  int result = 0;
  int origin = 4;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_9) {
  s21_decimal src;
  src.bits[0] = 0b10000111010110110010011111110011;
  src.bits[1] = 0b00000000000000000000000000000001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000100000000000000000;
  int result = 0;
  int origin = 65658654;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_10) {
  s21_decimal src;
  src.bits[0] = 0b00010101101111011001110101001110;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000110000000000000000;
  int result = 0;
  int origin = -364748;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_11) {
  s21_decimal src;
  src.bits[0] = 0b01101000011010011010001100101111;
  src.bits[1] = 0b00000000000000000001001000010011;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011010000000000000000;
  int result = 0;
  int origin = 1;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_12) {
  s21_decimal src;
  src.bits[0] = 0b00010110010010101110101011000000;
  src.bits[1] = 0b00000000000000000000100011111100;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000010110000000000000000;
  int result = 0;
  int origin = -98;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_13) {
  s21_decimal src;
  src.bits[0] = 0b00111011100110101100100111111001;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000000010000000000000000;
  int result = 0;
  int origin = 99999999;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_14) {
  s21_decimal src;
  src.bits[0] = 0b11001010011010010001110011000010;
  src.bits[1] = 0b10011001110101001010110100100110;
  src.bits[2] = 0b10110000001111100010111010011101;
  src.bits[3] = 0b10000000000101110000000000000000;
  int result = 0;
  int origin = -545445;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_15) {
  s21_decimal src;
  src.bits[0] = 0b11101010011100001110100101000111;
  src.bits[1] = 0b10100010011001110000111100001010;
  src.bits[2] = 0b10110000001111101111000100010000;
  src.bits[3] = 0b00000000000101100000000000000000;
  int result = 0;
  int origin = 5454545;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_16) {
  s21_decimal src;
  src.bits[0] = 0b11101010001011100110110001010100;
  src.bits[1] = 0b00100111000110111110101011111001;
  src.bits[2] = 0b00011001101111000001110101101001;
  src.bits[3] = 0b00000000000101000000000000000000;
  int result = 0;
  int origin = 79645421;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_17) {
  s21_decimal src;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b00000000000101010000000000000000;
  int result = 0;
  int origin = 12345677;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_18) {
  s21_decimal src;
  src.bits[0] = 0b10010001000010101111010011001010;
  src.bits[1] = 0b11000000010001011101010111110010;
  src.bits[2] = 0b00100111111001000001101100000000;
  src.bits[3] = 0b10000000000101010000000000000000;
  int result = 0;
  int origin = -12345677;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_19) {
  s21_decimal src;
  src.bits[0] = 0b10011100101100011101000110000101;
  src.bits[1] = 0b01100001100101011101011101110110;
  src.bits[2] = 0b00000000000000000000000011101010;
  src.bits[3] = 0b00000000000100000000000000000000;
  int result = 0;
  int origin = 432356;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_20) {
  s21_decimal src;
  src.bits[0] = 0b01100001011111010111001111001001;
  src.bits[1] = 0b00000000100111100100000111010001;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000010010000000000000000;
  int result = 0;
  int origin = 44545413;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_21) {
  s21_decimal src;
  src.bits[0] = 0b01011100000110001011011001101010;
  src.bits[1] = 0b00000000000000000000000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b10000000000000000000000000000000;
  int result = 0;
  int origin = -1545123434;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_23) {
  s21_decimal src;
  src.bits[0] = 0b10101001101110110110011111111111;
  src.bits[1] = 0b00001010111111101100000000000000;
  src.bits[2] = 0b00000000000000000000000000000000;
  src.bits[3] = 0b00000000000011000000000000000000;
  int result = 0;
  int origin = 792281;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST

START_TEST(dec_to_int_24) {
  s21_decimal src;
  src.bits[0] = 0b11111110100100001101100101011111;
  src.bits[1] = 0b10000100011001000010000111101000;
  src.bits[2] = 0b00000000000000000000000000000001;
  src.bits[3] = 0b00000000000100110000000000000000;
  int result = 0;
  int origin = 2;
  int origin_error = 0;
  int my_error = s21_from_decimal_to_int(src, &result);
  ck_assert_int_eq(origin, result);
  ck_assert_int_eq(origin_error, my_error);
}
END_TEST


// START_TEST(s21_from_float_to_decimal_1) {
//   s21_decimal val;
//   s21_from_float_to_decimal(0.03F, &val);

//   ck_assert_int_eq(val.bits[0], 3);
//   ck_assert_int_eq(val.bits[1], 0);
//   ck_assert_int_eq(val.bits[2], 0);
//   ck_assert_int_eq(val.bits[3], 131072);

//   s21_from_float_to_decimal(127.1234F, &val);
//   ck_assert_int_eq(val.bits[0], 1271234);
//   ck_assert_int_eq(val.bits[1], 0);
//   ck_assert_int_eq(val.bits[2], 0);
//   ck_assert_int_eq(val.bits[3], 262144);
// }
// END_TEST

// START_TEST(s21_from_float_to_decimal_2) {
//   s21_decimal val;
//   s21_from_float_to_decimal(22.14836E+03F, &val);
//   ck_assert_int_eq(val.bits[0], 2214836);
//   ck_assert_int_eq(val.bits[1], 0);
//   ck_assert_int_eq(val.bits[2], 0);
//   ck_assert_int_eq(val.bits[3], 131072);
// }
// END_TEST

// START_TEST(s21_from_float_to_decimal_3) {
//   s21_decimal val;
//   s21_from_float_to_decimal(102., &val);

//   ck_assert_int_eq(val.bits[0], 102);
//   ck_assert_int_eq(val.bits[1], 0);
//   ck_assert_int_eq(val.bits[2], 0);
//   ck_assert_int_eq(val.bits[3], 0);
// }
// END_TEST

// START_TEST(s21_from_float_to_decimal_4) {
//   s21_decimal val;

//   float a = 1.0F / 0.0F;
//   int err_check = s21_from_float_to_decimal(a, &val);
//   ck_assert_int_eq(err_check, 1);
//   ck_assert_int_eq(val.bits[0], 0);
//   ck_assert_int_eq(val.bits[1], 0);
//   ck_assert_int_eq(val.bits[2], 0);
//   ck_assert_int_eq(val.bits[3], 0);
// }
// END_TEST

// START_TEST(s21_from_float_to_decimal_5) {
//   s21_decimal val;
//   float a = -1.0F / 0.0F;
//   int err_check = s21_from_float_to_decimal(a, &val);
//   ck_assert_int_eq(err_check, 1);
// }
// END_TEST

// START_TEST(s21_from_float_to_decimal_6) {
//   s21_decimal val;
//   float a = NAN;
//   int err_check = s21_from_float_to_decimal(a, &val);
//   ck_assert_int_eq(err_check, 1);
//   ck_assert_int_eq(val.bits[0], 0);
//   ck_assert_int_eq(val.bits[1], 0);
//   ck_assert_int_eq(val.bits[2], 0);
//   ck_assert_int_eq(val.bits[3], 0);
// }
// END_TEST

// START_TEST(s21_from_float_to_decimal_7) {
//   s21_decimal val;
//   s21_from_float_to_decimal(0.0F, &val);
//   ck_assert_int_eq(val.bits[0], 0);
//   ck_assert_int_eq(val.bits[1], 0);
//   ck_assert_int_eq(val.bits[2], 0);
//   ck_assert_int_eq(val.bits[3], 0);
// }
// END_TEST



void srunner_add_others_tests(SRunner *sr) {
  Suite *save_v2 = suite_create("Others");
  TCase *tc_others = tcase_create("Others");
  suite_add_tcase(save_v2, tc_others);

  //floor
  tcase_add_test(tc_others, s21_floor_1);
  tcase_add_test(tc_others, s21_floor_2);
  tcase_add_test(tc_others, s21_floor_3);
  tcase_add_test(tc_others, s21_floor_4);
  tcase_add_test(tc_others, s21_floor_5);
  tcase_add_test(tc_others, s21_floor_6);
  tcase_add_test(tc_others, s21_floor_7);
  tcase_add_test(tc_others, s21_floor_8);
  tcase_add_test(tc_others, s21_floor_9);
  tcase_add_test(tc_others, s21_floor_10);
  tcase_add_test(tc_others, s21_floor_11);

  //round
  // tcase_add_test(tc_others, s21_round_1);
  // tcase_add_test(tc_others, s21_round_2);
  // tcase_add_test(tc_others, s21_round_3);
  // tcase_add_test(tc_others, s21_round_4);
  // tcase_add_test(tc_others, s21_round_5);
  // tcase_add_test(tc_others, s21_round_6);
  // tcase_add_test(tc_others, s21_round_7);
  // tcase_add_test(tc_others, s21_round_8);
  // tcase_add_test(tc_others, s21_round_9);
  // tcase_add_test(tc_others, s21_round_10);
  // tcase_add_test(tc_others, s21_round_11);
  // tcase_add_test(tc_others, s21_round_12);
  // tcase_add_test(tc_others, s21_round_13);
  // tcase_add_test(tc_others, s21_roundTest1);
  // tcase_add_test(tc_others, s21_roundTest2);
  // tcase_add_test(tc_others, s21_roundTest3);
  // tcase_add_test(tc_others, s21_roundTest4);
  // tcase_add_test(tc_others, s21_roundTest5);
  // tcase_add_test(tc_others, s21_roundTest6);
  // tcase_add_test(tc_others, s21_roundTest7);
  // tcase_add_test(tc_others, s21_roundTest8);
  // tcase_add_test(tc_others, s21_roundTest9);
  // tcase_add_test(tc_others, s21_roundTest10);
  // tcase_add_test(tc_others, s21_roundTest11);
  // tcase_add_test(tc_others, s21_roundTest12);
  // tcase_add_test(tc_others, s21_roundTest13);
  // tcase_add_test(tc_others, s21_roundTest14);
  // tcase_add_test(tc_others, s21_roundTest15);


  // //truncate
  tcase_add_test(tc_others, s21_trun_1);
  tcase_add_test(tc_others, s21_trun_2);
  tcase_add_test(tc_others, s21_trun_3);
  tcase_add_test(tc_others, s21_trun_4);
  tcase_add_test(tc_others, s21_truncate_1);
  tcase_add_test(tc_others, s21_truncate_2);
  tcase_add_test(tc_others, s21_truncate_3);
  tcase_add_test(tc_others, s21_truncate_4);
  tcase_add_test(tc_others, s21_truncate_5);
  tcase_add_test(tc_others, s21_truncate_6);
  tcase_add_test(tc_others, s21_truncate_7);
  tcase_add_test(tc_others, s21_truncate_8);
  tcase_add_test(tc_others, s21_truncateTest1);
  tcase_add_test(tc_others, s21_truncateTest2);
  tcase_add_test(tc_others, s21_truncateTest3);
  tcase_add_test(tc_others, s21_truncateTest4);
  tcase_add_test(tc_others, s21_truncateTest5);
  tcase_add_test(tc_others, s21_truncateTest6);
  tcase_add_test(tc_others, s21_truncateTest7);
  tcase_add_test(tc_others, s21_truncateTest8);
  tcase_add_test(tc_others, s21_truncateTest9);
  tcase_add_test(tc_others, s21_truncateTest10);
  tcase_add_test(tc_others, s21_truncateTest11);

  //negate
  tcase_add_test(tc_others, s21_negate_1);
  tcase_add_test(tc_others, s21_negate_2);
  tcase_add_test(tc_others, s21_negate_3);

  //int_to_dec

  tcase_add_test(tc_others, int_to_dec_1);
  tcase_add_test(tc_others, int_to_dec_2);
  tcase_add_test(tc_others, int_to_dec_3);
  tcase_add_test(tc_others, int_to_dec_4);
  tcase_add_test(tc_others, int_to_dec_5);
  tcase_add_test(tc_others, int_to_dec_6);
  tcase_add_test(tc_others, int_to_dec_7);
  tcase_add_test(tc_others, int_to_dec_8);
  tcase_add_test(tc_others, int_to_dec_9);
  tcase_add_test(tc_others, int_to_dec_10);
  tcase_add_test(tc_others, int_to_dec_11);
  tcase_add_test(tc_others, int_to_dec_12);
  tcase_add_test(tc_others, int_to_dec_13);
  tcase_add_test(tc_others, int_to_dec_14);
  tcase_add_test(tc_others, int_to_dec_15);
  tcase_add_test(tc_others, int_to_dec_16);
  tcase_add_test(tc_others, int_to_dec_17);
  tcase_add_test(tc_others, int_to_dec_18);
  tcase_add_test(tc_others, int_to_dec_19);
  tcase_add_test(tc_others, int_to_dec_20);
  tcase_add_test(tc_others, int_to_dec_21);

  //dec_to_int

  //tcase_add_test(tc_others, dec_to_int_1);
  tcase_add_test(tc_others, dec_to_int_2);
  tcase_add_test(tc_others, dec_to_int_3);
  tcase_add_test(tc_others, dec_to_int_4);
  tcase_add_test(tc_others, dec_to_int_5);
  tcase_add_test(tc_others, dec_to_int_7);
  tcase_add_test(tc_others, dec_to_int_8);
  tcase_add_test(tc_others, dec_to_int_9);
  tcase_add_test(tc_others, dec_to_int_10);
  tcase_add_test(tc_others, dec_to_int_11);
  tcase_add_test(tc_others, dec_to_int_12);
  tcase_add_test(tc_others, dec_to_int_13);
  tcase_add_test(tc_others, dec_to_int_14);
  tcase_add_test(tc_others, dec_to_int_15);
  tcase_add_test(tc_others, dec_to_int_16);
  tcase_add_test(tc_others, dec_to_int_17);
  tcase_add_test(tc_others, dec_to_int_18);
  tcase_add_test(tc_others, dec_to_int_19);
  tcase_add_test(tc_others, dec_to_int_20);
  tcase_add_test(tc_others, dec_to_int_21);
  tcase_add_test(tc_others, dec_to_int_23);
  tcase_add_test(tc_others, dec_to_int_24);

// dec_to_float

  
  //float_to_decimal

  // tcase_add_test(tc_others, s21_from_float_to_decimal_1);
  // tcase_add_test(tc_others, s21_from_float_to_decimal_2);
  // tcase_add_test(tc_others, s21_from_float_to_decimal_3);  // illegal instruction
  // tcase_add_test(tc_others, s21_from_float_to_decimal_4);
  // tcase_add_test(tc_others, s21_from_float_to_decimal_5);  // everlasting cycle
  // tcase_add_test(tc_others, s21_from_float_to_decimal_6); // everlasting cycle
  // tcase_add_test(tc_others, s21_from_float_to_decimal_7);
  

  srunner_add_suite(sr, save_v2);
}