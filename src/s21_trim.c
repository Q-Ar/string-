#include "s21_string.h"

short get_left(const char *src, const char *trim_chars);
short get_right(const char *src, const char *trim_chars);

void *s21_trim(const char *src, const char *trim) {
  short i, j;
  char *string = s21_NULL;
  char trim_space[] = " ";
  const char *trim_chars = trim;
  if (src) {
    if (trim_chars == NULL || s21_strlen(trim_chars) == 0) {
      trim_chars = trim_space;
    }
    short len_src = s21_strlen(src);
    if (len_src == 0) {
      while (string == s21_NULL) string = malloc(1);
      string[0] = '\0';
    } else {
      short left = get_left(src, trim_chars);
      short right = get_right(src, trim_chars);
      while (string == s21_NULL) {
        string = malloc(len_src + 1);
      }
      if (right == -1)
        string[0] = '\0';
      else {
        for (i = left, j = 0; i <= right; i++, j++) string[j] = src[i];
        string[j] = '\0';
      }
    }
  }
  return string;
}

short get_left(const char *src, const char *trim_chars) {
  short get_trim = 0;
  short get_poz = -1;
  short len_src = s21_strlen(src);
  short len_trim = s21_strlen(trim_chars);
  for (short i = 0; i < len_src; i++) {
    get_trim = 0;
    for (short k = 0; k < len_trim; k++) {
      if (src[i] == trim_chars[k]) {
        get_trim = 1;
        break;
      }
    }
    if (!get_trim) {
      get_poz = i;
    }
    if (get_poz != -1) break;
  }
  return get_poz;
}

short get_right(const char *src, const char *trim_chars) {
  short get_trim = 0;
  short get_poz = -1;
  short len_src = s21_strlen(src);
  short len_trim = s21_strlen(trim_chars);
  for (short i = len_src - 1; i >= 0; i--) {
    get_trim = 0;
    for (short k = 0; k < len_trim; k++) {
      if (src[i] == trim_chars[k]) {
        get_trim = 1;
        break;
      }
    }
    if (!get_trim) {
      get_poz = i;
    }
    if (get_poz != -1) break;
  }
  return get_poz;
}
