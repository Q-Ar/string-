#include "tests.h"

int main(void) {
  int failed_tests = 0;  // счётчик проваленных тестов
  Suite *test_s21_string_func[] = {test_s21_sprintf(), test_s21_string(), NULL};

  for (int i = 0; test_s21_string_func[i] != NULL; i++) {
    SRunner *srun = srunner_create(test_s21_string_func[i]);

    srunner_set_fork_status(srun, CK_NOFORK);
    srunner_run_all(srun, CK_NORMAL);

    failed_tests += srunner_ntests_failed(srun);
    srunner_free(srun);
  }
  printf("========= FAILED: %d =========\n", failed_tests);

  return failed_tests == 0 ? 0 : 1;
}
