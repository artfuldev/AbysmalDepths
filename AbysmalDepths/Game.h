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