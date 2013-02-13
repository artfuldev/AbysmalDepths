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

string Assassin::getClass()
{
	return "Assassin";
}

Assassin::Assassin(string newName)
{
	name=newName;
	heroType=3;
	xp=level=0;
	xpMod=1;
	strength=2;
	maxHP=curHP=(int)(strength*2.5);
	dexterity=5;
	damageMultiplier=dexterity*1.5;
	critMultiplier=1.5;
	meleeDamage=5;
	meleeDamage=(int)(damageMultiplier*meleeDamage);
	meleeWeaponDamage=rangedWeaponDamage=rangedWeaponAmmo=0;
	chanceToBlock=1;
	block=1;
	chanceToEvade=5;
	endurance=2;
	maxStamina=curStamina=(int)(endurance*1.5);
	knowledge=5;
	chanceToEvade*=knowledge;
	chanceToBlock*=knowledge;
	chanceToCrit*=knowledge;
	stealth=5;
	chanceToEvade+=stealth;
}

void Assassin::updateAttributes()
{
	strength+=(1*xpMod);
	endurance+=(1*xpMod);
	dexterity+=(2*xpMod);
	knowledge+=(2*xpMod);
	stealth+=(1*xpMod);
}

void Assassin::updateStats()
{
	maxHP=curHP=(int)(strength*2.5);
	damageMultiplier=dexterity*1.5;
	critMultiplier+=(0.5*xpMod);
	meleeDamage+=(5*xpMod);
	meleeDamage=(int)(damageMultiplier*meleeDamage);
	meleeWeaponDamage=rangedWeaponDamage=rangedWeaponAmmo=0;
	chanceToBlock+=(1*xpMod);
	block+=(1*xpMod);
	chanceToEvade+=(5*xpMod);
	maxStamina=curStamina=(int)(endurance*1.5);
	chanceToEvade*=knowledge;
	chanceToBlock*=knowledge;
	chanceToCrit*=knowledge;
	chanceToEvade+=stealth;
}
