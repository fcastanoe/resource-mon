CC = gcc
CFLAGS = -Isrc -Wall -Wextra -g

SRC = src/cpuinfo_manip.c src/meminfo_manip.c src/tui.c src/resource_mon.c
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))
BIN = bin/resource_mon

TEST_SRC = test/cpuinfo_test.c test/meminfo_test.c test/tui_test.c
TEST_BIN = bin/cpuinfo_test bin/meminfo_test bin/tui_test

all: resource_mon tests

resource_mon: $(OBJ)
	@mkdir -p bin
	$(CC) $(CFLAGS) -o $(BIN) $^ -lncurses

tests: $(TEST_SRC)
	@mkdir -p bin
	$(CC) $(CFLAGS) -o bin/cpuinfo_test test/cpuinfo_test.c src/cpuinfo_manip.c
	$(CC) $(CFLAGS) -o bin/meminfo_test test/meminfo_test.c src/meminfo_manip.c
	$(CC) $(CFLAGS) -o bin/tui_test test/tui_test.c src/tui.c -lncurses

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf obj/*.o bin/*

.PHONY: all tests clean resource_mon
