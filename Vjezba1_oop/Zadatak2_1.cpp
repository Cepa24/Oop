#include <iostream>
#include <string>


int main() {
	int godina_rodenja;
	std::string ime;

	std::cout << "Unesite godinu rodenja" << "\n";
	std::cin >> godina_rodenja;
	std::cin.ignore();
	std::cout << "Unesite ime i prezime" << "\n";
	std::getline(std::cin, ime);

	std::cout << "Inicijali: ";
	if (ime !="") {
		std::cout << ime[0] << ".";
		for (int i = 0;i < ime.length();i++) {
			if (ime[i] == ' ' && i + 1<ime.length()) {
				std::cout << ime[i+1] << ".";
			}
		}
	}
	std::cout << "\n";

	int broj_znakova = 0;
	for (int i = 0;i < ime.length();i++) {
		if (ime[i] != ' ') {
			broj_znakova++;
		}
	}
	std::cout << "Broj znakova imena i prezimena bez razmaka je " << broj_znakova << "\n";

	std::cout << "Osoba navrsava " << 2026-godina_rodenja << " godina ove godine";
}
