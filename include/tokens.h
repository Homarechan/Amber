#ifndef TOKENS_H_
#define TOKENS_H_

#include <stddef.h>


typedef enum {
    // Words
    TK_Number,  // Number
    TK_String,  // String
    TK_Name,    // Name of Value, Constants, Function etc

    // Symbols
    TK_LPar,          // Left parentheses     (
    TK_RPar,          // Right parentheses    )
    TK_LSqB,          // Left square blacket  [
    TK_RSqB,          // Right square blacket ]
    TK_LBra,          // Left blacket         {
    TK_RBra,          // Right blacket        }
    TK_Comma,         // Comma                ,
    TK_Dot,           // Dot                  .
    TK_Colon,         // Colon                :
    TK_SColon,        // Semicolon            ;
    TK_Equal,         // Equal                =
    TK_DEqual,        // Double Equal         ==
    TK_Bar,           // Bar                  |
    TK_BarEqual,      // Bar Equal            |=
    TK_Amper,         // Amper                &
    TK_AmperEqual,    // Amper Equal          &=
    TK_Excla,         // Exclamation point    !
    TK_NotEqual,      // Not Eqial            !=
    TK_Less,          // Less                 <
    TK_LessEqual,     // Less Equal           <=
    TK_Greater,       // Greater              >
    TK_GreaterEqual,  // Greater Equal        >=
    TK_CirFlex,       // Circum flex          ^
    TK_CFEqual,       // Circum flex Equal    ^=
    TK_LShift,        // Left shift           <<
    TK_LSEqual,       // Left shift Equal     <<=
    TK_RShift,        // Right shift          >>
    TK_RSEqual,       // Right shift Equal    >>=
    TK_Plus,          // Plus                 +
    TK_PlusEqual,     // Plus Equal           +=
    TK_DPlus,         // Double plus          ++
    TK_Minus,         // Minus                -
    TK_MinusEqual,    // Double Equal         -=
    TK_DMinus,        // Double minus         --
    TK_Star,          // Star                 *
    TK_StarEqual,     // Start Equal          *=
    TK_DStar,         // Double star          **
    TK_DStarEqual,    // Double star Equal    **=
    TK_Slash,         // Slash                /
    TK_SlashEqual,    // Slash Equal          /=
    TK_DSlash,        // Double slash         //
    TK_DSlashEqual,   // Double slash Equal   //=
    TK_Percent,       // Percent              %
    TK_PercentEqual,  // Percent Equal        %=
    TK_At,            // At                   @
    TK_AtEqual,       // At Equal             @=
    TK_LArrow,        // Left Arrow           <-
    TK_RArrow,        // Right Arrow          ->

    // Other
    TK_SOF,   // Start of file(source code)
    TK_EOF,   // End of file(source code)
    TK_Error  // Error token use in tokenization
} TokenType;

typedef struct Token_ Token;

struct Token_ {
    Token *   previous;
    Token *   next;
    TokenType tktype;
    int       number;  // Use if TokenType == TK_Number
    size_t    length;  // Length of string without '\0'
    char *    string;
};

char *token_name[54];


#endif  // TOKENS_H_