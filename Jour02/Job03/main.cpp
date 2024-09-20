#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class Pingouin {
private:
    double vitesseGlisse;
    std::string nom;

    static std::vector<std::shared_ptr<Pingouin>> colonies;

public:
    Pingouin() : vitesseGlisse(0.0), nom("Sans nom") {
        colonies.push_back(std::shared_ptr<Pingouin>(this));
    }

    Pingouin(double vitesse, const std::string& nom) : vitesseGlisse(vitesse), nom(nom) {
        colonies.push_back(std::shared_ptr<Pingouin>(this));
    }

    Pingouin(const Pingouin& autre) : vitesseGlisse(autre.vitesseGlisse), nom(autre.nom) {
        colonies.push_back(std::shared_ptr<Pingouin>(this));
    }

    ~Pingouin() {
        auto it = std::find_if(colonies.begin(), colonies.end(), [this](const std::shared_ptr<Pingouin>& ptr) {
            return ptr.get() == this;
        });

        if (it != colonies.end()) {
            colonies.erase(it);
        }
    }

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

    static void afficherColonies() {
        std::cout << "Colonies de pingouins :" << std::endl;
        for (const auto& pingouin : colonies) {
            pingouin->afficher();
        }
    }
};

std::vector<std::shared_ptr<Pingouin>> Pingouin::colonies;

int main() {
    auto p1 = std::make_shared<Pingouin>(5.0, "Pingouin 1");
    auto p2 = std::make_shared<Pingouin>(7.0, "Pingouin 2");
    auto p3 = std::make_shared<Pingouin>(6.5, "Pingouin 3");

    Pingouin::afficherColonies();


    p1.reset();
    p2.reset();
    p3.reset();


    std::cout << "Après destruction :" << std::endl;
    Pingouin::afficherColonies();

    return 0;
}
