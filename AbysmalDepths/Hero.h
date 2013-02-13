/*
"Abysmal Depths" is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

"Abysmal Depths" is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with "Abysmal Depths".  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef HERO_H
#define HERO_H

#include"Includes.h"

class Hero
{
	protected:
		string name;
		int heroType;
		int maxHP;
		int curHP;
		int xp;
		int xpToLevelUp;
		int xpMod;
		int level;
		int chanceToCrit;
		float critMultiplier;
		int chanceToEvade;
		int chanceToBlock;
		int block;
		int meleeDamage;
		int meleeWeaponDamage;
		int rangedWeaponDamage;
		int rangedWeaponAmmo;
		int dexterity;
		int strength;
		int endurance;
		int stealth;
		float damageMultiplier;
		int maxStamina;
		int curStamina;
		int knowledge;
	public:
		Hero();
		Hero(string newName);
		static Hero* Create(string newName, int classChoice);
		string getName();
		virtual string getClass();
		void levelUp();
		void checkXP();
		virtual void updateAttributes();
		virtual void updateStats();
		void displayStatus();
		int getHeroType();
		int getMaxHP();
		int getCurHP();
		int getXp();
		int getXpToLevelUp();
		int getXpMod();
		int getLevel();
		int getChanceToCrit();
		float getCritMultiplier();
		int getChanceToEvade();
		int getChanceToBlock();
		int getBlock();
		int getMeleeDamage();
		int getMeleeWeaponDamage();
		int getRangedWeaponDamage();
		int getRangedWeaponAmmo();
		int getDexterity();
		int getStrength();
		int getEndurance();
		float getDamageMultiplier();
		int getMaxStamina();
		int getCurStamina();
		int getKnowledge();
		void takeDamage(int newDamage);
		void updateXP(int newXP);
		int getStealth();
		~Hero();
};

class Warrior:public Hero
{
	public:
		Warrior();
		Warrior(string newName);
		virtual string getClass();
		virtual void updateAttributes();
		virtual void updateStats();
		~Warrior();
};

class Nomad:public Hero
{
	public:
		Nomad();
		Nomad(string newName);
		virtual string getClass();
		virtual void updateAttributes();
		virtual void updateStats();
		~Nomad();
};

class Assassin:public Hero
{
	public:
		Assassin();
		Assassin(string newName);
		virtual string getClass();
		virtual void updateAttributes();
		virtual void updateStats();
		~Assassin();
};

class Thief:public Hero
{
	public:
		Thief();
		Thief(string newName);
		virtual string getClass();
		virtual void updateAttributes();
		virtual void updateStats();
		~Thief();
};

class Archaeologist:public Hero
{
	public:
		Archaeologist();
		Archaeologist(string newName);
		virtual string getClass();
		virtual void updateAttributes();
		virtual void updateStats();
		~Archaeologist();
};
#endif