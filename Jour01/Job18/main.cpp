#include <iostream>

void addElement(int*& table, int& taille, int nouvelElement) {
    int* nouveauTableau = new int[taille + 1];

    for (int i = 0; i < taille; ++i) {
        nouveauTableau[i] = table[i];
    }

    nouveauTableau[taille] = nouvelElement;
    delete[] table;
    table = nouveauTableau;
    ++taille;
}

void showTable(const int* table, int taille) {
    for (int i = 0; i < taille; ++i) {
        std::cout << table[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int taille = 0;
    int* tableau = new int[taille];

    addElement(tableau, taille, 22);
    addElement(tableau, taille, 29);
    addElement(tableau, taille, 90);
    addElement(tableau, taille, 87);
    addElement(tableau, taille, 61);

    std::cout << "Contenu du tableau : ";
    showTable(tableau, taille);

    delete[] tableau;
    return 0;
}
