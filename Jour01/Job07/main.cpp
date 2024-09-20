#include <iostream>

int main() {
    int nombre, inverse = 0;

    std::cout << "Entrez un nombre entier : ";
    std::cin >> nombre;

    int temp = nombre;
    
    while (temp != 0) {
        int chiffre = temp % 10;
        inverse = inverse * 10 + chiffre;
        temp /= 10;
    }

    std::cout << "Le nombre avec les chiffres inverses est : " << inverse << std::endl;

    return 0;
}
