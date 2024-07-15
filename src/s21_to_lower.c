#include "s21_string.h"

void *s21_to_lower(const char *str) {
  char *new_str = s21_NULL;
  if (str) {
    new_str = (char *)calloc((s21_strlen(str) + 1), sizeof(char));
  }
  if (new_str) {
    s21_strncpy(new_str, str, s21_strlen(str) + 1);
    for (char *i = new_str; *i; i++) {
      if (*i >= 'A' && *i <= 'Z' && *i != '\0') {
        *i += 32;
      }
    }
  }
  return (void *)new_str;
}