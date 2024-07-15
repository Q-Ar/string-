#include <check.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../s21_string.h"

int count_func();  // подсчёт выполняемых итераций в тестах s21_sprintf()
Suite *test_s21_sprintf();  // набор тестов для s21_sprintf()
Suite *test_s21_string();  // набор тестов для остальных функций s21_string
