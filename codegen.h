#pragma once

#include "ast.h"
#include "ast_helpers.h"

#include <stdio.h>

void codegen(FILE *out, union ast_node *node, int depth, union ast_node *parent);
