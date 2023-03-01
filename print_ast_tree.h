#pragma once

#include "ast.h"

#include <stdio.h>

void print_ast_tree(FILE *out, union ast_node *node, int depth, union ast_node *parent);
