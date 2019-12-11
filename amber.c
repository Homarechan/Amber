#include <stdio.h>
#include <tokenizer.h>

int main() {
    char   src[]  = "1 2 3 456 789 + - == >>=";
    Token *result = tokenize(src, strlen(src));
    printf("start\n");
    while (result->tktype != TK_EOF) {
        printf("%s\n", result->string);
        result = result->next;
    }
}
