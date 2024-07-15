#include <stdarg.h>

#include "s21_string.h"

#define FLAGS 6
// FLAGS - размер массива для шаблонов спецификаторов
#define SPEC 25
// SPEC - размер строки на спецификатор

union data {  // объединение для значения параметра
  char c;
  long int d;
  double f;
  char *s;
  long unsigned int u;
};

enum param { c, d, f, s, u };  // перечисление для спецификаторов

struct set {
  char *str_change;  // промежуточная строка для преобразований
  union data value;  // объединение для значения параметра
  enum param spec;  // перечисление для спецификаторов
  char specif_compare[FLAGS];  // массив для сравнения спецификаторов
  char modif_value;  // символ модификатора
  short count_change;  // количество найденных спецификаторов
  char **mass_change;  // двумерный массив строк спецификаторов
  short *mass_poz;  // массив позиций для вставки значений по спецификаторам
  char flag_compare[3];  // массив сравнения для флагов в спецификаторе
  short mass_flag[3];    // массив отмеченных флагов
  short width;           // ширина в спецификаторе
  short accuracy;        // точность в спецификаторе
};

struct set *new_set();  // создание структуры
char *z_string(const char *s);  // Преобразование строки в z-строку

void format_parser(char *format, short i,
                   struct set *setting);  // выделение подстрок спецификаторов
void write_change(struct set *setting);  // Запись в дин массив спецификатора
void write_poz_change(struct set *setting,
                      short j);  // запись в массив позиции вставки

void transform_str(struct set *setting, char *medium_str, char *rezult_str,
                   va_list args);  // составление результирующей строки

void parce_display(struct set *setting,
                   short k);  // парсинг строки спецификатора
void value_param(struct set *setting, short k,
                 va_list args);  // записываем переменный параметр в объединение
                                 // и перечисление
void value_to_str(struct set *setting);  // преобразуем значение в строку
void char_to_str(struct set *setting);  // преобразование символа в строку
void int_to_str(struct set *setting);  // преобразование числа в строку
void float_to_str(
    struct set *setting);  // преобразование вещественного в строку
void part_to_str(long int *a, char *str,
                 short r);  // преобразование частей float в str
char flag_symbol(
    struct set *setting,
    short sign);  // определение символа в начале в зависимости от флага и знака
void shift_str(struct set *setting, short since,
               char symbol_sign);  // сдвиг str_change вправо на since символов
                                   // и вставка symbol_sign

void str_to_str(struct set *setting);  // преобразование строки в строку
void unint_to_str(
    struct set *setting);  // преобразование беззнакового целого в строку
void width_modif(struct set *setting);  // применение ширины к строке
void revers_string(char *str_rez, char *source);  // переворот строки
void write_str(char *rezult_str, short *j,
               char *str);  // вставка подстроки в строку
void clean_value_param(
    struct set *setting);  // очистка параметров в структуре после спецификатора
void free_set(struct set *setting);  // очистка структуры

int s21_sprintf(char *str, const char *format, ...) {
  struct set *setting = new_set();  // структура для параметров
  char *k = s21_NULL;
  while (k == s21_NULL) k = (char *)malloc(255);
  char *rezult_str = k;  // результирующая строка
  k = s21_NULL;
  while (k == s21_NULL) k = (char *)malloc(255);
  char *medium_str = k;  // выделяем место для промежуточной строки
  char *format_str = z_string(format);  // преобразуем формат в з-строку
  va_list args;  // Создание списка параметров для переменного списка аргументов
  va_start(args,
           format);  // инициализация списка аргументов с последнего известного
  va_list args_copy;  // объявление копии списка переменных параметров
  va_copy(args_copy, args);  // создание копии списка параметров
  medium_str[0] = 0;
  short i, j;
  for (i = 1, j = 1; i <= (short)format_str[0];) {  //
    if (format_str[i] != '%') {
      medium_str[j] = format_str[i];  // печатаем всё, что не спецификаторы
      medium_str[0]++;  // каждый раз при простом переносе символа - увеличиваем
                        // размер строки
      j++;
      i++;
    } else {
      format_parser(format_str, i,
                    setting);  // получили из текущего места строки спецификатор
      write_change(setting);  // записываем строчку в массив динамический
      write_poz_change(setting,
                       j - 1);  // записываем в дин массив последний символ
                                // новой строки, после которого печатать
      i += setting->str_change[0] + 1;
    }
  }
  medium_str[j] = '\0';
  transform_str(setting, medium_str, rezult_str,
                args_copy);  // формирование итоговой строки
  for (short i = 1, j = 0; i <= rezult_str[0];
       i++, j++)  // переписываем итог в обычную строку
    str[j] = rezult_str[i];
  str[(short)rezult_str[0]] = '\0';
  short count = rezult_str[0];
  free_set(setting);
  va_end(args);  // завершение работы со списком
  va_end(args_copy);
  free(format_str);
  format_str = s21_NULL;
  free(medium_str);
  medium_str = s21_NULL;
  free(rezult_str);
  rezult_str = s21_NULL;
  return count;
}

