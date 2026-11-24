DEBUG_PROGRAM = valgrind

BUILD = build
CFLAGS = -Wall -Wextra -g

STRUCT_DIR  = structs
STRUCT_SRCS = $(wildcard $(STRUCT_DIR)/*.c)
STRUCT_OBJS = $(STRUCT_SRCS:$(STRUCT_DIR)/%.c=$(BUILD)/struct_%.o)

$(BUILD)/struct_%.o: $(STRUCT_DIR)/%.c
	mkdir -p $(BUILD)
	gcc  $(CFLAGS) -c $< -o $@

$(BUILD)/structs.a: $(STRUCT_OBJS)
	ar rcs $@ $^

test: test/test.c $(BUILD)/structs.a
	mkdir -p bin
	gcc $^ -I$(STRUCT_DIR) -o bin/test
	$(DEBUG_PROGRAM) bin/test

clean:
	rm -rf build/* bin/*
