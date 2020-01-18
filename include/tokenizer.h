#ifndef TOKENIZER_H_
#define TOKENIZER_H_

#include "tokens.h"

#include <stdbool.h>
#include <stddef.h>


// private:
Token *appendtoken(Token *   previous,
                   Token *   next,
                   TokenType tktype,
                   int       number,
                   size_t    length,
                   char *    string,
                   bool      isoperator);
Token *appendtoken_number(Token *token, char *src, int pointer);
Token *appendtoken_symbol(Token *token, char *src, int pointer);
Token *appendtoken_eof(Token *token);
bool   issymbol(char c);

// public:
Token *tokenize(char *src, size_t length);

#endif  // TOKENIZER_H_