#include "tokenizer.h"
#include "tokens.h"

#include <stdio.h>
#include <string.h>

int main() {
    char   src[]  = "1 2 3 456 + ---=-==--%----\"-+-\"--- == += != <<= //=";
    Token *result = tokenize(src, strlen(src));
    printf("start\n");
    while (result->tktype != TK_EOF) {
        printf("%s\n", result->string);
        result = result->next;
    }
}
