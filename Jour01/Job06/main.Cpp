#include <iostream>

int main() {
    double prixHT, nombreKilos, tauxTVA, prixTTC;

    std::cout << "Entrez le prix HT d'un kilo de carottes : ";
    std::cin >> prixHT;

    std::cout << "Entrez le nombre de kilos de carottes : ";
    std::cin >> nombreKilos;

    std::cout << "Entrez le taux de TVA (en %) : ";
    std::cin >> tauxTVA;

    double montantHT = prixHT * nombreKilos;
    double montantTVA = montantHT * (tauxTVA / 100.0);
    prixTTC = montantHT + montantTVA;

    std::cout << "Le prix TTC des carottes est : " << prixTTC << " EUR" << std::endl;

    return 0;
}
