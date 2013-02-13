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