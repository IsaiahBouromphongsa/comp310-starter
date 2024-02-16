// token.c
#include "token.h"
#include <stdio.h> // Added for printf

// Create a new token with specified type and text
token_t* create_token(token_type_t type, const char* text) {
    token_t* token = (token_t*)malloc(sizeof(token_t));
    if (!token) return NULL; // Check malloc success

    token->type = type;
    token->text = strdup(text); // Duplicate text
    if (!token->text) { // Check strdup success
        free(token);
        return NULL;
    }
    return token;
}

// Print details of a token
void print_token(const token_t* token) {
    if (!token) return; // Check for NULL pointer
    const char* type_str = "";
    switch (token->type) {
        case NUMBER: type_str = "Number"; break;
        case OPERATOR: type_str = "Operator"; break;
        case SYMBOL: type_str = "Symbol"; break;
        case WORD: type_str = "Word"; break;
        default: type_str = "Unknown";
    }
    printf("Type: %s, Text: %s\n", type_str, token->text);
}

// Free allocated memory for a token
void free_token(token_t* token) {
    if (token) {
        free(token->text); // Free text
        token->text = NULL;
        free(token); // Free token itself
    }
}