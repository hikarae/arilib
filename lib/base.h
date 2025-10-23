#pragma once

#ifndef BASE_H
#define BASE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char* string; // Define string as a pointer to char

void stri (string* out){ // Function to read a string !NEED FREE
    size_t capacity;
    size_t index;
    char* str;
    
    if(*out == NULL) {
        capacity = 16;
        index = 0;
        str = (char*) malloc(capacity * sizeof(char));
    }
    else {
        capacity = strlen(*out) + 16;  
        index = strlen(*out);
        str = (char*) malloc(capacity * sizeof(char));
        strcpy(str, *out);  
        free(*out);  
    }
    
    if (!str) {
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
            capacity *= 2; // Double the capacity for better performance 
            char* new_str = (char*) realloc(str, capacity * sizeof(char));
            if (!new_str) {
                free(str);
                return;
            }
            str = new_str;
        }
        str[index++] = buffer;
    }
    str[index] = '\0';  // Null-terminate the string
    *out = str;
} 

#endif // BASE_H