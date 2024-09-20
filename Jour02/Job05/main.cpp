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
        ajouterAuVecteur();
    }

    Pingouin(double vitesse, const std::string& nom) : vitesseGlisse(vitesse), nom(nom) {
        ajouterAuVecteur();
    }

    Pingouin(const Pingouin& autre) : vitesseGlisse(autre.vitesseGlisse), nom(autre.nom) {
        ajouterAuVecteur();
    }

    ~Pingouin() {
        auto it = std::find_if(colonies.begin(), colonies.end(), [this](const std::shared_ptr<Pingouin>& ptr) {
            return ptr.get() == this;
        });

        if (it != colonies.end()) {
            colonies.erase(it);
        }
    }

    void ajouterAuVecteur() {
        auto ptr = std::shared_ptr<Pingouin>(this);
        colonies.push_back(ptr);
        std::sort(colonies.begin(), colonies.end(), [](const std::shared_ptr<Pingouin>& a, const std::shared_ptr<Pingouin>& b) {
            return a->calculerTempsPiste() < b->calculerTempsPiste();
        });
    }

    void afficher() const {
        std::cout << "Nom: " << nom << ", Vitesse de glisse: " << vitesseGlisse << " m/s" << std::endl;
    }

    void setVitesseGlisse(double vitesse) {
        vitesseGlisse = vitesse;
        std::sort(colonies.begin(), colonies.end(), [](const std::shared_ptr<Pingouin>& a, const std::shared_ptr<Pingouin>& b) {
            return a->calculerTempsPiste() < b->calculerTempsPiste();
        });
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

    double calculerTempsPiste() const {
        const double pente = 15.0;    
        const double plat1 = 20.0;    
        const double nage = 50.0;     
        const double plat2 = 15.0;    

        double tempsGlisse = pente / vitesseGlisse;
        double tempsNage = nage / vitesseGlisse;
        double tempsPlat = (plat1 + plat2) / vitesseGlisse;

        return tempsGlisse + tempsNage + tempsPlat;
    }

    static void afficherTempsColonies() {
        std::cout << "Temps de parcours de la piste pour chaque pingouin :" << std::endl;
        for (const auto& pingouin : colonies) {
            double temps = pingouin->calculerTempsPiste();
            std::cout << "Nom: " << pingouin->getNom() << ", Temps: " << temps << " secondes" << std::endl;
        }
    }
};

std::vector<std::shared_ptr<Pingouin>> Pingouin::colonies;

int main() {
    auto p1 = std::make_shared<Pingouin>(5.0, "Pingouin 1");
    auto p2 = std::make_shared<Pingouin>(7.0, "Pingouin 2");
    auto p3 = std::make_shared<Pingouin>(6.5, "Pingouin 3");

    Pingouin::afficherTempsColonies();

    p1->setVitesseGlisse(8.0);

    std::cout << "Après modification de la vitesse de glisse du Pingouin 1 :" << std::endl;
    Pingouin::afficherTempsColonies();

    p1.reset();
    p2.reset();
    p3.reset();

    std::cout << "Après destruction :" << std::endl;
    Pingouin::afficherTempsColonies();

    return 0;
}
