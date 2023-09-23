#CFLAGS = -Wall -Werror -Wextra -std=c11
COMPILER = gcc
COV_FLAGS = --coverage
TEST_FLAGS = -lcheck -lpthread -lm
OBJ_FILES = *.o
C_FILES = *.c
TEST_FILE = tests/s21_dec_tests.c
EXE_FILE = s21_decimal.a

ifeq ($(shell uname), Linux)
	TEST_FLAGS += -lrt -lsubunit
endif

all: clean s21_decimal.a test

s21_decimal.a:
	gcc -c $(C_FILES) $(COV_FLAGS)
	ar rcs $(EXE_FILE) $(OBJ_FILES)
	rm -rf $(OBJ_FILES)

s21_tests.o: $(TEST_FILE)
	gcc -c $(TEST_FILE)

test_cases: s21_tests.o
	gcc -c tests/*.c

test: s21_decimal.a test_cases
	gcc -o test_result *.o -L. $(EXE_FILE) $(TEST_FLAGS) $(COV_FLAGS)
	./test_result

clean:
	@rm -rf *.html *.gcno *.gcda *.o *.out *.gch *.css *coverage* *.a test_result

leaks:
	leaks -atExit -- ./test_result

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./test_result

rebuild: clean all