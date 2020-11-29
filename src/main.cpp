#include "include.h"

int main() {
    Personagem *inimigo[5] {
        new Swordmaster("Denis DJ"),
        new    Marksman("MC Negao da BL"),
        new      Priest("MC Poze"),
        new       Thief("MC Lan"),
        new    Sorcerer("MC Lan Novamente")
    };

    geradorInimigos(inimigo);

    Personagem *player;
    criaPersonagem(player);

    player->printPersonagem();

    system("pause");

    for(int i = 0; i < 5; i++) {
        int exit = enterBattle(*player, *inimigo[i]);

        if (exit == -1) {
            system("cls");
            std::cout << "Fim de jogo!\n\n"
                      << "Muito obrigado por jogar." << std::endl;

            system("pause");

            return 0;
        }

        if(i < 4 ) {
            system("cls");
            std::cout << "Proxima luta!\n\n";
            system("pause");
        } else {
            system("cls");
            std::cout << "Parabens! Voce venceu o jogo!!!\n\n"
                      << "Muito obrigado por jogar!" << std::endl;
        }
    }


    return 0;
}