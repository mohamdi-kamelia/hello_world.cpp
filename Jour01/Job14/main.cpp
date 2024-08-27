#include <iostream>
#include <cmath>

int main() {
    int N;
    
    std::cout << "Veuillez entrer un entier N : ";
    std::cin >> N;

    if (N < 5) {
        std::cerr << "La valeur de N doit être au moins 5." << std::endl;
        return 1; 
    }

    long long somme = 0;
    for (int i = 5; i <= N; ++i) {
        somme += std::pow(i, 3);
    }

    std::cout << "La somme des cubes de 5 a " << N << " est : " << somme << std::endl;

    return 0;
}
