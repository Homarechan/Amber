#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include "tokens.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// private:
Token *appendtoken(Token *   previous,
                   Token *   next,
                   TokenType tktype,
                   int       number,
                   int       length,
                   char *    string);
Token *appendtoken_number(Token *token, char *src, int pointer);
Token *appendtoken_symbol(Token *token, char *src, int pointer);
Token *appendtoken_eof(Token *token);
bool   issymbol(char c);

// public:
Token *tokenize(char *src, int length);

#endif  // TOKENIZER_H_