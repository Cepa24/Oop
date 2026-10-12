#include <iostream>
#include <string>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int inline my_max(int a,int b) {
	return (a > b) ? a : b;
}

template<typename T>
 void my_max_temp(T& a,T& b) {
	 if (a > b) {
		 std::cout << a << std::endl;
	 }
	 else {
		 std::cout << b << std::endl;
	 }
}

int main() {
	int a = MAX(3, 5);
	int b = 2 * MAX(3, 5);
	int c = MAX(3, 5) + 1;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	int i = 3;

	int d = MAX(++i, 2);
	std::cout << d << std::endl;
	int e = my_max(++i, 2);
	std::cout << e << std::endl;

	my_max_temp(a, b);

	double h = 1.0;
	double j = 2.1;
	my_max_temp(h, j);

	char jedno = 'A';
	char drugo = 'B';
	my_max_temp(jedno,drugo);

	std::string prvi = "prvi string";
	std::string drugi = "drugi string";
	my_max_temp(prvi, drugi);
}