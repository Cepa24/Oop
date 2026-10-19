#include <iostream>
#include <vector>
#include <algorithm>

void input_vector(std::vector<int>& v) {
	int unos = 1;
	while (unos!=0) {
		std::cout << "Unesite element: ";
		std::cin >> unos;
		if (unos != 0) {
			v.push_back(unos);
			std::cout << "Vektor size: " << v.size() << std::endl;
			std::cout << "Vektor capacity: " << v.capacity() << std::endl;
		}
	}
}

void print_vector(const std::vector<int>& v) {
	for (auto it = v.rbegin(); it != v.rend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main() {

	std::vector<int> prvi = {};
	std::vector<int> drugi = {};

	input_vector(prvi);
	print_vector(prvi);

	drugi.reserve(100);
	input_vector(drugi);
	print_vector(drugi);

	drugi.shrink_to_fit();
	std::cout << "Drugi capacity: " << drugi.capacity();

	return 1;
}