#include "tests.h"

int count_func() {
  static int count = 0;
  count++;
  return count;
}
/////// Тесты для целых чисел

START_TEST(d_1_v_formate) {  // вариации положения в строке формата
  int d[] = {0, -100, 100, 1, -1, 12345, -12345, 32000, -32000}, count = 0,
      i = 0;  // массив тестовых даных, кол-во тестов
  char format[4][8] = {"%d", "%d!", "!%d!", "!%d"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 9; j++, i++) {
    (i > 3) ? i = 0 : i;
    sprintf(rez_exp, format[i], d[j]);
    s21_sprintf(rez_act, format[i], d[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - d_1:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - d_1:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8d; \"%s|%s\"\n", format[i], d[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(9, count);
}
END_TEST

START_TEST(d_2_flag) {  // вариации флагов
  int d[] = {0, -100, 100, 1, -1, 12345, -12345, 32000, -32000}, count = 0,
      i = 0;  // массив тестовых даных, кол-во тестов
  char format[3][8] = {"%-d", "% d", "%+d"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 9; j++, i++) {
    (i > 2) ? i = 0 : i;
    sprintf(rez_exp, format[i], d[j]);
    s21_sprintf(rez_act, format[i], d[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - d_2:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - d_2:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8d; \"%s|%s\"\n", format[i], d[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(9, count);
}
END_TEST

START_TEST(d_3_width) {  // вариации ширины
  int d[] = {0, -100, 100, 1, -1, 12345, -12345, 32000, -32000}, count = 0,
      i = 0;  // массив тестовых даных, кол-во тестов
  char format[5][8] = {"%0d", "%4d", "%5d", "%1d", "%-10d"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 9; j++, i++) {
    (i > 4) ? i = 0 : i;
    sprintf(rez_exp, format[i], d[j]);
    s21_sprintf(rez_act, format[i], d[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - d_3:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - d_3:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8d; \"%s|%s\"\n", format[i], d[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(9, count);
}
END_TEST

START_TEST(d_4_accuracy) {  // вариации точности
  int d[] = {0, -100, 100, 1, -1, 12345, -12345, 32000, -32000}, count = 0,
      i = 0;  // массив тестовых даных, кол-во тестов
  char format[5][8] = {"%.0d", "%.4d", "%.5d", "%.1d",
                       "%.10d"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 9; j++, i++) {
    (i > 4) ? i = 0 : i;
    sprintf(rez_exp, format[i], d[j]);
    s21_sprintf(rez_act, format[i], d[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - d_4:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - d_4:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8d; \"%s|%s\"\n", format[i], d[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(9, count);
}
END_TEST

START_TEST(d_5_length) {  // вариации длины
  int d[] = {0, -100, 100, 1, -1, 12345, -12345, 32000, -32000}, count = 0,
      i = 0;  // массив тестовых даных, кол-во тестов
  char format[2][8] = {"%hd", "%ld"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 9; j++, i++) {
    (i > 1) ? i = 0 : i;
    sprintf(rez_exp, format[i], d[j]);
    s21_sprintf(rez_act, format[i], d[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - d_5:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - d_5:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8d; \"%s|%s\"\n", format[i], d[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(9, count);
}
END_TEST

/////// Тесты для беззнаковых целых чисел

START_TEST(u_1_v_formate) {  // вариации положения в строке формата
  unsigned int u[] = {0, -100, 100, 1, -1, 12345, -12345, 32000, -32000},
               count = 0, i = 0;  // массив тестовых даных, кол-во тестов
  char format[4][5] = {"%u", "%u!", "!%u!", "!%u"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 9; j++, i++) {
    (i > 3) ? i = 0 : i;
    sprintf(rez_exp, format[i], u[j]);
    s21_sprintf(rez_act, format[i], u[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - u_1:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - u_1:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8d; \"%s|%s\"\n", format[i], u[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(9, count);
}
END_TEST

START_TEST(u_2_flag) {  // вариации флагов
  unsigned int u[] = {0, -100, 100, 1, -1, 12345, -12345, 32000, -32000},
               count = 0, i = 0;  // массив тестовых даных, кол-во тестов
  char format[3][8] = {"%-u!", "% u!", "%+u!"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 9; j++, i++) {
    (i > 2) ? i = 0 : i;
    sprintf(rez_exp, format[i], u[j]);
    s21_sprintf(rez_act, format[i], u[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - u_2:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - u_2:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8d; \"%s|%s\"\n", format[i], u[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(9, count);
}
END_TEST

START_TEST(u_3_width) {  // вариации ширины
  unsigned int u[] = {0, -100, 100, 1, -1, 12345, -12345, 32000, -32000},
               count = 0, i = 0;  // массив тестовых даных, кол-во тестов
  char format[5][8] = {"%0u!", "%4u!", "%5u!", "%1u!",
                       "%10u!"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 9; j++, i++) {
    (i > 4) ? i = 0 : i;
    sprintf(rez_exp, format[i], u[j]);
    s21_sprintf(rez_act, format[i], u[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - u_3:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - u_3:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8d; \"%s|%s\"\n", format[i], u[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(9, count);
}
END_TEST

START_TEST(u_4_accuracy) {  // вариации точности
  unsigned int u[] = {0, -100, 100, 1, -1, 12345, -12345, 32000, -32000},
               count = 0, i = 0;  // массив тестовых даных, кол-во тестов
  char format[5][8] = {"%.0u!", "%.4u!", "%.5u!", "%.1u!", "%.10u!"};
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 9; j++, i++) {
    (i > 4) ? i = 0 : i;
    sprintf(rez_exp, format[i], u[j]);
    s21_sprintf(rez_act, format[i], u[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - u_4:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - u_4:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8d; \"%s|%s\"\n", format[i], u[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(9, count);
}
END_TEST

START_TEST(u_5_length) {  // вариации длины
  unsigned int u[] = {0, -100, 100, 1, -1, 12345, -12345, 32000, -32000},
               count = 0, i = 0;  // массив тестовых даных, кол-во тестов
  char format[2][8] = {"%hu", "%lu"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 9; j++, i++) {
    (i > 1) ? i = 0 : i;
    sprintf(rez_exp, format[i], u[j]);
    s21_sprintf(rez_act, format[i], u[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - u_5:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - u_5:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8d; \"%s|%s\"\n", format[i], u[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(9, count);
}
END_TEST

/////// Тесты для вещественных чисел

START_TEST(f_1_v_formate) {  // вариации положения в строке формата
  float f[] = {0.0, 0.0001, -0.0001, 0.67, -0.67, 0.33,    -0.33,
               1.0, 8.5,    -1.0,    33.0, -33.0, 123.125, -123.125};
  short count = 0, i = 0;  // массив тестовых даных, кол-во тестов
  char format[4][5] = {"%f", "%f!", "!%f!", "!%f"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 14; j++, i++) {
    (i > 3) ? i = 0 : i;
    sprintf(rez_exp, format[i], f[j]);
    s21_sprintf(rez_act, format[i], f[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - f_1:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - f_1:[%2d]: ", count_func());
    printf("format: %-7s znach: %f; \"%s|%s\"\n", format[i], f[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(14, count);
}
END_TEST

START_TEST(f_2_flag) {  // вариации флагов
  float f[] = {0.0, 0.0001, -0.0001, 0.67, -0.67, 0.33,    -0.33,   1.0,
               8.7, -77.34, -1.0,    33.0, -33.0, 123.456, -123.456};
  short count = 0, i = 0;  // массив тестовых даных, кол-во тестов
  char format[3][8] = {"!%-f!", "!% f!", "!%+f!"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 15; j++, i++) {
    (i > 2) ? i = 0 : i;
    sprintf(rez_exp, format[i], f[j]);
    s21_sprintf(rez_act, format[i], f[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - f_2:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - f_2:[%2d]: ", count_func());
    printf("format: %-7s znach: %f; \"%s|%s\"\n", format[i], f[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(15, count);
}
END_TEST

START_TEST(f_3_width) {  // вариации ширины
  float f[] = {0.0, 0.0001, -0.0001, 0.67, -0.67, 0.33,    -0.33,           1.0,
               8.7, -77.34, -1.0,    33.0, -33.0, 123.456, -1232345.4364443};
  short count = 0, i = 0;  // массив тестовых даных, кол-во тестов
  char format[5][8] = {"!%0f!", "!%4f!", "!%5f!", "!%1f!",
                       "!%10f!"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 15; j++, i++) {
    (i > 4) ? i = 0 : i;
    sprintf(rez_exp, format[i], f[j]);
    s21_sprintf(rez_act, format[i], f[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - f_3:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - f_3:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8f; \"%s|%s\"\n", format[i], f[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(15, count);
}
END_TEST

START_TEST(f_4_accuracy) {  // вариации точности
  float f[] = {0.0, 0.0001, -0.0001, 0.67, -0.67, 0.33,    -0.33,   1.0,
               8.7, -77.34, -1.0,    33.0, -33.0, 123.456, -123.456};
  short count = 0, i = 0;  // массив тестовых даных, кол-во тестов
  char format[5][8] = {"!%.0f!", "!%.4f!", "!%.5f!", "!%.1f!",
                       "!%.10f!"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 15; j++, i++) {
    (i > 4) ? i = 0 : i;
    sprintf(rez_exp, format[i], f[j]);
    s21_sprintf(rez_act, format[i], f[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - f_4:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - f_4:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8f; \"%s|%s\"\n", format[i], f[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(15, count);
}
END_TEST

START_TEST(f_5_length) {  // вариации длины
  float f[] = {0.0, 0.0001, -0.0001, 0.67, -0.67, 0.33,    -0.33,   1.0,
               8.7, -77.34, -1.0,    33.0, -33.0, 123.456, -123.456};
  short count = 0, i = 0;  // массив тестовых даных, кол-во тестов
  char format[2][8] = {"%hf", "%lf"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 15; j++, i++) {
    (i > 1) ? i = 0 : i;
    sprintf(rez_exp, format[i], f[j]);
    s21_sprintf(rez_act, format[i], f[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - f_5:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - f_5:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8f; \"%s|%s\"\n", format[i], f[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(15, count);
}
END_TEST

/////// Тесты для символов

START_TEST(c_1_procent_v_formate) {
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  sprintf(rez_exp, "%%");
  s21_sprintf(rez_act, "%%");
  if (strcmp(rez_exp, rez_act) == 0) {
    printf("PASS   - c_1:[%2d]: ", count_func());
  } else
    printf("  FAIL - c_1:[%2d]: ", count_func());
  printf("\"%s|%s\"\n", rez_exp, rez_act);
  ck_assert_str_eq(rez_exp, rez_act);
}
END_TEST

START_TEST(c_2_v_formate) {  // "%c"
  char c[] = {'a', '+', 'V', ' ', ' '};
  short count = 0, i = 0;  // массив тестовых даных, кол-во тестов
  char format[4][5] = {"%c", "%c!", "!%c!", "!%c"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 5; j++, i++) {
    (i > 4) ? i = 0 : i;
    sprintf(rez_exp, format[i], c[j]);
    s21_sprintf(rez_act, format[i], c[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - c_2:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - c_2:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8c; \"%s|%s\"\n", format[i], c[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(5, count);
}
END_TEST

START_TEST(c_3_flag) {  // вариации флагов
  char c[] = {'a', '+', 'V', ' ', ' '};
  short count = 0, i = 0;  // массив тестовых даных, кол-во тестов
  char format[3][8] = {"!%-c", "!% c", "!%+c"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 5; j++, i++) {
    (i > 2) ? i = 0 : i;
    sprintf(rez_exp, format[i], c[j]);
    s21_sprintf(rez_act, format[i], c[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - c_3:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - c_3:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8c; \"%s|%s\"\n", format[i], c[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(5, count);
}
END_TEST

START_TEST(c_4_width) {  // вариации ширины
  char c[] = {'a', '+', 'V', ' ', ' '};
  short count = 0, j = 0;  // массив тестовых даных, кол-во тестов
  char format[5][8] = {"!%0c", "!%4c", "!%5c", "!%1c",
                       "!%10c"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short i = 0; i < 5; i++, j++) {
    (j > 4) ? j = 0 : j;
    sprintf(rez_exp, format[i], c[j]);
    s21_sprintf(rez_act, format[i], c[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - c_4:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - c_4:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8c; \"%s|%s\"\n", format[i], c[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(5, count);
}
END_TEST

START_TEST(c_5_accuracy) {  // вариации точности
  char c[] = {'a', '+', 'V', ' ', ' '};
  short count = 0, j = 0;  // массив тестовых даных, кол-во тестов
  char format[5][8] = {"!%.0c", "!%.4c", "!%.5c", "!%.1c",
                       "!%.10c"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short i = 0; i < 5; i++, j++) {
    (j > 4) ? j = 0 : j;
    sprintf(rez_exp, format[i], c[j]);
    s21_sprintf(rez_act, format[i], c[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - c_5:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - c_5:[%2d]: ", count_func());
    printf("format: %-7s znach: %-8c; \"%s|%s\"\n", format[i], c[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(5, count);
}
END_TEST

/////// Тесты для строк

START_TEST(s_1_v_formate) {
  char s[5][15] = {"", "1", "abcd", "Hello World!"};
  short count = 0, i = 0;  // массив тестовых даных, кол-во тестов
  char format[4][5] = {"%s", "%s!", "!%s!", "!%s"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 4; j++, i++) {
    (i > 3) ? i = 0 : i;
    sprintf(rez_exp, format[i], s[j]);
    s21_sprintf(rez_act, format[i], s[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - s_1:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - s_1:[%2d]: ", count_func());
    printf("format: %-7s znach: %s; \"%s|%s\"\n", format[i], s[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(4, count);
}
END_TEST

START_TEST(s_2_flag) {  // вариации флагов
  char s[5][15] = {"", "1", "abcd", "Hello World!"};
  short count = 0, i = 0;  // массив тестовых даных, кол-во тестов
  char format[3][8] = {"%-s", "% s", "%+s"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short j = 0; j < 4; j++, i++) {
    (i > 2) ? i = 0 : i;
    sprintf(rez_exp, format[i], s[j]);
    s21_sprintf(rez_act, format[i], s[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - s_2:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - s_2:[%2d]: ", count_func());
    printf("format: %-7s znach: %s; \"%s|%s\"\n", format[i], s[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(4, count);
}
END_TEST

START_TEST(s_3_width) {  // вариации ширины
  char s[5][15] = {"", "1", "abcd", "Hello World!"};
  short count = 0, j = 0;  // массив тестовых даных, кол-во тестов
  char format[5][8] = {"%0s", "%4s", "%5s", "%1s", "%10s"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short i = 0; i < 5; i++, j++) {
    (j > 3) ? j = 0 : j;
    sprintf(rez_exp, format[i], s[j]);
    s21_sprintf(rez_act, format[i], s[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - s_3:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - s_3:[%2d]: ", count_func());
    printf("format: %-7s znach: %s; \"%s|%s\"\n", format[i], s[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(5, count);
}
END_TEST

START_TEST(s_4_accuracy) {  // вариации точности
  char s[4][15] = {"", "1", "abcd", "Hello World!"};
  short count = 0, j = 0;  // массив тестовых даных, кол-во тестов
  char format[20][8] = {"%.0s", "%.4s", "%.5s", "%.1s",
                        "%.10s"};  // массив форматов
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  for (short i = 0; i < 5; i++, j++) {
    (j > 4) ? j = 0 : j;
    sprintf(rez_exp, format[i], s[j]);
    s21_sprintf(rez_act, format[i], s[j]);
    if (strcmp(rez_exp, rez_act) == 0) {
      printf("PASS   - s_4:[%2d]: ", count_func());
      count++;
    } else
      printf("  FAIL - s_4:[%2d]: ", count_func());
    printf("format: %-7s znach: %s; \"%s|%s\"\n", format[i], s[j], rez_exp,
           rez_act);
  }
  ck_assert_int_eq(5, count);
}
END_TEST

START_TEST(integration) {
  char s[] = "Hello";
  int d = -123;
  float f = 5.6754;
  char format[] = "%.2s*%-d!%3f";  // формат
  char rez_exp[255] = "",
       rez_act[255] = "";  // ожидаемый результат и фактический
  sprintf(rez_exp, format, s, d, f);
  s21_sprintf(rez_act, format, s, d, f);
  if (strcmp(rez_exp, rez_act) == 0) {
    printf("PASS   - integration: ");
  } else
    printf("  FAIL - integration: ");
  printf("format: %s  \"%s|%s\"\n", format, rez_exp, rez_act);
  ck_assert_str_eq(rez_exp, rez_act);
}
END_TEST

Suite *test_s21_sprintf() {  // функция создания тестового набора
  TCase *tcase_d = tcase_create("TestCase_d");  // тест-кейс целых чисел
  TCase *tcase_u =
      tcase_create("TestCase_u");  // тест-кейс беззнаковых целых чисел
  TCase *tcase_f = tcase_create("TestCase_f");  // тест-кейс вещественных чисел
  TCase *tcase_c = tcase_create("TestCase_c");  // тест-кейс символов
  TCase *tcase_s = tcase_create("TestCase_s");  // тест-кейс строк

  tcase_add_test(tcase_d, d_1_v_formate);  // тесты для целых чисел
  tcase_add_test(tcase_d, d_2_flag);
  tcase_add_test(tcase_d, d_3_width);
  tcase_add_test(tcase_d, d_4_accuracy);
  tcase_add_test(tcase_d, d_5_length);

  tcase_add_test(tcase_u, u_1_v_formate);  // тесты для беззнаковых целых чисел
  tcase_add_test(tcase_u, u_2_flag);
  tcase_add_test(tcase_u, u_3_width);
  tcase_add_test(tcase_u, u_4_accuracy);
  tcase_add_test(tcase_u, u_5_length);

  tcase_add_test(tcase_f, f_1_v_formate);  // тесты для вещественных чисел
  tcase_add_test(tcase_f, f_2_flag);
  tcase_add_test(tcase_f, f_3_width);
  tcase_add_test(tcase_f, f_4_accuracy);
  tcase_add_test(tcase_f, f_5_length);

  tcase_add_test(tcase_c, c_1_procent_v_formate);  // тесты для %
  tcase_add_test(tcase_c, c_2_v_formate);  // тесты для символов
  tcase_add_test(tcase_c, c_3_flag);
  tcase_add_test(tcase_c, c_4_width);
  tcase_add_test(tcase_c, c_5_accuracy);

  tcase_add_test(tcase_s, s_1_v_formate);  // тесты для строк
  tcase_add_test(tcase_s, s_2_flag);
  tcase_add_test(tcase_s, s_3_width);
  tcase_add_test(tcase_s, s_4_accuracy);
  tcase_add_test(tcase_s, integration);

  Suite *suite =
      suite_create("s21_sprintf_suite");  // создали объект тестового набора
  suite_add_tcase(suite, tcase_d);  // добавили в объект тест-кейса тест
  suite_add_tcase(suite, tcase_u);
  suite_add_tcase(suite, tcase_f);
  suite_add_tcase(suite, tcase_c);
  suite_add_tcase(suite, tcase_s);

  return suite;
}