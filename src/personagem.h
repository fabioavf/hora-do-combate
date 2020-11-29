#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>

class Personagem{
  	protected:
		std::string name;

		// stats

		int hp; // health points, hp = 100 + 20 * (nivel - 5) + vit * 5
		int nivel; // nivel inicial = 5, sobe toda vez que ganha uma luta

		int atk; // quanto de dano dá no oponente
		int def; // quanto de dano do oponente é mitigado

		// atributos

		int str = 0; // força
		int dex = 0; // destreza
		int agl = 0; // agilidade
		int con = 0; // conhecimento
		int vit = 0; // vitalidade

		bool contadorDef = 0;

  	public:
	  	Personagem() = default;
		Personagem(std::string n, int lvl, int st, int dx, int ag, int cn, int vt) {
			name  = n; nivel = lvl; str = st; dex = dx; agl = ag; con = cn; vit = vt;
		};
		Personagem(std::string n) : Personagem(n, 0, 0, 0, 0, 0, 0) { };
		virtual ~Personagem() = default;

		void setPoints();
		void allocatePoint();
		void levelUp();
		virtual void updateStats();

		std::string getName() {return name;};
		int getAtk() {return atk;};
		int getDef() {return def;};
		int getHP() {return hp;};

		int getLvl() {return nivel;};
		int getStr() {return str;};
		int getDex() {return dex;};
		int getAgl() {return agl;};
		int getCon() {return con;};
		int getVit() {return vit;};

		void setLvl(int lvl) {nivel = lvl;};
		void setStr(int st) {str = st;};
		void setDex(int dx) {dex = dx;};
		void setAgl(int ag) {agl = ag;};
		void setCon(int cn) {con = cn;};
		void setVit(int vt) {vit = vt;};


		void takeHit(int dano) {
			hp = hp - dano;
		};

		void attack(Personagem&);
		void defend();

		virtual std::string returnClassName() {return "Personagem";};

		void printPersonagem();
};

class Swordmaster : public Personagem{
	public:
		Swordmaster() = default;
		Swordmaster(std::string n, int lvl, int st, int dx, int ag, int cn, int vt) 
			: Personagem(n, lvl, st, dx, ag, cn, vt) { };
		Swordmaster(std::string n) : Swordmaster(n, 0, 0, 0, 0, 0, 0) { };
		~Swordmaster() = default;

		void updateStats();

		std::string returnClassName() {return "Swordmaster";};

};

class Marksman : public Personagem{
	public:
		Marksman() = default;
		Marksman(std::string n, int lvl, int st, int dx, int ag, int cn, int vt) 
			: Personagem(n, lvl, st, dx, ag, cn, vt) { };
		Marksman(std::string n) : Marksman(n, 0, 0, 0, 0, 0, 0) { };
		~Marksman() = default;

		void updateStats();

		std::string returnClassName() {return "Marksman";};
};

class Priest : public Personagem{
	public:
		Priest() = default;
		Priest(std::string n, int lvl, int st, int dx, int ag, int cn, int vt) 
			: Personagem(n, lvl, st, dx, ag, cn, vt) { };
		Priest(std::string n) : Priest(n, 0, 0, 0, 0, 0, 0) { };
		~Priest() = default;

		void updateStats();

		std::string returnClassName() {return "Priest";};
};

class Thief : public Personagem{
	public:
		Thief() = default;
		Thief(std::string n, int lvl, int st, int dx, int ag, int cn, int vt) 
			: Personagem(n, lvl, st, dx, ag, cn, vt) { };
		Thief(std::string n) : Thief(n, 0, 0, 0, 0, 0, 0) { };
		~Thief() = default;

		void updateStats();

		std::string returnClassName() {return "Thief";};
};

class Sorcerer : public Personagem{
	public:
		Sorcerer() = default;
		Sorcerer(std::string n, int lvl, int st, int dx, int ag, int cn, int vt) 
			: Personagem(n, lvl, st, dx, ag, cn, vt) { };
		Sorcerer(std::string n) : Sorcerer(n, 0, 0, 0, 0, 0, 0) { };
		~Sorcerer() = default;

		void updateStats();

		std::string returnClassName() {return "Sorcerer";};
};

#endif