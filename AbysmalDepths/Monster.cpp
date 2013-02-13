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