struct set *new_set() {  // функция создания структуры
  struct set *new_setting = s21_NULL;
  char flags[] = {'+', ' ', '-'};
  char specif[] = {'c', 'd', 'f', 's', 'u', '%'};
  while (new_setting == s21_NULL)
    new_setting = malloc(sizeof(struct set));  // Память под новую структуру
  new_setting->str_change = s21_NULL;
  while (new_setting->str_change == s21_NULL)
    new_setting->str_change = malloc(255);  // Память под временную строку
  for (short i = 0; i < FLAGS; i++) {
    new_setting->specif_compare[i] =
        specif[i];  // Массив шаблон в структуре заполняем
  }
  new_setting->modif_value = '0';
  for (short i = 0; i < 3; i++) {
    new_setting->mass_flag[i] = 0;  // обнуление массива для флагов
    new_setting->flag_compare[i] =
        flags[i];  // массив сравнения для флагов в спецификаторе
  }
  new_setting->count_change = 0;  // обнуляем размер дин. массива спецификаторов
  new_setting->mass_change =
      s21_NULL;  // обнуляем указатель на дин массив спецификаторов
  new_setting->mass_poz =
      s21_NULL;  // обнуляем указатель на дин массив позиций вставки
  new_setting->width = -1;     // ширина в спецификаторе
  new_setting->accuracy = -1;  // точность в спецификаторе

  return new_setting;
}

char *z_string(const char *s) {  // преобразует обычную строку в z-строку.
  short len = 0;
  while (s[len] != '\0') len++;
  char *str = (char *)malloc(len + 2);
  str[0] = (char)len;
  for (short i = 0; i < len; i++) str[i + 1] = s[i];
  str[len + 1] = '\0';
  return str;
}

void format_parser(
    char *format_str, short i,
    struct set *setting) {  // выловить подстроку со спецификатором
  setting->str_change[0] = 0;  // длина строки
  short k = i;
  short get_flag = 0;  // флаг, что поймали флаг
  while (!get_flag && format_str[k] != '\0') {
    k++;
    for (short p = 0; p < FLAGS; p++) {
      if (format_str[k] == setting->specif_compare[p]) {
        get_flag = 1;
        break;
      }
    }
  }
  setting->str_change[0] = k - i;  // длина строки со спецификатором
  for (int p = 1; p <= setting->str_change[0]; p++)
    setting->str_change[p] =
        format_str[i + p];  // записываем строку спецификатора в структуру
  setting->str_change[setting->str_change[0] + 1] = '\0';
}

void write_change(
    struct set *setting) {  // записываем значение в динамический массив
  if (setting->str_change) {  // если строка не пустая
    setting->count_change++;
    char **p = s21_NULL;
    char *k = s21_NULL;
    if (setting->count_change == 1) {
      while (p == s21_NULL) p = (char **)malloc(sizeof(char *));
    } else {
      while (p == s21_NULL)
        p = (char **)realloc(setting->mass_change,
                             setting->count_change * sizeof(char *));
    }
    setting->mass_change = p;
    while (k == s21_NULL) k = (char *)malloc(SPEC);
    setting->mass_change[setting->count_change - 1] = k;
    short i;
    for (i = 0; i <= setting->str_change[0];
         i++)  // скопировала строку в дин массив
      setting->mass_change[setting->count_change - 1][i] =
          setting->str_change[i];
    setting
        ->mass_change[setting->count_change - 1][setting->str_change[0] + 1] =
        '\0';
  }
}

