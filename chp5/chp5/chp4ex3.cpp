//chp4ex3.cpp
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

int main() {
    int maxNumber = 100;
    int maxLength = static_cast<int>(std::log10(maxNumber * maxNumber)) + 1;

    for (int i = 1; i <= maxNumber; ++i)
    {
        int sum = i * i;
        std::cout << std::setw(5) << i << "ÀÇ Á¦°ö ";
        std::cout << std::setw(maxLength) << sum << std::endl;
    }
    return 0;
}