#include <iostream>

class Pingouin {
private:
    double vitesseGlisse; 
    std::string nom;

public:
    Pingouin() : vitesseGlisse(0.0), nom("Sans nom") {}

    Pingouin(double vitesse, const std::string& nom) : vitesseGlisse(vitesse), nom(nom) {}

    Pingouin(const Pingouin& autre) : vitesseGlisse(autre.vitesseGlisse), nom(autre.nom) {}

    void afficher() const {
        std::cout << "Nom: " << nom << ", Vitesse de glisse: " << vitesseGlisse << " m/s" << std::endl;
    }

    void setVitesseGlisse(double vitesse) {
        vitesseGlisse = vitesse;
    }

    double getVitesseGlisse() const {
        return vitesseGlisse;
    }

    void setNom(const std::string& nouveauNom) {
        nom = nouveauNom;
    }

    std::string getNom() const {
        return nom;
    }
};

int main() {
    Pingouin pingouin1(5.0, "Pingouin");
    pingouin1.afficher();

    Pingouin pingouin2(pingouin1);

    pingouin2.afficher();

    pingouin2.setVitesseGlisse(10.0);

    pingouin2.afficher();

    return 0;
}
