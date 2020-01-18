#!/usr/bin/sh

gcc amber.c src/tokenizer.c src/symbols.c src/tokens.c -I./include -o bin/main

bin/main