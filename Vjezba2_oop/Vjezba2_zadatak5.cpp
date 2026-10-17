#include <iostream>

double inline add(double x, double y) {
	return x + y;
}

double inline subtract(double x, double y) {
	return x - y;
}

double inline multiply(double x, double y) {
	return x * y;
}

double inline divide(double x, double y) {
	return x / y;
}

int main() {
	
	double (*operacije[])(double, double) = { add,subtract,multiply,divide };
	double prvi, drugi;
	int odabir;

	std::cout << "Unesite prvi broj: ";
	std::cin >> prvi;
	std::cout << "\n";

	std::cout << "Unesite drugi broj: ";
	std::cin >> drugi;
	std::cout << "\n";

	std::cout << "Unesite redni broj operacije: ";
	std::cin >> odabir;
	std::cout << "\n";

	if (drugi == 0 && odabir == 3) {
		std::cout << "Ne mozete dijeliti sa 0 ";
		return 0;
	}

	double rezultat = operacije[odabir](prvi,drugi);
	std::cout << "Rezultat: " << rezultat;

}