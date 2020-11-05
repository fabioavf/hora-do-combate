#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <string>

class Personagem{
  	protected:
		std::string name;

		// stats

		int hp; // health points, hp = 100 + 20 * (nivel - 5) + vit * 5
		int sp; // skill points, sp = 100
		int ap; // action points, ap = 2 no primeiro round e +1 por round
		int xp; // experiencia ATUAL, teto de xp = 500 + 60 * (nivel - 5)
		int nivel; // nivel inicial = 5, sobe toda vez que alcança o teto

		int atk; 
		int def;

		// atributos

		int str = 1; // força
		int dex = 1; // destreza
		int agl = 1; // agilidade
		int	con = 1; // conhecimento
		int	vit = 1; // vitalidade

  	public:
		Personagem(std::string nome);
		Personagem(std::string nome, int forca, int destr, int agil, int conhec, int vital);
		virtual ~Personagem() = default;

		void allocatePoint();
		void updateStats();
		void xpCheck();

		virtual void attack(Personagem&) = 0;
		virtual void levelUp() = 0;
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