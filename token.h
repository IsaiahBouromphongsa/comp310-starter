// token.h
#ifndef TOKEN_H
#define TOKEN_H

#include <stdlib.h>
#include <string.h>

// Enum for different token types
typedef enum {
    NUMBER,
    OPERATOR,
    SYMBOL,
    WORD,
    UNKNOWN
} token_type_t;

// Struct for a token
typedef struct {
    token_type_t type;
    char* text;
} token_t;

// Function declarations
token_t* create_token(token_type_t type, const char* text);
void print_token(const token_t* token);
void free_token(token_t* token);

#endif // TOKEN_H