void write_poz_change(struct set *setting, short j) {
  short *k = s21_NULL;
  if (setting->count_change == 1) {
    while (k == s21_NULL) k = (short *)malloc(sizeof(short));
  } else {
    while (k == s21_NULL)
      k = (short *)realloc(setting->mass_poz,
                           setting->count_change * sizeof(short));
  }
  setting->mass_poz = k;
  setting->mass_poz[setting->count_change - 1] = j;
}

void transform_str(struct set *setting, char *medium_str, char *rezult_str,
                   va_list args) {
  rezult_str[0] = medium_str[0];
  short i, j, k;
  for (i = 1, j = 1;
       i <=
       medium_str[0] + 1;) {  // проходим по всем элементам промежуточной строки
    for (k = 0; k < setting->count_change;
         k++) {  // проходим по всему массиву позиций
      if (i - 1 == setting->mass_poz[k]) {
        setting->mass_poz[k] =
            -1;  // на случай нескольких последовательных спецификаторов
        parce_display(setting, k);  // достаем всё из спецификатора
        value_param(setting, k,
                    args);  // достаём параметр и заносим в объединение, в
                            // перечислении отмечаем спецификатор
        value_to_str(setting);  // преобразуем значение в строку
        write_str(rezult_str, &j, setting->str_change);
        clean_value_param(setting);  // очищаем установленные параметры с
                                     // прошлого спецификатора
      }
    }
    rezult_str[j] = medium_str[i];
    j++;
    i++;
  }
  rezult_str[j] = '\0';
}

void parce_display(struct set *setting,
                   short k) {  // парсинг строки спецификатора
  short flag_get = 0;  // флаг, что поиск флагов в строке окончен
  short flag_width = 0;  // флаг, что поиск ширины в строке окончен
  short i;
  char c;
  for (i = 1; i <= setting->mass_change[k][0]; i++) {
    c = setting->mass_change[k][i];
    if ((c == '-' || c == ' ' || c == '+') &&
        !flag_get) {  // если в начале стоит флаг - ищем его сравнение и
      for (short j = 0; j < 3; j++) {
        if (c == setting->flag_compare[j]) {  // если совпало с + - или
                                              // пробелом, отмечаем
          setting->mass_flag[j] = 1;
          break;
        }
      }
    } else
      flag_get = 1;
    if (c >= '0' && c <= '9' && !flag_width) {
      if (setting->width == -1)
        setting->width = c - '0';
      else
        setting->width = setting->width * 10 + (c - '0');
    } else if (c == '.')
      flag_width = 1;
    if (c >= '0' && c <= '9' && flag_width == 1) {
      if (setting->accuracy == -1)
        setting->accuracy = c - '0';
      else
        setting->accuracy = setting->accuracy * 10 + (c - '0');
    } else if (c == 'h' || c == 'l')
      flag_width = 2;
    if (c == 'h' || c == 'l') {
      if (c == 'h' && setting->modif_value == '0')
        setting->modif_value = 'h';
      else if (c == 'l' && setting->modif_value == '0')
        setting->modif_value = 'l';
    }
  }
}

void value_param(struct set *setting, short k,
                 va_list args) {  // k - какой спецификатор и параметр берём
  short len = setting->mass_change[k][0];  // длина строки
  if (setting->mass_change[k][len] == '%') {
    setting->spec = c;
    setting->value.c = '%';
  } else if (setting->mass_change[k][len] == 'c') {
    setting->spec = c;
    char c = va_arg(args, int);
    setting->value.c = c;
  } else if (setting->mass_change[k][len] == 'd') {
    setting->spec = d;
    if (setting->modif_value == 'h') {
      int number = va_arg(args, int);
      setting->value.d = (short)number;
    } else if (setting->modif_value == 'l')
      setting->value.d = va_arg(args, long int);
    else
      setting->value.d = va_arg(args, int);
  } else if (setting->mass_change[k][len] == 'f') {
    setting->spec = f;
    setting->value.f = va_arg(args, double);
  } else if (setting->mass_change[k][len] == 's') {
    setting->spec = s;
    char *str = va_arg(args, char *);
    setting->value.s = z_string(str);  // преобразуем строку в z-строку
  } else if (setting->mass_change[k][len] == 'u') {
    setting->spec = u;
    if (setting->modif_value == 'h') {
      unsigned int number = va_arg(args, unsigned int);
      setting->value.u = (short unsigned)number;
    } else if (setting->modif_value == 'l')
      setting->value.u = va_arg(args, long unsigned int);
    else
      setting->value.u = va_arg(args, unsigned int);
  }
}

