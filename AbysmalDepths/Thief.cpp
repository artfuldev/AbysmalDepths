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

string Thief::getClass()
{
	return "Thief";
}

Thief::Thief(string newName)
{
	name=newName;
	heroType=4;
	xp=level=0;
	xpMod=1;
	strength=3;
	maxHP=curHP=(int)(strength*2.5);
	dexterity=4;
	damageMultiplier=dexterity*1.2;
	critMultiplier=1.1;
	meleeDamage=3;
	meleeDamage=(int)(damageMultiplier*meleeDamage);
	meleeWeaponDamage=rangedWeaponDamage=rangedWeaponAmmo=0;
	chanceToBlock=2;
	block=1;
	chanceToEvade=4;
	endurance=3;
	maxStamina=curStamina=(int)(endurance*1.5);
	knowledge=3;
	chanceToEvade*=knowledge;
	chanceToBlock*=knowledge;
	chanceToCrit*=knowledge;
	stealth=4;
	chanceToEvade+=stealth;
}

void Thief::updateAttributes()
{
	strength+=(1*xpMod);
	endurance+=(1*xpMod);
	dexterity+=(2*xpMod);
	knowledge+=(1*xpMod);
	stealth+=(2*xpMod);
}

void Thief::updateStats()
{
	maxHP=curHP=(int)(strength*2.5);
	damageMultiplier=dexterity*1.2;
	critMultiplier+=(0.1*xpMod);
	meleeDamage+=(1*xpMod);
	meleeDamage=(int)(damageMultiplier*meleeDamage);
	meleeWeaponDamage=rangedWeaponDamage=rangedWeaponAmmo=0;
	chanceToBlock+=(3*xpMod);
	block+=(2*xpMod);
	chanceToEvade+=(4*xpMod);
	maxStamina=curStamina=(int)(endurance*1.5);
	chanceToEvade*=knowledge;
	chanceToBlock*=knowledge;
	chanceToCrit*=knowledge;
	chanceToEvade+=stealth;
}
