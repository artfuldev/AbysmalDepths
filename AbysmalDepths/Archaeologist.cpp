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

string Archaeologist::getClass()
{
	return "Archaeologist";
}

Archaeologist::Archaeologist(string newName)
{
	name=newName;
	heroType=5;
	xp=level=0;
	xpMod=1;
	strength=3;
	maxHP=curHP=(int)(strength*2.5);
	dexterity=3;
	damageMultiplier=dexterity*1.4;
	critMultiplier=1.4;
	meleeDamage=2;
	meleeDamage=(int)(damageMultiplier*meleeDamage);
	meleeWeaponDamage=rangedWeaponDamage=rangedWeaponAmmo=0;
	chanceToBlock=5;
	block=1;
	chanceToEvade=5;
	endurance=5;
	maxStamina=curStamina=(int)(endurance*1.5);
	knowledge=5;
	chanceToEvade*=knowledge;
	chanceToBlock*=knowledge;
	chanceToCrit*=knowledge;
	stealth=3;
	chanceToEvade+=stealth;
}

void Archaeologist::updateAttributes()
{
	strength+=(1*xpMod);
	endurance+=(2*xpMod);
	dexterity+=(1*xpMod);
	knowledge+=(2*xpMod);
	stealth=+(1*xpMod);
}

void Archaeologist::updateStats()
{
	maxHP=curHP=(int)(strength*2.5);
	damageMultiplier=dexterity*1.4;
	critMultiplier+=(0.4*xpMod);
	meleeDamage+=(2*xpMod);
	meleeDamage=(int)(damageMultiplier*meleeDamage);
	meleeWeaponDamage=rangedWeaponDamage=rangedWeaponAmmo=0;
	chanceToBlock+=(5*xpMod);
	block+=(1*xpMod);
	chanceToEvade+=(5*xpMod);
	maxStamina=curStamina=(int)(endurance*1.5);
	chanceToEvade*=knowledge;
	chanceToBlock*=knowledge;
	chanceToCrit*=knowledge;
	chanceToEvade+=stealth;
}
