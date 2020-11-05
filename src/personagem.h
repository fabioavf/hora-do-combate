#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>
#include <string>

using namespace std;

class Personagem{
  	protected:
		string name;
		int hp;
		int sp;
		int ap;
		int xp;
		int nivel;

		int str = 1, // força
		    dex = 1, // destreza
		  	agl = 1, // agilidade
			con = 1, // conhecimento
			vit = 1; // vitalidade

  	public:
		Personagem();
		virtual ~Personagem() = default;

		virtual void attack(Personagem&);
		virtual void levelUp();
};

class Swordmaster : public Personagem{
	private:
		int atkBoost = 0; // variável que se altera com o uso da habilidade atk boost do Swordmaster

	public:
		Swordmaster();
		~Swordmaster() = default;

		void attack(Personagem&);
		void levelUp();

		// Habilidades

		// Estocada
		// Atk Boost
		// Sacrifício

};

class Marksman : public Personagem{
	private:
		int dexBoost = 0; // variável que se altera com o uso da habilidade dex boost do Marksman

	public:
		Marksman();
		~Marksman() = default;

		// Habilidades

		// Frechinha com powerup
		// Dex Boost
		// Legolas (habilidade OPzuda)
};

class Priest : public Personagem{
	private:
		// Nada, por enquanto

	public:
		Priest();
		~Priest(){}

		// Habilidades

		// Magiazinha melhor
		// Cura HP
		// Exorcismo
};

class Thief : public Personagem{
	private:
		int aglBoost = 0; // variável que se altera com o uso da habilidade agl boost do Thief

	public:
		Thief();
		Thief() = default;

		// Habilidades
		
		// Ataque duplo
		// Agl Boost
		// Backstab
};

class Sorcerer : public Personagem{
	private:
		int intBoost; // variável que se altera com o uso da habilidade agl boost do Thief

	public:
		Sorcerer();
		~Sorcerer() = default;

		// Habilidades

		// Magiazinha melhor
		// Int Boost
		// Jaula Mágica
};

#endif