/*
** FiFFTy Project, 2024
** Git
** File description:
** main
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <cctype>
#include <string>

size_t catMyNb(std::string str)
{
    std::string nb = "";
    for (size_t i = 0; i < str.size(); i++) {
        if (std::isdigit(str[i])) {
            if (nb.size() <= 1) {
                nb += str[i];
            } else {
                nb[1] = str[i];
            }
        }
    }
    if (nb.size() == 1)
            nb += nb;

    if (nb.empty()) {
        return (0);
    } else {
        try {
            return (std::stoi(nb));
        } catch (const std::invalid_argument& e) {
            std::cerr << "Erreur de conversion : " << e.what() << std::endl;
            return (0);
        }
    }
}

int main(void)
{
    const char* myFile = "file.txt";

    std::ifstream file(myFile);

    if (!file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
        return 1;
    }

    std::vector<std::string> lignes;
    std::string ligne;
    while (std::getline(file, ligne)) {
        lignes.push_back(ligne);
    }
    file.close();

    size_t pwd = 0;
    for (size_t i = 0; i < lignes.size(); ++i)
        pwd += catMyNb(lignes[i]);

    std::cout << "The PWD is: " << pwd << std::endl;
}
