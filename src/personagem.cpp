#include "personagem.h"
#include <iostream>

// -----------------------------------------------------------------------------

// INICIA PERSONAGEM

void Personagem::allocatePoint() {
    // PROVISORIO
    int escolha;
    bool valida = 0;

    while(!valida) {
        valida = 1;

        system("cls");

        std::cout << "Voce subiu de nivel!\n"
                  << "Escolha uma habilidade para alocar seu ponto:\n\n"
                  << "1. Forca\n"
                  << "2. Destreza\n"
                  << "3. Agilidade\n"
                  << "4. Conhecimento\n"
                  << "5. Vitalidade\n\n";

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

void Personagem::levelUp() {
    nivel++;
    allocatePoint();
    updateStats();
}

void Personagem::attack(Personagem &inimigo) {
    if(inimigo.contadorDef == 0) {
        inimigo.takeHit(atk);
    } else {
        int dano = atk - inimigo.def;
        inimigo.takeHit(dano);
        inimigo.contadorDef = 0;
        inimigo.hp += 4;
    }
}

void Personagem::defend() {
    contadorDef = 1;
}

void Personagem::printPersonagem() {
    system("cls");

    std::cout << "Nome: " << name << "\n\n"
              << "Nivel: " << nivel << "\n"
              << "Classe: " << returnClassName() << "\n\n"
              << "For: " << str << "\n"
              << "Dex: " << dex << "\n"
              << "Agl: " << agl << "\n"
              << "Con: " << con << "\n"
              << "Vit: " << vit << "\n\n";
}

// FIM PERSONAGEM

// -----------------------------------------------------------------------------

// INICIO SWORDMASTER

void Swordmaster::updateStats() {
    hp = 100 + 20 * (nivel - 5) + vit * 5;

    atk = 10 + str * 3 + agl * 2;
    def = 3 + vit * 3 + str * 2;
}

// FIM SWORDMASTER

// -----------------------------------------------------------------------------

// INICIO MARKSMAN

void Marksman::updateStats() {
    hp = 100 + 20 * (nivel - 5) + vit * 5;

    atk = 10 + dex * 3 + agl * 2;
    def = 3 + vit * 3 + agl * 2;
}

// FIM MARKSMAN

// -----------------------------------------------------------------------------

// INICIO PRIEST

void Priest::updateStats() {
    hp = 100 + 20 * (nivel - 5) + vit * 5;

    atk = 10 + con * 3 + str * 2;
    def = 3 + vit * 3 + str * 2;
}

// FIM PRIEST

// -----------------------------------------------------------------------------

// INICIO THIEF

void Thief::updateStats() {
    hp = 100 + 20 * (nivel - 5) + vit * 5;

    atk = 10 + agl * 3 + dex * 2;
    def = 3 + vit * 3 + agl * 2;
}

// FIM THIEF

// -----------------------------------------------------------------------------

// INICIO SORCERER

void Sorcerer::updateStats() {
    hp = 100 + 20 * (nivel - 5) + vit * 5;

    atk = 10 + con * 3;
    def = 3 + vit * 3;    
}

// FIM SORCERER

// -----------------------------------------------------------------------------