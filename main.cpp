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

size_t verif(const std::string &temp)
{
    if (temp.compare("one") == 0)
        return (1);
    else if (temp.compare("two") == 0)
        return (2);
    else if (temp.compare("three") == 0)
        return (3);
    else if (temp.compare("four") == 0)
        return (4);
    else if (temp.compare("five") == 0)
        return (5);
    else if (temp.compare("six") == 0)
        return (6);
    else if (temp.compare("seven") == 0)
        return (7);
    else if (temp.compare("eight") == 0)
        return (8);
    else if (temp.compare("nine") == 0)
        return (9);
    else
        return (0);
}

size_t isDigitAlpha(const std::string &str, size_t &x)
{
    std::string temp = "";
    size_t t = x;
    while (t < str.size() && std::isalpha(str[t])) {
        temp += str[t];
        ++t;
        if (verif(temp) != 0) {
            break;
        }
    }
    return (verif(temp));
}

size_t catMyNb(const std::string &str)
{
    std::string nb = "";
    std::string fn = "";
    for (size_t i = 0; i < str.size(); ++i) {
        if (std::isdigit(str[i])) {
            nb += str[i];
        } else if (std::isalpha(str[i])) {
            size_t alphaValue = isDigitAlpha(str, i);

            if (alphaValue != 0)
                nb += std::to_string(alphaValue);
        }
    }
    if (nb.size() == 1)
        nb += nb;
    fn += nb[0];
    fn += nb[nb.size() - 1];
    if (fn.empty()) {
        return 0;
    } else {
        try {
            return std::stoi(fn);
        } catch (const std::invalid_argument &e) {
            std::cerr << "Erreur de conversion : " << e.what() << std::endl;
            return 0;
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
    for (size_t i = 0; i < lignes.size(); ++i) {
        pwd += catMyNb(lignes[i]);
    }
    std::cout << "The PWD is: " << pwd << std::endl;
}
