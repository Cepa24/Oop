#include <iostream>
#include <string>

bool split_email(const std::string& email, std::string& user, std::string& domain) {
	if (email.find("@") != std::string::npos && email.find("@") == email.rfind("@") && email.find("@") != 0 && email.find("@")!=email.size()-1 && email.find(".", email.find("@")) != std::string::npos) {
		user=email.substr(0, email.find("@"));
		domain = email.substr(email.find("@") + 1);
		return true;
	}
	else {
		return false;
	}
}

int main() {
	std::string mail;
	std::string ime;
	std::string domena;
	std::cout << "Unesite e-mail adresu: ";
	std::getline(std::cin, mail);
	bool provjera=split_email(mail, ime, domena);
	if (provjera) {
		std::cout << "\nKorisnicko ime: " << ime;
		std::cout << "\nDomena: " << domena;
	}
	else {
		std::cout << "Neispravna email adresa";
	}
}