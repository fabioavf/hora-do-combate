#include "personagem.h"
#include <cstdlib>
#include <ctime>

int randGen(int lvl) {
    unsigned int temp;

    if(lvl == 0) {
        return 0;
    } else if(lvl == 1) {
        return 1;
    } else {
        temp = (rand() % 100) / 10;

        if(temp < lvl && temp > 0) {
            return temp;
        } else randGen(lvl);
    }
}

void geradorInimigos(Personagem *vetInimigos[]) {
    srand(time(NULL));

    for(int i = 0; i < 5; i++) {
        int nivel = 5 + i;
        unsigned int temp;

        vetInimigos[i]->setLvl(nivel);

        std::string classe = vetInimigos[i]->returnClassName();

        if(classe == "Swordmaster") {
            temp = randGen(nivel);
            vetInimigos[i]->setStr(temp);
            nivel -= temp;

            vetInimigos[i]->setDex(0);
            
            temp = randGen(nivel);
            vetInimigos[i]->setAgl(temp);
            nivel -= temp;
            
            vetInimigos[i]->setCon(0);

            temp = randGen(nivel);
            vetInimigos[i]->setVit(temp);
            nivel -= temp;

            if(nivel != 0) {
                vetInimigos[i]->setStr(vetInimigos[i]->getStr() + nivel);
            }
        } else if (classe == "Marksman") {
            vetInimigos[i]->setStr(0);

            temp = randGen(nivel);
            vetInimigos[i]->setDex(temp);
            nivel -= temp;
            
            temp = randGen(nivel);
            vetInimigos[i]->setAgl(temp);
            nivel -= temp;
            
            vetInimigos[i]->setCon(0);

            temp = randGen(nivel);
            vetInimigos[i]->setVit(temp);
            nivel -= temp;

            if(nivel != 0) {
                vetInimigos[i]->setDex(vetInimigos[i]->getDex() + nivel);
            }
        } else if (classe  == "Thief") {
            vetInimigos[i]->setStr(0);

            temp = randGen(nivel);
            vetInimigos[i]->setDex(temp);
            nivel -= temp;
            
            temp = randGen(nivel);
            vetInimigos[i]->setAgl(temp);
            nivel -= temp;
            
            vetInimigos[i]->setCon(0);

            temp = randGen(nivel);
            vetInimigos[i]->setVit(temp);
            nivel -= temp;

            if(nivel != 0) {
                vetInimigos[i]->setAgl(vetInimigos[i]->getAgl() + nivel);
            }
        } else if (classe == "Priest") {
            temp = randGen(nivel);
            vetInimigos[i]->setStr(temp);
            nivel -= temp;

            vetInimigos[i]->setDex(0);
            
            vetInimigos[i]->setAgl(0);
            
            temp = randGen(nivel);
            vetInimigos[i]->setCon(temp);
            nivel -= temp;

            temp = randGen(nivel);
            vetInimigos[i]->setVit(temp);
            nivel -= temp;

            if(nivel != 0) {
                vetInimigos[i]->setVit(vetInimigos[i]->getVit() + nivel);
            }
        } else if (classe == "Sorcerer") {
            vetInimigos[i]->setStr(0);

            vetInimigos[i]->setDex(0);
            
            vetInimigos[i]->setAgl(0);
            
            temp = randGen(nivel);
            vetInimigos[i]->setCon(temp);
            nivel -= temp;

            temp = randGen(nivel);
            vetInimigos[i]->setVit(temp);
            nivel -= temp;

            if(nivel != 0) {
                vetInimigos[i]->setCon(vetInimigos[i]->getCon() + nivel);
            }
        } else if (classe == "Personagem") {
            std::cout << "Isso nao deveria acontecer" << std::endl; 
        }
    }
}