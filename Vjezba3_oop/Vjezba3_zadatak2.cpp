#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cout << "Unesite broj dana: ";
	std::cin >> n;

	if (n <= 0) {
		std::cout << "\nBroj dana mora biti veci od 0!";
		return 0;
	}

	std::vector<double> temperature(n);
	for (int i = 0;i < n;i++) {
		std::cout << "\nUnesite " << i+1 << ". temperaturu: ";
		std::cin >> temperature[i];
	}

	std::vector<double> promjene;
	promjene.reserve(n - 1);
	for (auto it = temperature.begin();it+1 != temperature.end();it++) {
		promjene.push_back(*(it+1)-*it);
	}

	std::cout << "Originalni vektor: " << std::endl;
	for (auto it = temperature.begin();it != temperature.end();it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "Promjene temperatura: " << std::endl;
	for (auto it = promjene.begin();it != promjene.end();it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	double zadnji = temperature.back();
	temperature.resize(7, zadnji);

	std::cout << "Izvjestaj: " << std::endl;
	for (auto it = temperature.begin();it != temperature.end();it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return 1;
}