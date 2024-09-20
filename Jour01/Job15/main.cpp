#include <iostream>

bool isBitCountEven(unsigned int number) {
    int count = 0;
    while (number) {
        count ^= (number & 1); 
        number >>= 1;          
    }
    return !count; 
}

int main() {
    unsigned int testNumber = 42; 
    bool result = isBitCountEven(testNumber);

    std::cout << "Le nombre de bits a 1 dans " << testNumber << " est ";
    std::cout << (result ? "pair" : "impair") << "." << std::endl;

    return 0;
}
