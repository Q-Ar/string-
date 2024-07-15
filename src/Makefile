CC= gcc
FLAGS= -Wall -Werror -Wextra
FLAGS_GCOV= -fprofile-arcs -ftest-coverage

ifeq ($(shell uname -s), Darwin)
	FLAGS_TESTS= -lcheck
endif
ifeq ($(shell uname -s), Linux)
	FLAGS_TESTS= -lcheck -lm -lsubunit
endif

DIR_REPORT= ./report
DIR_INFO= ./info

NAME_C_FORLIB= s21_string.c
NAME_O_FORLIB= s21_string.o
NAME_LIB= s21_string.a
NAME_TEST= test_s21_string
NAME_GCOVTEST= gcov_s21_string

SRCS = s21_strtok.c\
			s21_strchr.c\
			s21_strcspn.c\
			s21_memchr.c\
			s21_memcmp.c\
			s21_memcpy.c\
			s21_memset.c\
			s21_strerror.c\
			s21_strlen.c\
			s21_strncmp.c\
			s21_strncat.c\
			s21_strncpy.c\
			s21_strpbrk.c\
			s21_strrchr.c\
			s21_strstr.c\
			s21_insert.c\
			s21_sprintf.c\
			s21_trim.c\
			s21_to_lower.c\
			s21_to_upper.c

OBJS		= $(SRCS:.c=.o)

TESTDIR = tests
TEST = $(TESTDIR)/test_s21_sprintf_suite.c\
			 $(TESTDIR)/test_s21_string_suite.c\
			 $(TESTDIR)/tests.c


all: $(NAME_LIB) test gcov_report


$(NAME_LIB): 
	@$(CC) -c $(SRCS) $(FLAGS)
	@ar rcs $(NAME_LIB) $(OBJS)
	@rm -rf *.o


test:
	@$(CC) -o $(NAME_TEST) $(SRCS) $(TEST) $(FLAGS_TESTS) $(FLAGS)
	

gcov_report:
	@$(CC) -o $(NAME_GCOVTEST) $(SRCS) $(TEST) $(FLAGS_TESTS) $(FLAGS) $(FLAGS_GCOV)
	@chmod +x *
	@./$(NAME_GCOVTEST)
	@mkdir $(DIR_INFO) $(DIR_REPORT)
	@gcov ./* ./
	@mv *.gcno *.gcda *.gcov $(DIR_INFO)/
	@lcov -d $(DIR_INFO) -c -o $(DIR_INFO)/lcov.info
	@genhtml -o $(DIR_REPORT) $(DIR_INFO)/lcov.info
	@open $(DIR_REPORT)/index.html


check: test
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.c *.h */*.c */*.h
	@cp ../materials/linters/.clang-format .clang-format
	clang-format -style=Google -n *.c *.h */*.c */*.h
	clang-format -style=Google -i *.c *.h */*.c */*.h
	@rm -rf .clang-format


clean:
	@rm -rf *.o *.a *.gcno *.gcda *.gcov $(NAME_TEST) $(NAME_GCOVTEST) $(DIR_INFO) $(DIR_REPORT)  


rebuid: clean test