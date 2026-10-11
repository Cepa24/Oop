#include <iostream>

struct Fraction
{
	int numerator;
	int denominator;

	void reduce() {
		int manji = 0;
		int nzd = 0;

		if (numerator < denominator) {
			manji = numerator;
		}
		else {
			manji = denominator;
		}

		for (int i = 1;i <= manji;i++) {
			if (denominator % i == 0 && numerator % i == 0) {
				if (nzd < i) {
					nzd = i;
				}
			}
		}

		numerator = numerator / nzd;
		denominator = denominator / nzd;

	}

	double value() {
		double decimalni = (double)numerator / denominator;
		return decimalni;
	}

	void print() {
		std::cout << numerator << "/" << denominator << std::endl;
	}

};

Fraction sum(const Fraction& a, const Fraction& b) {
	Fraction rezultat;
	rezultat.numerator = a.numerator * b.denominator + b.numerator * a.denominator;
	rezultat.denominator = a.denominator * b.denominator;
	rezultat.reduce();
	return rezultat;
}

int main(void) {
	Fraction a = { 1, 2 };
	Fraction b = { 1, 4 };

	std::cout << "Originalni razlomak: ";
	a.print();
	std::cout << "Decimalni broj: " << a.value() << std::endl;

	Fraction rezultat = sum(a, b);

	std::cout << "Zbroj: ";
	rezultat.print();

	std::cout << "Decimalni broj: "<< rezultat.value() << std::endl;

}