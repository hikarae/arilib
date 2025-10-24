#pragma once

#ifndef RVECTOR_H
#define RVECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t size;
    size_t capacity;
    char type;// can be 'i' for int, 'f' for float, 'd' for double, 'c' for char
    void* data;
} rvector; // Define a simple dynamic array (vector) structure

// Function to initialize a vector
void rvector_init(rvector* vec) {
    vec->size = 0;
    vec->capacity = 4; // initial capacity
    char type = vec->type;
    if (vec->data != NULL) {
        free(vec->data); // free existing data if any
    }
    switch (type)
    {
    case 'i':
        int* idata = (int*) malloc(vec->capacity * sizeof(int));
        if(!idata){
            printf("Memory allocation failed\n");
            return;
        }
        vec->data = idata;
        break;
    case 'f':
        float* fdata = (float*) malloc(vec->capacity * sizeof(float));
        if(!fdata){
            printf("Memory allocation failed\n");
            return;
        }
        vec->data = fdata;
        break;
    case 'd':
        double* ddata = (double*) malloc(vec->capacity * sizeof(double));
        if(!ddata){
            printf("Memory allocation failed\n");   
            return;
        }
        vec->data = ddata;  
        break;
    case 'c':
        char* cdata = (char*) malloc(vec->capacity * sizeof(char));
        if(!cdata){
            printf("Memory allocation failed\n");
            return;
        }
        vec->data = cdata;
        break;  
    default:
        printf("Unsupported type\n");
        break;
    }
}

// Function to push back an integer to the vector
void rpushbackint(rvector* vec, int value) {
    if (vec->type != 'i') {
        printf("Vector type mismatch\n");
        return;
    }
    if (vec->size >= vec->capacity) {
        vec->capacity += 1; // increase capacity
        int* new_data = (int*) realloc(vec->data, vec->capacity * sizeof(int));
        if (!new_data) {
            printf("Memory reallocation failed\n");
            return;
        }
        vec->data = new_data;
    }
    ((int*)vec->data)[vec->size++] = value;
}

// Function to push back a float to the vector
void rpushbackfloat(rvector* vec, float value) {
    if (vec->type != 'f') { 
        printf("Vector type mismatch\n");
        return;
    }
    if (vec->size >= vec->capacity) {
        vec->capacity += 1; // increase capacity
        float* new_data = (float*) realloc(vec->data, vec->capacity * sizeof(float));
        if (!new_data) {
            printf("Memory reallocation failed\n");
            return;
        }
        vec->data = new_data;
    }
    ((float*)vec->data)[vec->size++] = value;
}

// Function to push back a double to the vector
void rpushbackdouble(rvector* vec, double value) {
    if (vec->type != 'd') {
        printf("Vector type mismatch\n");
        return;
    }
    if (vec->size >= vec->capacity) {
        vec->capacity += 1; // increase capacity
        double* new_data = (double*) realloc(vec->data, vec->capacity * sizeof(double));
        if (!new_data) {
            printf("Memory reallocation failed\n");
            return;
        }
        vec->data = new_data;
    }
    ((double*)vec->data)[vec->size++] = value;
}
// Function to push back a char to the vector
void rpushbackchar(rvector* vec, char value) {
    if (vec->type != 'c') { 
        printf("Vector type mismatch\n");
        return;
    }
    if (vec->size >= vec->capacity) {
        vec->capacity += 1; // increase capacity
        char* new_data = (char*) realloc(vec->data, vec->capacity * sizeof(char));
        if (!new_data) {
            printf("Memory reallocation failed\n");
            return;
        }
        vec->data = new_data;
    }
    ((char*)vec->data)[vec->size++] = value;
}

// Function to get the size of the vector
size_t rvector_size(const rvector* vec) {
    return vec->size;
}

// Print type of vector
void rvector_print_type(const rvector* vec) {
    switch (vec->type) {
        case 'i':
            printf("Vector type: int\n");
            break;
        case 'f':
            printf("Vector type: float\n");
            break;
        case 'd':
            printf("Vector type: double\n");
            break;
        case 'c':
            printf("Vector type: char\n");
            break;
        default:
            printf("Vector type: unknown\n");
            break;
    }
}
#endif // RVECTOR_H