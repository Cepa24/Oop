#include <iostream>

bool inline ascending(int a, int b) {
	return a > b;
}

bool inline descending(int a, int b) {
	return a < b;
}

void my_sort(int arr[], int n, bool (*cmp)(int, int)) {
	int temp = 0;
	for (int i = 0;i < n - 1;i++) {
		for (int j = 0;j < n - i - 1;j++) {
			if (cmp(arr[j], arr[j + 1])) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void ispis(int arr[],int n) {
	for (int i = 0;i < n;i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


int main() {
	int niz[] = { 1,232,22321,32002,32983812,23,945,3702,2563,56,234,12 };
	int n = sizeof(niz) / sizeof(niz[0]);

	ispis(niz, n);
	my_sort(niz,n,ascending);
	ispis(niz,n);
	my_sort(niz, n, descending);
	ispis(niz,n);
}