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

string Nomad::getClass()
{
	return "Nomad";
}

Nomad::Nomad(string newName)
{
	name=newName;
	heroType=2;
	xp=level=0;
	xpMod=1;
	strength=4;
	maxHP=curHP=(int)(strength*2.5);
	dexterity=1;
	damageMultiplier=dexterity*1.3;
	critMultiplier=1.3;
	meleeDamage=2;
	meleeDamage=(int)(damageMultiplier*meleeDamage);
	meleeWeaponDamage=rangedWeaponDamage=rangedWeaponAmmo=0;
	chanceToBlock=3;
	block=2;
	chanceToEvade=2;
	endurance=4;
	maxStamina=curStamina=(int)(endurance*1.5);
	knowledge=4;
	chanceToEvade*=knowledge;
	chanceToBlock*=knowledge;
	chanceToCrit*=knowledge;
	stealth=2;
	chanceToEvade+=stealth;
}

void Nomad::updateAttributes()
{
	strength+=(2*xpMod);
	endurance+=(1*xpMod);
	dexterity+=(1*xpMod);
	knowledge+=(2*xpMod);
	stealth+=(1*xpMod);
}

void Nomad::updateStats()
{
	maxHP=curHP=(int)(strength*2.5);
	damageMultiplier=dexterity*1.3;
	critMultiplier+=(0.3*xpMod);
	meleeDamage+=(2*xpMod);
	meleeDamage=(int)(damageMultiplier*meleeDamage);
	meleeWeaponDamage=rangedWeaponDamage=rangedWeaponAmmo=0;
	chanceToBlock+=(3*xpMod);
	block+=(2*xpMod);
	chanceToEvade+=(2*xpMod);
	maxStamina=curStamina=(int)(endurance*1.5);
	chanceToEvade*=knowledge;
	chanceToBlock*=knowledge;
	chanceToCrit*=knowledge;
	chanceToEvade+=stealth;
}
