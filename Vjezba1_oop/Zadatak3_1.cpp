#include <iostream>


int& find_max(int arr[], int n) {
	int najveci = 0;
	for (int i=0;i < n;i++) {
		if (arr[i] > najveci) {
			najveci = i;
		}
	}
	return arr[najveci];
}

int main() {
	int numbers[] = { 4, -7, 12, 0, 9, -3 };
	for (int& broj : numbers) {
		if (broj < 0) {
			broj = broj*( - 1);
		}
	}
	std::cout << "Niz s samo pozitivnim brojevima: ";
	for (int broj : numbers) {
		std::cout << broj<< " ";
	}

	find_max(numbers, 6) = 0;

	for (int broj : numbers) {
		std::cout << broj << " ";
	}
}
