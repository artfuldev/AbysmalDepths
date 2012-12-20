#include "Includes.h"

Hero::Hero(string newName)
{
	name=newName;
	heroType=0;
#ifdef DEBUG_MODE
	cout<<name<<" created.\n";
#endif
}

void Hero::checkXP()
{
	if((xp>=xpMod)&&(xp%xpMod>=0))
	{
		levelUp();
	}
}

void Hero::levelUp()
{
	level++;
	xp-=xpMod;
	updateAttributes();
	updateStats();
	xpMod++;
	cout<<STAT_UPDT<<"You have leveled up...\n";
}

void Hero::updateAttributes()
{

}

void Hero::updateStats()
{

}

Hero* Hero::Create(string newName, int classChoice)
{
	switch(classChoice)
	{
		case 1:
			return new Warrior(newName);
		case 2:
			return new Nomad(newName);
		case 3:
			return new Assassin(newName);
		case 4:
			return new Thief(newName);
		case 5:
			return new Archaeologist(newName);
		default:
			return new Hero(newName);
	}
}

string Hero::getName()
{
	return name;
}

string Hero::getClass()
{
	switch(heroType)
	{
		case 1:
			return "Warrior";
		case 2:
			return "Nomad";
		case 3:
			return "Assassin";
		case 4:
			return "Thief";
		case 5:
			return "Archaeologist";
		default:
			return "Unknown";
	}
}

Hero::Hero()
{
#ifdef DEBUG_MODE
	cout<<"Hero created...";
#endif
}

Hero::~Hero()
{
#ifdef DEBUG_MODE
	cout<<"Hero deleted...";
	_getch();
#endif
}

void Hero::displayStatus()
{
	cout<<CLRSCR;
	cout<<getName()<<", a Level "<<level<<" "<<getClass()<<"...\n";
	cout<<"Health: "<<curHP<<"/"<<maxHP<<"\tStamina: "<<curStamina<<"/"<<maxStamina<<endl;
	cout<<"The rest of the details are either unknown or cannot be quantified or are classified..."<<endl;
	for(int i=0;i<80;i++)
		cout<<"_";
	_getch();
}

int Hero::getHeroType()
{
	return heroType;
}

int Hero::getMaxHP()
{
	return maxHP;
}

int Hero::getCurHP()
{
	return curHP;
}

int Hero::getXp()
{
	return xp;
}

int Hero::getXpToLevelUp()
{
	return xpToLevelUp;
}

int Hero::getXpMod()
{
	return xpMod;
}

int Hero::getLevel()
{
	return level;
}

int Hero::getChanceToCrit()
{
	return chanceToCrit;
}

float Hero::getCritMultiplier()
{
	return critMultiplier;
}

int Hero::getChanceToEvade()
{
	return chanceToEvade;
}

int Hero::getChanceToBlock()
{
	return chanceToBlock;
}

int Hero::getBlock()
{
	return block;
}

int Hero::getMeleeDamage()
{
	return meleeDamage;
}

int Hero::getMeleeWeaponDamage()
{
	return meleeWeaponDamage;
}

int Hero::getRangedWeaponDamage()
{
	return rangedWeaponDamage;
}

int Hero::getRangedWeaponAmmo()
{
	return rangedWeaponAmmo;
}

int Hero::getDexterity()
{
	return dexterity;
}

int Hero::getStrength()
{
	return strength;
}

int Hero::getEndurance()
{
	return endurance;
}

float Hero::getDamageMultiplier()
{
	return damageMultiplier;
}

int Hero::getMaxStamina()
{
	return maxStamina;
}

int Hero::getCurStamina()
{
	return curStamina;
}

int Hero::getKnowledge()
{
	return knowledge;
}

void Hero::takeDamage(int newDamage)
{
	if(newDamage<0)
		newDamage=1;
	curHP-=newDamage;
}

void Hero::updateXP(int newXP)
{
	xp+=newXP;
	checkXP();
}

int Hero::getStealth()
{
	return stealth;
}