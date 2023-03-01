CC = gcc
CFLAGS = -Wall
LDFLAGS = #-lfl


ifeq ($(BUILD),debug)
# Debug
CFLAGS += -O0 -g
# LDFLAGS +=
else ifeq ($(BUILD),asm)
# Asm
CFLAGS += -O3 -g -save-temps -fverbose-asm -masm=intel -DNDEBUG
else
# Release mode
CFLAGS += -O3 -DNDEBUG
# LDFLAGS += -s
endif


SRCS = scc.c parser.tab.c lex.yy.c ast.c ast_nodes.c ast_helpers.c symbol_table.c symbol_keys.c print_ast_tree.c codegen.c compiler_passes.c traverse_ast.c compass_impl.c compass_generics.c
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

asm:	# -save-temps -fverbose-asm -masm=intel ... used for looking at the disassembly code!
	make BUILD=asm

flex:
	flex --yylineno --header-file=lex.yy.h lexer.l

bison:
	bison -d parser.y

bison-debug:
	bison --verbose --debug -d parser.y
