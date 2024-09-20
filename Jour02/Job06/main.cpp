#include <iostream>
#include <vector>
#include <algorithm> 

class LieuxDeRencontre {
private:
    std::vector<std::string> lieux;

public:
    LieuxDeRencontre() {
        lieux.push_back("lac");
        lieux.push_back("glacier");
        lieux.push_back("banquise");
        lieux.push_back("côte");
        lieux.push_back("île");
        lieux.push_back("océan");
    }

    void ajouterLieu(const std::string& lieu) {
        if (std::find(lieux.begin(), lieux.end(), lieu) == lieux.end()) {
            lieux.push_back(lieu);
        } else {
            std::cout << "Le lieu '" << lieu << "' est déjà présent dans la liste." << std::endl;
        }
    }
    void retirerLieu(const std::string& lieu) {
        auto it = std::find(lieux.begin(), lieux.end(), lieu);
        if (it != lieux.end()) {
            lieux.erase(it);
        } else {
            std::cout << "Le lieu '" << lieu << "' n'est pas dans la liste." << std::endl;
        }
    }
    void afficherLieux() const {
        std::cout << "Lieux de rencontre des pingouins :" << std::endl;
        for (const auto& lieu : lieux) {
            std::cout << "- " << lieu << std::endl;
        }
    }
};

int main() {
    LieuxDeRencontre lieux;
    lieux.afficherLieux();
    lieux.ajouterLieu("plage");
    lieux.retirerLieu("lac");
    lieux.afficherLieux();
    
    return 0;
}