void value_to_str(struct set *setting) {
  switch (setting->spec) {
    case c: {
      char_to_str(setting);
      break;
    }
    case d: {
      int_to_str(setting);
      break;
    }
    case f: {
      float_to_str(setting);
      break;
    }
    case s: {
      str_to_str(setting);
      break;
    }
    case u: {
      unint_to_str(setting);
      break;
    }
  }
  width_modif(setting);
}

void char_to_str(struct set *setting) {
  setting->str_change[0] = 1;
  setting->str_change[1] = (char)setting->value.c;
  setting->str_change[2] = '\0';
}

void int_to_str(struct set *setting) {
  char s[255];
  short sign = 0;  // флаг для знака числа
  int i = 1;
  if (setting->value.d == 0) {
    if (setting->accuracy == 0) {
      setting->str_change[0] = 0;
      setting->str_change[1] = '\0';
    } else {
      setting->str_change[0] = 1;
      setting->str_change[1] = '0';
      setting->str_change[2] = '\0';
    }
  } else {
    if (setting->value.d < 0) {
      sign = 1;  // знак - = 1
      setting->value.d = -1 * setting->value.d;
    }
    while (setting->value.d % 10 != 0 || setting->value.d / 10 != 0) {
      s[i] = setting->value.d % 10 + '0';
      setting->value.d = setting->value.d / 10;
      i++;
    }
    s[0] = i - 1;
    s[i] = '\0';

    revers_string(setting->str_change, s);  // функция переворота строки
  }

  if (setting->accuracy > 0 && setting->accuracy > setting->str_change[0]) {
    short since = setting->accuracy - setting->str_change[0];
    shift_str(setting, since, '0');
  }

  char symbol_sign =
      flag_symbol(setting, sign);  // знак в начале в зависимости от флага

  if (symbol_sign != '0') {
    shift_str(setting, 1, symbol_sign);
  }
}

void float_to_str(struct set *setting) {
  short round = 6;  // сколько знаков после запятой оставить
  char s2[255] = "";  // хранит целую часть
  char s3[255] = "";  // хранит вещественную часть
  short sign = 0;     // флаг, что есть знак -

  if (setting->accuracy != -1) round = setting->accuracy;

  if (setting->value.f < 0) {  // отметили, если есть знак -
    setting->value.f = -1 * setting->value.f;
    sign = 1;
  }

  for (short i = 0; i < round; i++) {
    setting->value.f *= 10;
  }
  long int a = setting->value.f;
  float b = setting->value.f - a;  // получили вещественную часть
  if (b > 0.5)  // по математике округляем
    a += 1;
  part_to_str(&a, s3, round);  // вещественная часть

  part_to_str(&a, s2, -1);  // целая часть
  short k;
  for (k = 1; k <= s2[0]; k++) setting->str_change[k] = s2[k];
  setting->str_change[0] = s2[0];
  if (s3[0] != 0) {
    setting->str_change[k] = '.';
    setting->str_change[0] += 1;

    for (k = 1; k <= s3[0]; k++)
      setting->str_change[setting->str_change[0] + k] = s3[k];
    setting->str_change[setting->str_change[0] + k] = '\0';
    setting->str_change[0] += s3[0];
  }
  char symbol_sign =
      flag_symbol(setting, sign);  // знак в начале в зависимости от флага

  if (symbol_sign != '0') {
    shift_str(setting, 1, symbol_sign);
  }
}

void part_to_str(long int *a, char *str, short r) {
  char s[255];
  int i = 1;
  if (r == -1) {
    if (*a == 0) {
      i = 2;
      s[1] = '0';
    } else
      while (*a % 10 != 0 || *a / 10 != 0) {
        s[i] = *a % 10 + '0';
        *a /= 10;
        i++;
      }
  } else
    for (i = 1; i <= r;) {
      s[i] = *a % 10 + '0';
      *a /= 10;
      i++;
    }
  s[0] = i - 1;
  s[i] = '\0';

  revers_string(str, s);  // функция переворота строки
}

