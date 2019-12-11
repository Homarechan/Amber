#ifndef SYMBOLS_H_
#define SYMBOLS_H_

#include "tokens.h"

#include <stdbool.h>


char symbols[] = {'(', ')', '[', ']', '{', '}', ',', '.', ':', ';', '=', '|',
                  '&', '!', '<', '>', '^', '+', '-', '*', '/', '%', '@'};
int  symbols_count = 23;

bool      issymbol(char c);
TokenType getonesymbol(char c1);
TokenType gettwosymbol(char c1, char c2);
TokenType getthreesymbol(char c1, char c2, char c3);

#endif  // SYMBOLS_H_