#include <iostream>
#include <vector>
#include <algorithm>

void input_vector(std::vector<int>& v) {
	int unos = 1;
	while (unos != 0) {
		std::cout << "Unesite element: ";
		std::cin >> unos;
		if (unos != 0) {
			v.push_back(unos);
		}
	}
}

int main() {
	std::vector <int> brojevi;
	int k;

	std::cout << "Unesite brojeve(0 za kraj) :" << std::endl;
	input_vector(brojevi);
	std::cout << "Unesite k: ";
	std::cin >> k;
	if (k <= 0) {
		std::cout << "Pogreska u unosu!";
		return 1;
	}

	int negativnih = std::count_if(brojevi.begin(), brojevi.end(), [](int x) {
		return x < 0;
		});
	std::cout << "negativnih: " << negativnih << std::endl;

	auto it = std::find_if(brojevi.begin(), brojevi.end(), [k](int x) {
		return x % k == 0;
	});

	if (it != brojevi.end()) {
		std::cout << "prvi visekratnik od " << k << ": " << *it << " (pozicija " << it - brojevi.begin() << ")" << std::endl;
	}
	else {
		std::cout << "nema visekratnika od " << k << std::endl;
	}

	auto mn = std::min_element(brojevi.begin(), brojevi.end());
	auto mx = std::max_element(brojevi.begin(), brojevi.end());
	std::cout << "min " << *mn << " (pozicija " << mn - brojevi.begin() << "), max " << *mx << " (pozicija " << mx - brojevi.begin() << ")" << std::endl;

	brojevi.erase(std::remove_if(brojevi.begin(), brojevi.end(), [k](int x) {
		return x % k == 0;
	}), brojevi.end());

	std::cout << "bez visekratnika:";
	for (int x : brojevi) {
		std::cout << " " << x;
	}
	std::cout << std::endl;

	return 0;
}