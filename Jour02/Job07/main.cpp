#include <string>
#include <map>
#include <iostream>

class Pingouin {
private:
    std::map<std::string, int> skills; 

public:
    void addSkill(const std::string& skillName, int level) {
        skills[skillName] = level;
        std::cout << "Compétence ajoutée: " << skillName << " avec niveau " << level << std::endl;
    }

    void modifySkill(const std::string& skillName, int newLevel) {
        if (skills.find(skillName) != skills.end()) {
            skills[skillName] = newLevel;
            std::cout << "Niveau de la compétence " << skillName << " modifié à " << newLevel << std::endl;
        } else {
            std::cout << "Compétence " << skillName << " non trouvée!" << std::endl;
        }
    }

    void removeSkill(const std::string& skillName) {
        if (skills.erase(skillName) > 0) {
            std::cout << "Compétence " << skillName << " supprimée." << std::endl;
        } else {
            std::cout << "Compétence " << skillName << " non trouvée!" << std::endl;
        }
    }

    void listSkills() const {
        if (skills.empty()) {
            std::cout << "Aucune compétence disponible." << std::endl;
        } else {
            std::cout << "Liste des compétences:" << std::endl;
            for (const auto& skill : skills) {
                std::cout << "- " << skill.first << " : Niveau " << skill.second << std::endl;
            }
        }
    }
};
