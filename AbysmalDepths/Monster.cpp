#include"Includes.h"

Monster::Monster(string newName,int newLevel)
{
	name=newName;
	level=newLevel;
	damage=2*level;
	hp=50*level;
}

int Monster::getLevel()
{
	return level;
}

string Monster::getName()
{
	return name;
}

int Monster::getDamage()
{
	return damage;
}

int Monster::getHP()
{
	return hp;
}

void Monster::takeDamage(int newDamage)
{
	if(newDamage<=0)
		newDamage=1;
	hp-=newDamage;
}

Monster::Monster()
{

}