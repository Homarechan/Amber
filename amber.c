#include "tokenizer.h"
#include "tokens.h"

#include <stdio.h>


int main() {
    char   src[]  = "1 2 3 456 + ---=-==--%----\"-+-\"--- == += != <<=";
    Token *result = tokenize(src, 12);
    printf("start\n");
    while (result->tktype != TK_EOF) {
        printf("%s\n", result->string);
        result = result->next;
    }
}
