#include <iostream>
#include <string>

std::string with_separators(std::string digits) {
	int pocetak = 0;
	if (digits[0] == '-') {
		pocetak = 1;
	}
	for (int i = digits.length() - 3; i > pocetak; i -= 3) {
		digits.insert(i, ".");
	}
	return digits;
}

std::string without_separators(std::string text) {
	int pozicija;
	while ((pozicija = text.find('.')) != std::string::npos) {
		text.erase(pozicija, 1);
	}
	return text;
}

int main() {
	std::string broj1;
	std::string broj2;
	std::cout << "Unesite broj bez tocaka: ";
	std::getline(std::cin, broj1);
	std::cout << "Unesite broj s tockama: ";
	std::getline(std::cin, broj2);
	std::cout << "Broj s tockama: "<< with_separators(broj1) << '\n';
	std::cout << "Broj bez tocaka: "<< without_separators(broj2) << '\n';
}