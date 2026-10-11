#include <iostream>

int main()
{
    int a{}, b{};
    std::cout << "Unesite a i b: " << "\n";
    std::cin >> a >> b;
    int zbroj{ (a + b) };
    double sredina{ (a + b) / 2.0 };
    bool provjera{ a < b };
    std::cout << "Zbroj brojeva a i b je: " << zbroj << "\n";
    std::cout << "Aritmeticka sredina brojeva a i b je: " << sredina << "\n";

    if (provjera == 1)
    {
        std::cout << "broj a je manji od broja b";
    }
    else
    {
        std::cout << "broj b je manji od broja a";
    }
}