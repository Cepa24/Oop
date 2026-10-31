#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>

struct PasswordInfo {
	int length;
	int digits;
	int uppercase;
	int special;
};

PasswordInfo analyze(const std::string& password) {
	PasswordInfo psw;
	psw.length = std::count_if(password.begin(), password.end(), [](char znak) {
		return znak;
	});

	psw.digits = std::count_if(password.begin(), password.end(), [](char znak) {
		return std::isdigit(znak);
	});

	psw.uppercase = std::count_if(password.begin(), password.end(), [](char znak) {
		return std::isupper(znak);
	});

	psw.special = std::count_if(password.begin(), password.end(), [](char znak) {
		return std::ispunct(znak);
	});

	return psw;
}

bool is_strong(const PasswordInfo& info) {
	if (info.length >= 10 && info.digits >0 && info.uppercase > 0  && info.special > 0) {
		return true;
	}
	return false;
}

int main() {
	std::string lozinka;
	PasswordInfo informacije;
	std::cout << "Unesite svoju lozinku: ";
	std::cin >> lozinka;

	informacije = analyze(lozinka);
	std::cout << "Duljina: " << informacije.length << "\n";
	std::cout << "Znamenke: " << informacije.digits << "\n";
	std::cout << "Velika slova: " << informacije.uppercase << "\n";
	std::cout << "Posebni: " << informacije.special << "\n";

	if (is_strong(informacije)) {
		std::cout << "\nLozinka je JAKA.\n";
	}
	else {
		std::cout << "\nLozinka je SLABA.\n";
	}

}

