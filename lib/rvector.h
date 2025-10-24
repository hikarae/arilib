#pragma once

#ifndef RVECTOR_H
#define RVECTOR_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    size_t size;
    size_t capacity;
    int* data;
} vector;

// Function to initialize a vector
void vector_init(vector* v) {
    v->size = 0;
    v->capacity = 4; // initial capacity
    v->data = (int*) malloc(v->capacity * sizeof(int));
    if (!v->data) {
        printf("Memory allocation failed\n");
        return;
    }
}

// Function to push an element to the vector
void vector_push_back(vector* v, int value) {
    if (v->size >= v->capacity) {
        v->capacity += 1; // increase capacity
        int* new_data = (int*) realloc(v->data, v->capacity * sizeof(int));
        if (!new_data) {
            printf("Memory reallocation failed\n");
            return;
        }
        v->data = new_data;
    }
    v->data[v->size++] = value;
}   
#endif // RVECTOR_H