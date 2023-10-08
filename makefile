#Homework 3
#Brady Bock
#bbock4

GCC = gcc
CONSERVATIVE_FLAGS = -std=c99 -Wall -Wextra -pedantic
DEBUGGING_FLAGS = -g -O0
CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

puzzle: puzzle.o puzzle_funcs.o
	$(GCC) -o puzzle puzzle.o puzzle_funcs.o

puzzle_funcs.o: puzzle_funcs.c puzzle.h
	$(GCC) -c puzzle_funcs.c $(CFLAGS)

puzzle.o: puzzle.c puzzle.h
	$(GCC) -c puzzle.c $(CFLAGS)

# TODO: instructions to compile and run the test file

test: testLink
	./test

testLink: puzzle_funcs.o puzzle_tests.o
	$(GCC) -o test puzzle_funcs.o puzzle_tests.o

puzzle_funcs.o: puzzle_funcs.c puzzle.h
	$(GCC) -c puzzle_funcs.c $(CFLAGS)

puzzle_tests.o: puzzle_tests.c puzzle.h
	$(GCC) -c puzzle_tests.c $(CFLAGS)

clean:
	rm -f *.o hw3 test *~





#Homework 3
#Brady Bock
#bbock4
# GCC = gcc
# CONSERVATIVE_FLAGS = -std=c99 -Wall -Wextra -pedantic
# DEBUGGING_FLAGS = -g -O0
# CFLAGS = $(CONSERVATIVE_FLAGS) $(DEBUGGING_FLAGS)

# hw3: hw3.o functions.o
# 	$(GCC) -o hw3 hw3.o functions.o

# functions.o: functions.c functions.h
# 	$(GCC) -c functions.c $(CFLAGS)

# hw3.o: hw3.c functions.h
# 	$(GCC) -c hw3.c $(CFLAGS)

# # TODO: instructions to compile and run the test file

# test: testLink
# 	./test

# testLink: test_functions.o functions.o
# 	$(GCC) -o test test_functions.o functions.o

# test_functions.o: test_functions.c functions.h
# 	$(GCC) -c test_functions.c $(CFLAGS)

# clean:
# 	rm -f *.o hw3 test *~

