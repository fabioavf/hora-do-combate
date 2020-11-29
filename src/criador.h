#include <iostream>
#include "personagem.h"

void criaPersonagem(Personagem*& pers) {
    int classe; std::string nome;

    system("cls");
	
	std::cout << "|---------------------------------------------------|\n";
	std::cout << "|               Criador de Personagem               |\n";
	std::cout << "|---------------------------------------------------|\n\n";


	std::cout << "  Escolha seu nome:\n\n"
			  << "  > ";
	std::cin >> nome;

	system("cls");

	std::cout << "|---------------------------------------------------|\n";
	std::cout << "|               Criador de Personagem               |\n";
	std::cout << "|                                                   |\n";
    std::cout << "|            Escolha sua classe (1 a 5):            |\n";
	std::cout << "|---------------------------------------------------|\n";
	std::cout << "|                                                   |\n";
	std::cout << "|        CLASSE    FOR    DEX    AGL    CON    VIT  |\n";
	std::cout << "|                                                   |\n";
	std::cout << "|  1 ESPADACHIM      3      0      1      0      2  |\n";
	std::cout << "|                                                   |\n";
	std::cout << "|  2   ATIRADOR      0      3      2      0      1  |\n";
	std::cout << "|                                                   |\n";
	std::cout << "|  3     LADRAO      0      2      3      0      1  |\n";
	std::cout << "|                                                   |\n";
	std::cout << "|  4      PADRE      1      0      0      2      3  |\n";
	std::cout << "|                                                   |\n";
	std::cout << "|  5       MAGO      0      0      0      4      2  |\n";
	std::cout << "|                                                   |\n";
	std::cout << "|---------------------------------------------------|\n\n";

	bool isValid = 0;

	while (!isValid) {
		std::cout << "  Escolha uma classe:\n\n";
		std::cout << "  > ";
		
		std::cin >> classe;

		switch(classe) {
			case 1: {
				pers = new Swordmaster(nome, 5, 3, 0, 1, 0, 2);
				isValid = 1;
				break;
			}
			case 2: {
				pers = new Marksman(nome, 5, 0, 3, 2, 0, 1);
				isValid = 1;
				break;
			}
			case 3: {
				pers = new Thief(nome, 5, 0, 2, 3, 0, 1);
				isValid = 1;
				break;
			}
			case 4: {
				pers = new Priest(nome, 5, 1, 0, 0, 2, 3);
				isValid = 1;
				break;
			}
			case 5: {
				pers = new Sorcerer(nome, 5, 0, 0, 0, 4, 2);
				isValid = 1;
				break;
			}
			default: {
				std::cout << "\nEntrada incorreta. Tente novamente\n\n";
				break;
			}
		}
	}
}