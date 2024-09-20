#include <iostream>

class Aquatique {
protected:
    double vitesseNage; 

public:

    Aquatique(double vitesse) : vitesseNage(vitesse) {}

    virtual void nage() const {
        std::cout << "ma vitesse de nage est a " << vitesseNage << " m/s." << std::endl;
    }

    double getVitesseNage() const {
        return vitesseNage;
    }

    void setVitesseNage(double vitesse) {
        vitesseNage = vitesse;
    }
};

class Terrestre {
protected:
    double vitesseMarche; 

public:
    
    Terrestre(double vitesse) : vitesseMarche(vitesse) {}

    
    virtual void marche() const {
        std::cout << " ma vitesse de marche est égale a  " << vitesseMarche << " m/s." << std::endl;
    }

    
    double getVitesseMarche() const {
        return vitesseMarche;
    }

    
    void setVitesseMarche(double vitesse) {
        vitesseMarche = vitesse;
    }
};


class Pingouin : public Aquatique, public Terrestre {
public:
    Pingouin(double vitesseNage, double vitesseMarche)
        : Aquatique(vitesseNage), Terrestre(vitesseMarche) {}

    void sePresenter() const {
        std::cout << "Je suis un pingouin. ";
        nage();
        marche();
    }

    void nage() const override {
        std::cout << "Je nage comme un pingouin à une vitesse de " << getVitesseNage() << " m/s." << std::endl;
    }

    void marche() const override {
        std::cout << "Je marche comme un pingouin à une vitesse de " << getVitesseMarche() << " m/s." << std::endl;
    }
};

int main() {
    Pingouin pingu(3.5, 1.0);

    pingu.sePresenter();

    return 0;
}
