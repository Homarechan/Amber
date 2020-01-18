#include "tokenizer.h"

#include "symbols.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Token *appendtoken(Token *   previous,
                   Token *   next,
                   TokenType tktype,
                   int       number,
                   int       length,
                   char *    string) {
    Token *new_token    = (Token *)malloc(sizeof(Token));
    new_token->previous = previous;
    new_token->next     = next;
    new_token->tktype   = tktype;
    new_token->number   = number;
    new_token->length   = length;

    if (string) {
        new_token->string = (char *)malloc(length);
        memcpy(new_token->string, string, length);
        new_token->string[length] = '\0';
    }
    previous->next = new_token;

    return new_token;
}

Token *appendtoken_number(Token *token, char *src, int pointer) {
    char *tmp           = src;
    int   result_number = strtol(tmp + pointer, &tmp, 10);
    int   length        = tmp - src - pointer;

    Token *new_token =
      appendtoken(token, NULL, TK_Number, result_number, length, src + pointer);

    return new_token;
}

Token *appendtoken_symbol(Token *token, char *src, int pointer) {
    TokenType binop;

    if ((binop = getthreesymbol(
           src[pointer], src[pointer + 1], src[pointer + 2])) != TK_Error) {
        char *tname = token_name[(int)binop];
        return appendtoken(token, NULL, binop, 0, 3, NULL);
    }
    if ((binop = gettwosymbol(src[pointer], src[pointer + 1])) != TK_Error) {
        char *tname = token_name[(int)binop];
        return appendtoken(token, NULL, binop, 0, 2, NULL);
    }
    if ((binop = getonesymbol(src[pointer])) != TK_Error) {
        char *tname = token_name[(int)binop];
        return appendtoken(token, NULL, binop, 0, 1, NULL);
    }
    fprintf(stderr, "panic: Unknown operator in %d\n", pointer);
    exit(EXIT_FAILURE);
}

Token *appendtoken_eof(Token *token) {
    Token *new_token = appendtoken(token, NULL, TK_EOF, 0, 0, "");
    return new_token;
}

Token base;

// Public function
Token *tokenize(char *src, int length) {
    // Base token
    Token *latest = appendtoken(&base, NULL, TK_SOF, 0, 0, "");

    // Src pointer
    int pointer = 0;

    // Charactor
    char now;

    // Main tokenize loop
    while (1) {

        now = src[pointer];

        // If space, pass it.
        if (isspace(now)) {
            ++pointer;
            continue;
        }

        // If digit, generate a number token.
        if (isdigit(now)) {
            latest = appendtoken_number(latest, src, pointer);
            pointer += latest->length;
            continue;
        }

        // If symbol, generate a symbol token.
        if (issymbol(now)) {
            latest = appendtoken_symbol(latest, src, pointer);
            pointer += latest->length;
            continue;
        }

        if (now == '\0') {
            appendtoken_eof(latest);
            return base.next;
        }

        if (pointer > length) {
            fprintf(stderr, "panic: The last of file is not EOF\n");
            exit(EXIT_FAILURE);
        }
        fprintf(stderr, "panic: Unknown charactor\n");
        exit(EXIT_FAILURE);
    }
}