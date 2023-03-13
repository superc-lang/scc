CC = ../../scc
CFLAGS = -Wall
LDFLAGS = #-lfl


ifeq ($(BUILD),debug)
# Debug
CFLAGS += -O0 -g
# LDFLAGS +=
else
# Release mode
CFLAGS += -O3 -DNDEBUG
# LDFLAGS += -s
endif


SRCS = main.c opaque-generic.c
OBJ_DIR = build
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

TARGET = a.out

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: all
# ./$(TARGET)
	./run.sh

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

debug:
	make BUILD=debug
# $(CC) $(CFLAGS) -g -o $(TARGET) $(SRCS)
