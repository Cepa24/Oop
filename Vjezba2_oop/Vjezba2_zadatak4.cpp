#include <iostream>

void my_transform(int arr[], int n, int (*f)(int)) {
	for (int i = 0;i < n;i++) {
		arr[i] = f(arr[i]);
	}
}

int twice(int broj) {
	return broj * 2;
}

void ispis(int arr[], int n) {
	for (int i = 0;i < n;i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int arr[] = {3, 4, 7, 2, 5, 6, 8, 1};
	int n = sizeof(arr) / sizeof(arr[0]);
	ispis(arr, n);
	my_transform(arr, n, twice);
	std::cout << "Nakon transformacije: " << std::endl;
	ispis(arr, n);

	my_transform(arr, n, [](int x) {
		return (x%2==0) ? x/2 : x*2;
	});
	std::cout << "Prva lambda: " << std::endl;
	ispis(arr, n);

	int suma = 0;
	int produkt = 1;

	auto operacije = [&](int j) {
		suma += j;
		produkt *= j;
	};

	for (int i = 0;i < n;i++) {
		operacije(arr[i]);
	}
	std::cout << "Suma: " << suma << ", produkt: " << produkt << std::endl;

	std::cout << "Unesite prag: ";
	int prag;
	std::cin >> prag;
	std::cout<<std::endl;
	int s = 0;
	auto zbroji_vece = [prag, &s](int k) {
		if (prag < k) {
			s += k;
		}
	};
	for (int i = 0;i < n;i++) {
		zbroji_vece(arr[i]);
	}
	std::cout << "Prag: " << prag << ", suma veceg od praga: " << s << std::endl;
}