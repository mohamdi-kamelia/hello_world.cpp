#include <iostream>

int main() {
    int nombre;

    std::cout << "Entrez un nombre entier: ";
    std::cin >> nombre;

    if (nombre % 2 == 0) {
        std::cout << "Le nombre " << nombre << " est pair." << std::endl;
    } else {
        std::cout << "Le nombre " << nombre << " est impair." << std::endl;
    }

    return 0;
}
