#include <iostream>

int trouverPlusPetit(int** tableau, int taille) {
    if (taille <= 0) {
        std::cerr << "Le tableau est vide ou la taille est invalide." << std::endl;
        return -1; 
    }

    int plusPetit = **tableau;

    for (int i = 1; i < taille; ++i) {
        if (**(tableau + i) < plusPetit) {
            plusPetit = **(tableau + i);
        }
    }

    return plusPetit; 
}

int main() {
    int a = 12, b = 45, c = 7, d = 23, e = 9;

    int* tableau[] = { &a, &b, &c, &d, &e };
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    
    int plusPetit = trouverPlusPetit(tableau, taille);

    std::cout << "Le plus petit element du tableau est : " << plusPetit << std::endl;

    return 0;
}
