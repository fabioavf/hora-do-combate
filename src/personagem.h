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

		int forca = 1,
		    destreza = 1,
		  	agilidade = 1,
			inteligencia = 1,
			vitalidade = 1;

  	public:
		Personagem();
		virtual ~Personagem() {}

		virtual void Attack(Personagem&);
		virtual void Defense();
		virtual void sobeNivel();
};

class Swordmaster : public Personagem{
	private:
		int atkBoost; //Determina a defesa adicional que personagens da classe Swordmaster possuem.
	public:
		Swordmaster();
		~Swordmaster() {}

		void Attack(Personagem&);
		void Defense();
		void sobeNivel();

		// Habilidades

};

class Marksman : public Personagem{
	private:
		int accuracy; //Muda para o valor 1 quando a função Aim eh chamada. Logo apos atacar, muda para 0 novamente.
		int aimdamage; //determina dano extra ao mirar (Aim).
		int headshot; //determina chance de um headshot, que mata o inimigo imediatamente.
	public:
		Marksman();
		~Marksman(){}
		void Aim(); //Faz com que o jogador perca 1 turno para "mirar", porem no outro turno o tiro tem dano extra.
};

class Priest : public Personagem{
	private:
		int hpregen; //Priests regeneram uma quantidade de HP todo turno, pois sao abencoados.
		int blessed; //Determina chance de evasiva, onde o golpe do inimigo eh anulado.
	public:
		Priest();
		~Priest(){}
};

class Thief : public Personagem{
	private:
		int criticalchance; //Chance de critico dos Thiefs.
		int poison; //Determina dano causado por veneno. Cada vez que o Thief acerta um inimigo, o dano do veneno aumenta.
	public:
		Thief();
		Thief(){}
};

class Sorcerer : public Personagem{
	private:
		int magicpower; //Determina um bonus de ataque que personagens da classe Sorcerer possuem.
		int devilchild; //Determina a chance de que o HP do sorcerer seja completamente regenerado durante um turno.
	public:
		Sorcerer();
		~Sorcerer(){}
};

#endif