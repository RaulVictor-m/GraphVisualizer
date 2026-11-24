BUILD = build
CFLAGS = -Wall -Wextra -g

STRUCT_SRCS = $(wildcard structs/*.c)
STRUCT_OBJS = $(STRUCT_SRCS:structs/%.c=$(BUILD)/struct_%.o)

$(BUILD)/struct_%.o: structs/%.c
	mkdir -p $(BUILD)
	gcc  $(CFLAGS) -c $< -o $@

$(BUILD)/structs.a: $(STRUCT_OBJS)
	ar rcs $@ $^

# test: stack.o array_list.o test.o
# 	gcc test.o stack.o array_list.o -o test
# 	valgrind ./test

# clear:
# 	rm *.o test
