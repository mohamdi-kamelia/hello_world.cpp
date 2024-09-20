#include <iostream>

int main() {
    int somme = 0; // Variable pour la somme des nombres
    int nombre;    // Variable temporaire pour chaque nombre saisi

    std::cout << "Veuillez entrer cinq entiers:" << std::endl;

    for (int i = 0; i < 5; ++i) {
        std::cin >> nombre;
        somme += nombre;
    }

    double moyenne = static_cast<double>(somme) / 5;
    std::cout << "La moyenne des cinq nombres est: " << moyenne << std::endl;

    return 0;
}
