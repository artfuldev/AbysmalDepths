#include"Includes.h"

Game::Game()
{
#ifdef DEBUG_MODE
	cout<<"Game created...";
	_getch();
#endif
	userHero=new Hero("a nobody");
	newMonster=new Monster();
	errorFlag=0;
	endFlag=0;
	gameEndFlag=0;
	heroCreated=0;
}

void Game::gameRun()
{
	gameSetup();
}

void Game::combat(Hero& newHero,Monster& newMonster)
{
	int playerDamage,monsterDamage;
	while(true)
	{
		playerDamage=newMonster.getDamage()-newHero.getBlock();
		cout<<endl<<newMonster.getName()<<" damages you for "<<playerDamage<<" HP...\n";
		newHero.takeDamage(playerDamage);
		if(newHero.getCurHP()<=0)
			gameEnd();
		cout<<newMonster.getName()<<" HP: "<<newMonster.getHP()<<"\t\t"<<newHero.getName()<<" HP: "<<newHero.getCurHP();
		_getch();
		monsterDamage=newHero.getMeleeDamage();
		newMonster.takeDamage(monsterDamage);
		if(newMonster.getHP()<=0)
		{
			cout<<endl<<"You deliver the killing blow to "<<newMonster.getName()<<"\n";
			newHero.updateXP(newMonster.getLevel());
			return;
		}
		cout<<endl<<"You damage "<<newMonster.getName()<<" for "<<monsterDamage<<" HP...\n";
		cout<<newMonster.getName()<<" HP: "<<newMonster.getHP()<<"\t\t"<<newHero.getName()<<" HP: "<<newHero.getCurHP();
		_getch();
	}
}

void Game::escape(Hero& newHero,Monster& newMonster)
{
	if(newHero.getStealth()>(5*newMonster.getLevel()))
	{
		cout<<"You have escaped from "<<newMonster.getName()<<" with your high stealth...";
		if(newHero.getStealth()>(10*newMonster.getLevel()))
			cout<<"\nIt was a piece of cake considering your stealth abilities...";
		return;
	}
	cout<<"Your insuffient training in such stealthy activities has let you down..\n The monster sees you and begins to attack...";
	_getch();
	combat(newHero,newMonster);
}

void Game::gameEnd()
{
	cout<<endl;
	if(!endFlag)
	{
		//Check if no errors->User died by choice
		if(errorFlag==0)
		{
			cout<<STAT_UPDT<<"You, "<<userHero->getName();
			if(userHero->getClass()!="Unknown")
				cout<<" the "<<userHero->getClass();
			cout<<", have died...";
		}
		//Check if Known Error->Display errorMsg
		if(errorFlag==1)
			cout<<ERROR_STORY;
		if(errorFlag==2)
			cout<<ERROR_CHOICE;
		if(errorFlag==3)
			cout<<ERROR_CHOOSE_HERO;
		if(errorFlag==4)
			cout<<ERROR_CHOOSE_CLASS;
		//Check if error due to files->Display errorMsg
		if(errorFlag!=0)
			cout<<ERROR_IN_FILES;
	}
	cout<<GAME_END_STRING;
	_getch();
	exit(0);
}

void Game::initStory()
{
	fstream inFile;
	int i=0;
	string stories[MAX_SIZE];
	string fileName;
	fileName="Game01.adg";
	inFile.open(fileName,ios::in);
	while(inFile>>stories[i])
	{
		endFlag=0;
		printStoryEvent(stories[i]);
	}
}

void Game::gameSetup()
{
	cout<<CLRSCR<<"New Game Started...\nPress Any Key...";
	_getch();
	initStory();
	gameEnd();
}

void Game::gameShutDown()
{

}

Game::~Game()
{
#ifdef DEBUG_MODE
	delete userHero;
	cout<<"Game deleted...";
	_getch();
#endif
}