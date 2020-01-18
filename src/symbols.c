#include "symbols.h"

bool issymbol(char c) {
    char symbols[] = {'(', ')', '[', ']', '{', '}', ',', '.',
                      ':', ';', '=', '|', '&', '!', '<', '>',
                      '^', '+', '-', '*', '/', '%', '@'};
    for (int n = 0; n < 23; ++n) {
        if (c == symbols[n]) {
            return true;
        }
    }
    return false;
}

TokenType getonesymbol(char c1) {
    switch (c1) {
    case '(': return TK_LPar;
    case ')': return TK_RPar;
    case '[': return TK_LSqB;
    case ']': return TK_RSqB;
    case '{': return TK_LBra;
    case '}': return TK_RBra;
    case ',': return TK_Comma;
    case '.': return TK_Dot;
    case ':': return TK_Colon;
    case ';': return TK_SColon;
    case '=': return TK_Equal;
    case '|': return TK_Bar;
    case '&': return TK_Amper;
    case '!': return TK_Excla;
    case '<': return TK_Less;
    case '>': return TK_Greater;
    case '^': return TK_CirFlex;
    case '+': return TK_Plus;
    case '-': return TK_Minus;
    case '*': return TK_Star;
    case '/': return TK_Slash;
    case '%': return TK_Percent;
    case '@': return TK_At;
    default: return TK_Error;
    }
}

TokenType gettwosymbol(char c1, char c2) {
    switch (c1) {
    case '=':
        switch (c2) {
        case '=': return TK_DEqual;
        }
        break;
    case '|':
        switch (c2) {
        case '=': return TK_BarEqual;
        }
        break;
    case '&':
        switch (c2) {
        case '=': return TK_AmperEqual;
        }
        break;
    case '!':
        switch (c2) {
        case '=': return TK_NotEqual;
        }
        break;
    case '<':
        switch (c2) {
        case '=': return TK_LessEqual;
        case '<': return TK_LShift;
        case '-': return TK_LArrow;
        }
        break;
    case '>':
        switch (c2) {
        case '=': return TK_GreaterEqual;
        case '>': return TK_RShift;
        }
        break;
    case '^':
        switch (c2) {
        case '=': return TK_CFEqual;
        }
        break;
    case '+':
        switch (c2) {
        case '=': return TK_PlusEqual;
        case '+': return TK_DPlus;
        }
        break;
    case '-':
        switch (c2) {
        case '=': return TK_MinusEqual;
        case '-': return TK_DMinus;
        case '>': return TK_RArrow;
        }
        break;
    case '/':
        switch (c2) {
        case '=': return TK_SlashEqual;
        case '/': return TK_DSlash;
        }
        break;
    case '%':
        switch (c2) {
        case '=': return TK_PercentEqual;
        }
        break;
    case '@':
        switch (c2) {
        case '=': return TK_AtEqual;
        }
        break;
    }
    return TK_Error;
}

TokenType getthreesymbol(char c1, char c2, char c3) {
    switch (c1) {
    case '<':
        switch (c2) {
        case '<':
            switch (c3) {
            case '=': return TK_LSEqual;
            }
            break;
        }
        break;
    case '>':
        switch (c2) {
        case '>':
            switch (c3) {
            case '=': return TK_RSEqual;
            }
            break;
        }
        break;
    case '*':
        switch (c2) {
        case '*':
            switch (c3) {
            case '=': return TK_DStarEqual;
            }
            break;
        }
        break;
    case '/':
        switch (c2) {
        case '/':
            switch (c3) {
            case '=': return TK_DSlashEqual;
            }
            break;
        }
        break;
    }
    return TK_Error;
}
