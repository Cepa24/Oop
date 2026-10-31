#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

struct Student {
	std::string JMBAG;
	std::string surname;
	int points;
};

int main() {
	std::vector<Student> registered{
		{"0302", "Kovac", 78}, {"0117", "Babic", 45},
		{"0255", "Maric", 91}, {"0117", "Babic", 45},
		{"0410", "Novak", 78}, {"0089", "Juric", 62},
		{"0255", "Maric", 91}, {"0520", "Maric", 55},
		{"0333", "Peric", 30} 
	};

	int prag_bodova;
	std::cout << "Unesite prag bodova: ";
	std::cin >> prag_bodova;

	std::sort(registered.begin(), registered.end(), [](const Student& a,const Student& b) {
		return a.JMBAG < b.JMBAG;
	});
	registered.erase(std::unique(registered.begin(), registered.end(), [](const Student& a, const Student& b) {
		return a.JMBAG == b.JMBAG;
	}), registered.end());

	std::cout << "Prijavljenih: " << registered.size() << std::endl;

	registered.erase(std::remove_if(registered.begin(), registered.end(), [prag_bodova](const Student& a) {
		return a.points < prag_bodova;
	}), registered.end());

	std::sort(registered.begin(), registered.end(), [prag_bodova](const Student& a,const Student b) {
		if (a.points!=b.points) {
			return a.points > b.points;
		}
		else {
			return a.surname < b.surname;
		}
	});

	int brojac = 1;
	for (auto ucenik : registered) {
		std::cout << brojac << ". " << ucenik.surname << " (" << ucenik.JMBAG << ") " << ucenik.points << "\n";
		brojac++;
	}


	return 0;
}