char flag_symbol(struct set *setting,
                 short sign) {  // определение символа в начале в зависимости от
                                // флага и знака
  char symbol_sign = '0';
  if (sign) {
    symbol_sign = '-';
  } else {
    if (setting->mass_flag[0] &&
        !setting->mass_flag[1]) {  // если + без пробела
      symbol_sign = '+';
    } else if (setting->mass_flag[1] &&
               !setting->mass_flag[0]) {  // если пробел без +
      symbol_sign = ' ';
    }
  }
  return symbol_sign;
}

void shift_str(struct set *setting, short since,
               char symbol_sign) {  // сдвиг str_change вправо на since символов
                                    // и вставка symbol_sign
  short i, j;
  for (i = 0; i < since; i++) {
    for (j = setting->str_change[0]; j > 0; j--) {
      setting->str_change[j + 1] = setting->str_change[j];
    }
    setting->str_change[0] += 1;
    setting->str_change[1] = symbol_sign;
  }
}

void str_to_str(struct set *setting) {  // заносит обычную строку в структуру в
                                        // виде z-строки
  int i;
  if (setting->accuracy != -1 && setting->accuracy < setting->value.s[0]) {
    for (i = 1; i <= setting->accuracy; i++)
      setting->str_change[i] = setting->value.s[i];
    setting->str_change[0] = setting->accuracy;
  } else {
    for (i = 0; i <= setting->value.s[0]; i++)
      setting->str_change[i] = setting->value.s[i];
  }
  setting->str_change[i] = '\0';
  free(setting->value.s);
}

void unint_to_str(struct set *setting) {
  char s[255];
  short i = 1;
  if (setting->value.u == 0) {
    if (setting->accuracy == 0) {
      setting->str_change[0] = 0;
      setting->str_change[1] = '\0';
    } else {
      setting->str_change[0] = 1;
      setting->str_change[1] = '0';
      setting->str_change[2] = '\0';
    }
  } else {
    while (setting->value.u % 10 != 0 || setting->value.u / 10 != 0) {
      s[i] = setting->value.u % 10 + '0';
      setting->value.u /= 10;
      i++;
    }
    s[0] = i - 1;
    s[i] = '\0';

    revers_string(setting->str_change, s);  // функция переворота строки
    if (setting->accuracy > 0 && setting->accuracy > setting->str_change[0]) {
      short since = setting->accuracy - setting->str_change[0];
      shift_str(setting, since, '0');
    }
  }
}

void width_modif(struct set *setting) {
  short count_symbol;
  short i;
  if (setting->width != -1 &&
      setting->width >
          setting
              ->str_change[0]) {  // если длина есть и она больше длины строки
    count_symbol = setting->width -
                   (short)setting->str_change[0];  // сколько символов добавить
    if (setting->mass_flag[2]) {  // если есть -
      for (i = (setting->str_change[0] + 1);
           i <= (setting->str_change[0] + count_symbol); i++)
        setting->str_change[i] = ' ';
      setting->str_change[0] += count_symbol;
      setting->str_change[i] = '\0';
    } else {
      shift_str(setting, count_symbol, ' ');
    }
  }
}

void revers_string(char *str_rez, char *source) {
  str_rez[0] = source[0];
  int i, j;
  for (i = source[0], j = 1; i > 0; i--, j++) str_rez[j] = source[i];
  str_rez[j] = '\0';
}

void write_str(
    char *rezult_str, short *j,
    char *str) {  // функция вставки подстроки в результирующую строку
  short i;
  for (i = 1; i <= str[0];) {
    rezult_str[*j] = str[i];
    *j += 1;
    i++;
    rezult_str[0]++;
  }
}

void clean_value_param(struct set *setting) {
  for (short i = 0; i < 3; i++)
    setting->mass_flag[i] = 0;  // массив отмеченных флагов
  setting->width = -1;          // ширина в спецификаторе
  setting->accuracy = -1;  // точность в спецификаторе
}

void free_set(struct set *setting) {  // функция очистки структуры
  free(setting->str_change);
  for (short i = setting->count_change - 1; i >= 0; i--) {
    free(setting->mass_change[i]);
  }
  free(setting->mass_change);
  setting->mass_change = s21_NULL;
  free(setting->mass_poz);
  setting->mass_poz = s21_NULL;
  free(setting);
  setting = s21_NULL;
}
