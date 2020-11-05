#include "personagem.h"
#include <iostream>

Personagem::Personagem(std::string nome) {name = nome;}

Personagem::Personagem(std::string nome, int forca, int destr, int agil, int conhec, int vital) {
    name = nome;
    str = forca;
    dex = destr;
    agl = agil;
    con = conhec;
    vit = vital;
}

void Personagem::allocatePoint() {
    // PROVISORIO
    int escolha;
    bool valida = 0;

    while(!valida) {
        valida = 1;

        std::cout << "Escolha uma habilidade para alocar seu ponto:\n\n"
                  << "1. Forca\n"
                  << "2. Destreza\n"
                  << "3. Agilidade\n"
                  << "4. Conhecimento\n"
                  << "5. Vitalidade\n";

        std::cout << "> ";
        std::cin >> escolha;

        switch(escolha) {
            case 1:
                str++;
                break;
            case 2:
                dex++;
                break;
            case 3:
                agl++;
                break;
            case 4:
                con++;
                break;
            case 5:
                vit++;
                break;
            default:
                valida = 0;
                std::cout << "Escolha invalida.\n";
                break;
        }
    }
}

void Personagem::updateStats() {
    hp = 100 + 20 * (nivel - 5) + vit * 5;
    
}

void Personagem::xpCheck() {
    int tetoXP = 500 + 60 * (nivel - 5);

    if(xp >= tetoXP) {
        xp = 0;
        nivel++;

        allocatePoint();
    }
}