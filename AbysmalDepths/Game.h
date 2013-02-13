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

#ifndef GAME_H
#define GAME_H

#include"Includes.h"

class Game
{
	Hero *userHero;
	Monster *newMonster;
	int errorFlag;
	int endFlag;
	int gameEndFlag;
	int heroCreated;
public:
	void gameSetup();
	void gameShutDown();
	void gameRun();
	void initStory();
	void gameEnd();
	void printStoryEvent(string fileName);
	void tagReplace(string passedString, string newTag, string newReplaceString);
	string decryptFile(string inFileName);
	void combat(Hero& newHero, Monster& newMonster);
	void escape(Hero& newHero, Monster& newMonster);
	Game();
	~Game();
};

#endif