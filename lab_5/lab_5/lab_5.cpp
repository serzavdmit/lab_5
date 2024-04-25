#include <iostream>
#include <string>
using namespace std;
string decToBin(double decimal) 
{
    
    string binary = "";
    int intPart = static_cast<int>(decimal);
    double fractionalPart = decimal - intPart;
    while (intPart > 0) {
        binary = std::to_string(intPart % 2) + binary;
        intPart /= 2;
    }
    binary += '.';
    int maxIterations = 32;  
    while (fractionalPart > 0 && maxIterations-- > 0) {
        fractionalPart *= 2;
        if (fractionalPart >= 1) {
            binary += '1';
            fractionalPart -= 1;
        }
        else {
            binary += '0';
        }
    }
    return binary;
}
int main() {
    setlocale(LC_ALL, "Ukr");
    double input;
    std::cout << "Введiть десяткове число: ";
    std::cin >> input;

    if (std::cin.fail()) {
        std::cerr << "Некоректнi данi. Будь ласка, введiть число.\n";
        return 1;
    }

    string binary = decToBin(input);
    cout << "Двiйкове представлення: " << binary << endl;
    return 0;
}
