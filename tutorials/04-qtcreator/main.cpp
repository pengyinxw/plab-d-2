#include <iostream>

void multiply(int firstFactor, int secondFactor, int& result);

void sum(int firstAddend, int secondAddend, int result) {
	result
	= firstAddend
	+
	secondAddend;
}

void sumRef(int firstAddend, int secondAddend, int& result) {
	result = firstAddend + secondAddend;
}

int main() {
int a = 5;
int b = 3;
int result;
int resultRef;

int resultMult;
multiply(a, b, resultMult);

std::cout << "Result of sum: " << result << std::endl;
std::cout << "Result of sumRef: " << resultRef << std::endl;
std::cout << "Result of mult: " << resultMult << std::endl;


bool flag = false;
if (flag) {
std::cout << "Hello World!" << std::endl;
}
return(0);
}
