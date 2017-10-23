#include "functions.h"

void changeValue(int* value) {
	*value = 42;
}

void malFunction() {
	int* nullPointer = nullptr;
	int valueNullPointerShowsTo = *nullPointer;
}
