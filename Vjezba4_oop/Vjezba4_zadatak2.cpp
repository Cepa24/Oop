#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Song {
	std::string title;
	std::string artist;
	int year;
	int plays;
};

void print_song(const Song& s) {
	std::cout << "Naslov: " << s.title << ", Izvodac: " << s.artist << ", Godina: "<< s.year <<", Broj slusanja: " << s.plays << std::endl;
}

int main() {
	std::vector<Song> songs = {
	{"Pjesma1","Darko Rundek",2001,100000000},
	{"Pjesma2","Stjepan Curepa",2003,100},
	{"Pjesma3","Miso Kovac",2000,3294923},
	{"Pjesma4","Alka Vuica",2013,92173},
	{"Pjesma5","Darko Rundek",2023,92132173}
	};

	for (auto pjesma : songs) {
		print_song(pjesma);
	}

	std::sort(songs.begin(), songs.end(), [](Song& s1, Song& s2) {
		if (s1.year != s2.year) {
			return s1.year > s2.year;
		}
		else {
			return s1.title > s2.title;
		}
	});

	std::cout << "Pjesme sortirane po godini: \n";
	for (auto pjesma : songs) {
		print_song(pjesma);
	}

	std::string ime;
	std::cout << "Unesite ime izvodaca: ";
	std::getline(std::cin, ime);

	auto izvodaca = std::count_if(songs.begin(), songs.end(), [&ime](Song& pisma) {
		return pisma.artist == ime;
	});

	if (izvodaca == 0) {
		std::cout << "Nema niti jedne pjesme tog izvodaca na popisu!";
	} 
	else{
		std::cout << "Broj pjesama na popisu tog izvodaca: " << izvodaca;
	}
	
	auto najslusanija = std::max_element(songs.begin(), songs.end(),[](const auto& a, const auto& b) {
		return a.plays < b.plays;
	});

	std::cout << "\nNajslusanija pjesma na popisu: "<< najslusanija->plays;

	return 0;
}