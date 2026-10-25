#include <iostream>
#include <array>

constexpr int DAYS = 7;

double total(const std::array<double, DAYS>& hours) {
	double suma = 0;
	for (double dan : hours) {
		suma += dan;
	}
	return suma;
}

int best_day(const std::array<double, DAYS>& hours) {
	int najbolji = 0;
	for (int i = 0;i < DAYS;i++) {
		if (hours[i] >= hours[najbolji]) {
			najbolji = i;
		}
	}
	return najbolji + 1;
}

int main() {
	std::array<double, DAYS> prvi;
	std::array<double, DAYS> drugi;

	std::cout << "Unesi sate ucenja u prvom tjednu: ";
	for (int i = 0;i < DAYS;i++) {
		std::cout << "Unesi za " << i + 1 << ". dan: ";
		std::cin >> prvi[i];
		std::cout << std::endl;
	}

	std::cout << "\nPrvi tjedan: ukupno " << total(prvi)<< " h, najvise ucenja u danu " << best_day(prvi) << std::endl;

	drugi.fill(1.5);

	std::cout << "\nDrugi tjedan: ukupno " << total(drugi) << " h" << std::endl;

	std::cout << "\nprvi == drugi: " << (prvi == drugi) << std::endl;
	std::cout << "prvi < drugi: " << (prvi < drugi) << std::endl;
	std::cout << "prvi < drugi: " << (prvi > drugi) << std::endl;

	prvi.swap(drugi);

	std::cout << "\nNakon swap:" << std::endl;
	std::cout << "Prvi tjedan: ukupno " << total(prvi) << " h" << std::endl;
	std::cout << "Drugi tjedan: ukupno " << total(drugi) << " h" << std::endl;

	return 0;
}