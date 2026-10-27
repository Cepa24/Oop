#include <iostream>
#include <string>
#include <vector>

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
    std::string recenica;
    std::cout << "Unesite recenicu: ";
    std::getline(std::cin, recenica);
    std::vector<std::string> rijeci = split_words(recenica);
    std::cout << "Broj rijeci: " << rijeci.size() << '\n';
    std::string najdulja = rijeci[0];

    for (const std::string& rijec : rijeci) {
        if (rijec.length() > najdulja.length()) {
            najdulja = rijec;
        }
    }
    std::cout << "Najdulja: " << najdulja << '\n';
    std::string obrnuto;
    for (int i = rijeci.size() - 1; i >= 0; i--) {
        obrnuto += rijeci[i];
        if (i > 0) {
            obrnuto += "-";
        }
    }
    std::cout << obrnuto << '\n';
    std::string prva = rijeci[0];
    for (const std::string& rijec : rijeci) {
        if (rijec < prva) {
            prva = rijec;
        }
    }
    std::cout << "Prva po abecedi: " << prva << '\n';
}
