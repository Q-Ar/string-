#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *pos;
  if (str == 0) {
    str = pos;
  }
  while (s21_strchr(delim, *str)) {
    if (*str == '\0') {
      return 0;
    }
    str++;
  }
  pos = str + s21_strcspn(str, delim);
  if (*pos != 0) {
    *pos = 0;
    pos++;
  }
  return str;
}