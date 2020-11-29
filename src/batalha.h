#include <iostream>
#include <cstdlib>
#include <ctime>
#include "personagem.h"

int enterBattle(Personagem& player, Personagem& inimigo) {
    player.updateStats();
    inimigo.updateStats();

    bool win  = 0; int op, k{0}, danoPlayer, danoInimigo;

    for(;;) { // ever
        system("cls");

        std::cout << "|---------------------------------------------------|\n";
        std::cout << "|                 Inicio de Batalha!                |\n";
    	std::cout << "|---------------------------------------------------|\n";

        std::cout << "  Turno " << k + 1 << "\n\n";

        std::cout << "  HP de " << player.getName() << ": " << player.getHP() << "\n";
        std::cout << "  HP de " << inimigo.getName() << ": " << inimigo.getHP() << "\n\n";

        if(k != 0) {
            std::cout << player.getName() << " recebeu " << danoInimigo << " de dano!\n";
            std::cout << inimigo.getName() << " recebeu " << danoPlayer << " de dano!\n\n";
        }

        danoPlayer = inimigo.getHP();
        danoInimigo = player.getHP();

        bool validOp = 0;

        while(!validOp) {
            std::cout << "  1. Atacar\n"
                      << "  2. Defender\n\n"
                      << "  > ";
                      
            std::cin >> op;

            switch (op) {
            case 1:
                player.attack(inimigo);
                validOp = 1;
                break;
            case 2:
                player.defend();
                validOp = 1;
                break;
            default:
                std::cout << "\nInsira um comando valido." << std::endl << std::endl;
                break;
            }
        }

        srand(time(NULL));

        op = rand() % 100;

        if (op <= 70) {
                inimigo.attack(player);
        } else {
                inimigo.defend();
        }

        danoPlayer -= inimigo.getHP();
        danoInimigo -= player.getHP();
        k++;

        std::cout << std::flush;

        if(inimigo.getHP() <= 0) {
            system("cls");
            std::cout << "Voce venceu a luta! Parabens!\n\n";
            system("pause");
            win = 1;
            break;
        } else if (player.getHP() <= 0) {
            system("cls");
            std::cout << "Voce perdeu a luta!\n\n";
            system("pause");
            break;
        }
    }

    if(win) {
        player.levelUp();
        return 0;
    } else {
        bool validOp = 0;
        while (!validOp) {
            system("cls");

            std::cout << "Voce deseja continuar jogando e repetir a luta?\n"
                    << "1. Sim\n"
                    << "2. Nao\n\n"
                    << "> ";

            std::cin >> op;

            if (op == 1 || op == 2)
                break;
            else {
                std::cout << "Insira novamente...\n";
                getchar();
            }
        }

        switch (op) {
        case 1:
            enterBattle(player, inimigo);
            return 0;
            break;
        case 2:
            return -1;
            break;
        default:
            std::cout << "Isso nao deveria acontecer" << std::endl;
            break;
        }
    }
        


}