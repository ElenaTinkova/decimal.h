#include "s21_dec_tests.h"

//-----------Арифметика-----------//

//коды ошибок: 
//0 - OK
//1 - число слишком велико или равно бесконечности
//2 - число слишком мало или равно отрицательной бесконечности
//3 - деление на 0

// add function
START_TEST(s21_add_test_1) {
  s21_decimal value_1 = {2, 0, 0, 0};
  s21_decimal value_2 = {3, 0, 0, 0};
  s21_decimal result = {0};
  s21_decimal check = {5, 0, 0, 0};
  s21_add(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_2) {
  s21_decimal value_1 = {2, 0, 0, 0b10000000000000000000000000000000};
  s21_decimal value_2 = {3, 0, 0, 0};
  s21_decimal result = {0};
  s21_decimal check = {1, 0, 0, 0b00000000000000000000000000000000};
  s21_add(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_3) {
  s21_decimal value_1 = {2, 0, 0, 0};
  s21_decimal value_2 = {3, 0, 0, 0b10000000000000000000000000000000};
  s21_decimal result = {0};
  s21_decimal check = {1, 0, 0, 0b10000000000000000000000000000000};
  s21_add(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

START_TEST(s21_add_test_4) {
  s21_decimal value_1 = {2, 0, 0, 0b10000000000000000000000000000000};
  s21_decimal value_2 = {3, 0, 0, 0b10000000000000000000000000000000};
  s21_decimal result = {0};
  s21_decimal check = {5, 0, 0, 0b10000000000000000000000000000000};
  s21_add(value_1, value_2, &result);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

void srunner_add_math_tests(SRunner *sr) {
  Suite *save_v1 = suite_create("Math");
  TCase *tc_math = tcase_create("Math");
  suite_add_tcase(save_v1, tc_math);

  //add func
  tcase_add_test(tc_math, s21_add_test_1);
  tcase_add_test(tc_math, s21_add_test_2);
  tcase_add_test(tc_math, s21_add_test_3);
  tcase_add_test(tc_math, s21_add_test_4);
  
  srunner_add_suite(sr, save_v1);
}