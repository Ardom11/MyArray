#include "MyArray.h"
#include <stdio.h>
#include <stdlib.h>

void array_init(MyArray* arr, int capacity) {
	arr->data = malloc(sizeof(int) * capacity);
	arr->size = 0;
	arr->capacity = capacity;
}

void array_free(MyArray* arr) {
	if (arr->data != NULL) {
		free(arr->data);
		arr->data = NULL;
	}
	arr->size = 0;
	arr->capacity = 0;
}

void array_add(MyArray* arr, int value) {
	if (arr->data == NULL) {
		printf("Array is NULL\n");
		return;
	}

	if (arr->size == arr->capacity) {
		arr->data = realloc(arr->data, sizeof(int) * (arr->capacity + 1));
		arr->capacity += 1;
	}

	int* D = arr->data;

	*(D + arr->size) = value;
	arr->size++;
}

void array_insert(MyArray* arr, int value, int pos) {
	if (arr->data == NULL) {
		printf("Array is NULL\n");
		return;
	}

	if (pos > arr->size || pos < 0) {
		printf("Wrong position");
		return;
	}

	if (arr->size == arr->capacity) {
		arr->data = realloc(arr->data, sizeof(int) * (arr->capacity + 1));
		arr->capacity += 1;
	}

	int* D = arr->data;

	for (int i = arr->size; i > pos - 1; i--) {
		*(D + i) = *(D + i - 1);
	}

	*(D + (pos - 1)) = value;
	arr->size++;
}

void array_delete(MyArray* arr, int pos) {
	if (arr->data == NULL) {
		printf("Array is NULL\n");
		return;
	}

	if (pos > arr->size || pos < 0) {
		printf("Wrong position");
		return;
	}

	int* D = arr->data;

	for (int i = pos - 1; i < arr->size - 1; i++) {
		*(D + i) = *(D + i + 1);
	}

	arr->size--;
}

void array_print(MyArray* arr) {
	if (arr->data == NULL) {
		printf("Array is NULL\n");
		return;
	}

	int* D = arr->data;
	for (int i = 0; i < arr->size; i++) {
		printf("%d ", *(D + i));
	}

	printf("\n");
}

void array_copy(MyArray* src, MyArray* dest) {
	if (src->data == NULL) {
		printf("Source array is NULL\n");
		return;
	}
	
	if (dest->data == NULL) {
		array_init(dest, src->size);
	}

	if (dest->capacity < src->size) {
		dest->data = realloc(dest->data, sizeof(int) * (dest->capacity + (src->size - dest->capacity)));
		dest->capacity += src->size - dest->capacity;
	}

	int* Dsrc = src->data;
	int* Ddest = dest->data;

	for (int i = 0; i < src->size; i++) {
		*(Ddest + i) = *(Dsrc + i);
	}
	dest->size = src->size;
}