#include <iostream>


constexpr int fibonacci(int n) {
    return (n <= 1) ? n : (fibonacci(n - 1) + fibonacci(n - 2));
}


bool isBitCountEven(unsigned int number) {
    int count = 0;
    while (number) {
        count += number & 1;
        number >>= 1;
    }
    return (count % 2 == 0);
}

int main() {
   
    std::cout << "Les dix premiers termes de la suite de Fibonacci sont :" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << fibonacci(i) << " ";
    }
    std::cout << std::endl;


    unsigned int testNumber = 15; 
    bool result = isBitCountEven(testNumber);

    std::cout << "Le nombre de bits a 1 dans " << testNumber << " est ";
    std::cout << (result ? "pair" : "impair") << "." << std::endl;

    return 0;
}
