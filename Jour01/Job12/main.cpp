#include <iostream>

int doubleArray(int* tableau, int taille) {
    int somme = 0;
    for (int i = 0; i < taille; ++i) {
        *(tableau + i) *= 2;
        somme += *(tableau + i);
    }
    return somme;
}

void printArray(int* tableau, int taille) {
    for (int i = 0; i < taille; ++i) {
        std::cout << *(tableau + i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    int tableau[] = {1, 2, 3, 4, 5};
    int taille = sizeof(tableau) / sizeof(tableau[0]);

    int somme = doubleArray(tableau, taille);

    std::cout << "Somme des elements doubles : " << somme << std::endl;

    std::cout << "Tableau apres avoir double les elements : ";
    printArray(tableau, taille);

    return 0;
}
