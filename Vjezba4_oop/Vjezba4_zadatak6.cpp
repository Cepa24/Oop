#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>

std::vector<std::string> split_words(const std::string& text) {
    std::vector<std::string> rijeci;
    int pocetak = 0;
    while (pocetak < text.length()) {
        while (pocetak < text.length() && text[pocetak] == ' ') {
            pocetak++;
        }
        if (pocetak >= text.length()) {
            break;
        }
        int kraj = text.find(' ', pocetak);
        if (kraj == std::string::npos) {
            kraj = text.length();
        }
        rijeci.push_back(text.substr(pocetak, kraj - pocetak));
        pocetak = kraj;
    }

    return rijeci;
}


int main() {
	std::vector<std::string> rjecnik = { "programski", "jezik", "c++", "je", "brz", "i", "mocan", "ali", "nije","jednostavan", "za", "pocetnike" };
    std::sort(rjecnik.begin(), rjecnik.end());

	std::string recenica;
    std::cout << "Unesite recenicu: ";
	std::getline(std::cin, recenica);

    std::vector<std::string> rijeci = split_words(recenica);
    std::vector<std::string> nepoznate;

    for (auto &rijec : rijeci) {
        
        rijec.erase(std::remove_if(rijec.begin(), rijec.end(), [](char& c) {
            return c == ',' || c == '.';
        }), rijec.end());

        std::transform(rijec.begin(), rijec.end(), rijec.begin(), [](char& c) {
            return std::tolower(c);
        });

        if (!rijec.empty()) {
            if (!std::binary_search(rjecnik.begin(), rjecnik.end(), rijec)) {
                nepoznate.push_back(rijec);
            }
        }

    }

    std::cout << "Nepoznatih rijeci: " << nepoznate.size();
    for (auto& nepo : nepoznate) {
        std::cout << " " << nepo;
    }
    std::cout << std::endl;


	return 0;
}