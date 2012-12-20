#ifndef MONSTER_H
#define MONSTER_H

#include"Includes.h"

class Monster
{
	protected:
		string name;
		string type;
		int hp;
		int damage;
		int level;
	public:
		Monster();
		Monster(string newName, int newLevel);
		int getLevel();
		string getName();
		int getDamage();
		int getHP();
		void takeDamage(int newDamage);
};

#endif