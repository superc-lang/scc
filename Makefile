CC = gcc
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



SRCS = scc.c parser.tab.c lex.yy.c ast.c ast_nodes.c ast_helpers.c symbol_table.c symbol_keys.c
OBJ_DIR = build
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

TARGET = scc

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

debug:
	make BUILD=debug
# $(CC) $(CFLAGS) -g -o $(TARGET) $(SRCS)

flex:
	flex --yylineno --header-file=lex.yy.h lexer.l

bison:
	bison -d parser.y

bison-debug:
	bison --verbose --debug -d parser.y
