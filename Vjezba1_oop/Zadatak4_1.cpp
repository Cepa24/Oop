#include <iostream>

namespace geo{
	const double pi = 3.1416;
	
	double area(double r) {
		return r * r * pi;
	}

	double area(double a, double b) {
		return a * b;
	}

	int area(int a) {
		return a * a;
	}

}

void print_line(char c = '-', int length = 30) {
	for(int i=0;i<length;i++){
		std::cout << c;
	}
	std::cout << std::endl;
}

int main(void) {
	using namespace geo;

	std::cout << area(5) << std::endl;
	print_line();
	std::cout << area(5.0) << std::endl;
	print_line();
	std::cout << area(2, 3) << std::endl;
	print_line();
	std::cout << area('A') << std::endl;
	print_line();
}