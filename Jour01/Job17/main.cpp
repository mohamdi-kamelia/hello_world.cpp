#include <iostream>
#include <cstdlib> 
#include <ctime>   

enum Specialite {
    IA,
    Web,
    Logiciel,
    Systeme_Immersif,
    Cybersecurite,
    NombreDeSpecialites 
};

void afficherSpecialite(Specialite s, int nombreEtudiants) {
    std::string nomSpecialite;

    switch (s) {
        case IA:
            nomSpecialite = "Intelligence Artificielle (IA)";
            break;
        case Web:
            nomSpecialite = "Developpement Web";
            break;
        case Logiciel:
            nomSpecialite = "Ingenierie Logicielle";
            break;
        case Systeme_Immersif:
            nomSpecialite = "Systemes Immersifs";
            break;
        case Cybersecurite:
            nomSpecialite = "Cyber securite";
            break;
        default:
            nomSpecialite = "Inconnue";
            break;
    }

    std::cout << nomSpecialite << " : " << nombreEtudiants << " etudiants." << std::endl;
}

int main() {
    std::srand(std::time(0));
    int nombreEtudiants[NombreDeSpecialites];

    for (int i = 0; i < NombreDeSpecialites; ++i) {
        nombreEtudiants[i] = std::rand() % 55 + 12; 
    }

    for (int i = 0; i < NombreDeSpecialites; ++i) {
        afficherSpecialite(static_cast<Specialite>(i), nombreEtudiants[i]);
    }

    return 0;
}
