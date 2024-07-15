#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *pos = s21_NULL;
  char *chaystack = (char *)haystack;
  int len_hay = s21_strlen(haystack);
  int len_need = s21_strlen(needle);
  int k = 0;
  int flag = 0;
  for (int i = 0; i < len_hay; i++) {
    flag = 0;
    k = i;
    for (int j = 0; j < len_need; j++) {
      if (haystack[k] != needle[j]) {
        flag = 1;
        break;
      }
      k++;
    }
    if (flag == 0) {
      pos = &chaystack[i];
      break;
    }
  }
  return pos;
}