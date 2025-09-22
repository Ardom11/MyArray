#include "MyArray.h"

int main() {
	MyArray arr1;
	MyArray arr2;

	array_init(&arr1, 4);
	array_add(&arr1, 1);
	array_add(&arr1, 2);
	array_add(&arr1, 3);
	array_add(&arr1, 4);

	array_init(&arr2, 3);
	array_add(&arr2, 5);
	array_add(&arr2, 6);
	array_add(&arr2, 7);

	array_print(&arr1);
	array_print(&arr2);

	printf("\n");
	array_insert(&arr1, 6, 2);
	array_print(&arr1);

	printf("\n");
	array_copy(&arr1, &arr2);
	array_print(&arr2);

	printf("\n");
	array_delete(&arr1, 3);
	array_print(&arr1);

	array_free(&arr1);
	array_free(&arr2);
	
	return 0;
}