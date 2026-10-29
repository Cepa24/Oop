#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

bool starts_with(const std::string& s, const std::string& prefix) {
	if (s.length() < prefix.length()) {
		return false;
	}
	return std::equal(prefix.begin(), prefix.end(), s.begin());
}

bool ends_with(const std::string& s, const std::string& suffix) {
	if (s.length() < suffix.length()) {
		return false;
	}
	return std::equal(suffix.rbegin(),suffix.rend(),s.rbegin());
}

int main() {
	std::vector<std::string> datoteke{"vjezba04.cpp", "slajdovi.pdf", "main.cpp", "README.md", "vjezba04.h", "notes.txt", "vjezba03.cpp"};
	std::string prefiks = "vjezba";
	std::string sufiks = ".cpp";

	int broj_datoteka_sufiks = std::count_if(datoteke.begin(), datoteke.end(), [sufiks](std::string& file) {
		return ends_with(file,sufiks);
	});

	std::cout << ".cpp datoteka: " << broj_datoteka_sufiks << std::endl;

	datoteke.erase(
		std::remove_if(datoteke.begin(), datoteke.end(), [prefiks](std::string& file) {
			return starts_with(file, prefiks);
		}),datoteke.end()
	);

	for (auto& file : datoteke) {
		std::cout << file << " ";
	}

	return 0;
}