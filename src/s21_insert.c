#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  short error = 0;
  s21_size_t len_str = -1, len_src = -1;
  if (src && str) {
    len_str = 0;
    len_src = 0;
    while (src[len_src] != '\0') len_src++;
    while (str[len_str] != '\0') len_str++;
  } else
    error = 1;
  char *string = s21_NULL;
  if (!error && start_index <= len_src) {
    while (!string) {
      string = malloc(len_str + len_src + 1);
    }
    s21_size_t i, j, k;
    for (i = 0, j = 0, k = 0; k < len_str + len_src; k++) {
      if (i != start_index || j >= len_str) {
        string[k] = src[i];
        i++;
      } else if (i == start_index && j < len_str) {
        string[k] = str[j];
        j++;
      }
    }
    string[k] = '\0';
  }
  return string;
}