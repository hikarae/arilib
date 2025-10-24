#pragma once

#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef char* string; // define string as a pointer to char

// Function to read a string, need free with free()
void rscanf (string* out) {
    size_t capacity;
    size_t index;
    string str;
    
    if(*out == NULL) { // if the input string is NULL, initialize it
        capacity = 16; // initial capacity
        index = 0;
        str = (char*) malloc(capacity * sizeof(char));
    }
    else { // if the input string is not NULL, continue from its end
        capacity = strlen(*out) + 2; // extend capacity
        index = strlen(*out);
        str = (char*) malloc(capacity * sizeof(char));
        strcpy(str, *out);  
        free(*out);  
    }
    
    if (!str) { // check for malloc failure
        printf("Memory allocation failed\n");
        return;  
    }
    char buffer;
    while (true){
        buffer = getchar();
        if (buffer == '\n' || buffer == EOF){
            break;
        }
        if (index + 1 >= capacity){
            capacity += 1; // double the capacity for better performance 
            char* new_str = (char*) realloc(str, capacity * sizeof(char));
            if (!new_str) { // check for realloc failure
                printf("Memory relocation failed\n");
                free(str);
                return;
            }
            str = new_str;
        }
        str[index++] = buffer;
    }; 
    str[index] = '\0';  // null-terminate the string
    *out = str;
}

// Function to reverse a string in place if func == 1, or return a new reversed string if func == 0
char* reverse_string(const string* input, int func){
    if (input == NULL) {
        printf("Input string is NULL\n");
        return NULL; // handle NULL input
    }
    if(func != 0 && func != 1){
        printf("Invalid function parameter\n");
        return NULL; // handle invalid func parameter
    }
    if(func == 1){
        size_t len = strlen(*input);
        for(size_t i = 0; i < len / 2; i++){
            char temp = (*input)[i];
            (*input)[i] = (*input)[len - i - 1];
            (*input)[len - i - 1] = temp;
        }
        return NULL; // in-place reversal, no new string returned
    }
    else {
        size_t len = strlen(*input);
        char* reversed = (char*) malloc((len + 1) * sizeof(char));
        if (!reversed) {
            printf("Memory allocation failed\n");
            return NULL; // handle malloc failure
        }
        for(size_t i = 0; i < len / 2; i++){
            reversed[i] = (*input)[len - i - 1];
        }
        reversed[len] = '\0'; // null-terminate the new string
        return reversed;
    }

}

// Function to convert a string to uppercase
void upcase(string* input){
    if (input == NULL || *input == NULL) {
        printf("Input string is NULL\n");
        return; // handle NULL input
    }
    size_t len = strlen(*input);
    for(size_t i = 0; i < len; i++){
        (*input)[i] = toupper((*input)[i]);
    }
}

// Function to convert a string to lowercase
void lowcase(string* input){
    if (input == NULL || *input == NULL) {
        printf("Input string is NULL\n");
        return; // handle NULL input
    }
    size_t len = strlen(*input);
    for(size_t i = 0; i < len; i++){
        (*input)[i] = tolower((*input)[i]);
    }
}

// Function to clear the input buffer
void clearinputbuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

#endif // STRING_H