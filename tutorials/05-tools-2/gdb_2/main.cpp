#include <iostream>
#include "functions.h"

int main() {
	int value = 1;

	if (value == 1) {
		value = 0;
	} else {
		value = 1;
	}

	changeValue(&value);

	malFunction();

	std::cout << "End of function reached!" << std::endl;

	return 0;
}
