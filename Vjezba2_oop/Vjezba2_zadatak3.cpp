#include <iostream>

template <typename T>
bool inline ascending(T a,T b) {
	return a > b;
}

template <typename T>
bool inline descending(T a,T b) {
	return a < b;
}

template <typename T>
void my_sort(T arr[], int n, bool (*cmp)(T, T)) {
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

template <typename T>
void ispis(T arr[], int n) {
	for (int i = 0;i < n;i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


int main() {
    int    a[] = { 1,232,22321,32002,32983812,23,945,3702,2563,56,234,12 };
    double b[] = { 3.5, 1.2, 9.9, 0.1, 4.4 };
    char   c[] = { 'k', 'a', 'z', 'm', 'b' };
    int na = sizeof(a) / sizeof(a[0]);
    int nb = sizeof(b) / sizeof(b[0]);
    int nc = sizeof(c) / sizeof(c[0]);

    std::cout << "int: \n";
    my_sort(a, na, ascending);
    ispis(a, na);
    my_sort(a, na, descending);
    ispis(a, na);

    std::cout << "double: \n";
    my_sort(b, nb, ascending);
    ispis(b, nb);
    my_sort(b, nb, descending);
    ispis(b, nb);

    std::cout << "char: \n";
    my_sort(c, nc, ascending);
    ispis(c, nc);
    my_sort(c, nc, descending);
    ispis(c, nc);
}