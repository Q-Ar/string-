#include "s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  unsigned char *byte1 = (unsigned char *)str1;
  unsigned char *byte2 = (unsigned char *)str2;
  while (n-- > 0) {
    if (*byte1 != *byte2) {
      return (*byte1 - *byte2);
    }
    byte1++;
    byte2++;
  }
  return 0;
}