#include "s21_dec_tests.h"

//-----------Другие функции-----------//

//десятичные числа в диапазоне от положительных 79,228,162,514,264,337,593,543,950,335 до отрицательных

//коды ошибок: 
// 0 - OK
// 1 - ошибка вычисления

// floor function
START_TEST(s21_floor_test_1) { // 2 + 3 = 5
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{5, 0, 0, 0}};
  ck_assert_int_eq((s21_add(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
} 
END_TEST


// round function
START_TEST(s21_round_test_1) { // 2 - 3 = -1
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{1, 0, 0, 0b10000000000000000000000000000000}};
  ck_assert_int_eq((s21_sub(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST


// truncate function
START_TEST(s21_truncate_test_1) { // 2 * 3 = 6
  s21_decimal value_1 = {{2, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{6, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_mul(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST


// negate function
START_TEST(s21_negate_test_1) { // 6 : 3 = 2
  s21_decimal value_1 = {{6, 0, 0, 0}};
  s21_decimal value_2 = {{3, 0, 0, 0}};
  s21_decimal result = {0};
  s21_decimal check = {{2, 0, 0, 0b00000000000000000000000000000000}};
  ck_assert_int_eq((s21_div(value_1, value_2, &result)), 0);
  ck_assert_int_eq(result.bits[0], check.bits[0]);
  ck_assert_int_eq(result.bits[1], check.bits[1]);
  ck_assert_int_eq(result.bits[2], check.bits[2]);
  ck_assert_int_eq(result.bits[3], check.bits[3]);
}
END_TEST

void srunner_add_others_tests(SRunner *sr) {
  Suite *save_v2 = suite_create("Others");
  TCase *tc_others = tcase_create("Others");
  suite_add_tcase(save_v2, tc_others);

  //floor
  tcase_add_test(tc_others, s21_floor_test_1);
  //round
  tcase_add_test(tc_others, s21_round_test_1);
  //truncate
  tcase_add_test(tc_others, s21_truncate_test_1);
  //negate
  tcase_add_test(tc_others, s21_negate_test_1);
  

  srunner_add_suite(sr, save_v2);
}