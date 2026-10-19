#include <iostream>

template <typename T>
T funkcija(T niz[],int n,T(*operation)(T x)) {
	for (int i = 0; i < n; i++) {
		niz[i] = operation(niz[i]);
	}
}

template <typename T>
T kvadrat(T clan) {
	return clan * clan;
}

template <typename T>
void ispis(T niz[],int n) {
	for (int i = 0; i < n; i++) {
		std::cout << niz[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	int arr[] = {1,2,4,7,21,11};
	int n = sizeof(arr) / sizeof(arr[0]);

	ispis(arr, n);
	funkcija(arr, n, kvadrat);
	ispis(arr, n);
}