// chp4ex2.cpp

#include <iostream>
#include <iomanip>
#include <string>    

int main() {
    for (int i = 1; i <= 100; ++i)
    {
        int sum = i * i;
        std::cout << std::setw(5) << i << "ÀÇ Á¦°ö" << sum << std::endl;
    }
    return 0;
}