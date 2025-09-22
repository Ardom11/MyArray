#ifndef MYARRAY_H
#define MYARRAY_H

typedef struct {
	int *data;
	int size; //How many we have already
	int capacity; //How many we can store
} MyArray;

void array_init(MyArray *arr, int capacity);

void array_free(MyArray *arr);

void array_add(MyArray* arr, int value);

void array_insert(MyArray* arr, int value, int pos);

void array_delete(MyArray* arr, int pos);

void array_print(MyArray* arr);

void array_copy(MyArray* src, MyArray* dest);
#endif