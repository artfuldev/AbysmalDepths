#include"Includes.h"

string Game::decryptFile(string inFileName)
{
	/*fstream fileToDecrypt,fileDecrypted;
	string fileNameDecrypted;
	int i=0,j=1;
	char chars='0',charsDec;
	fileNameDecrypted=inFileName+".dec";
	fileToDecrypt.open(inFileName,ios::in);
	fileToDecrypt.unsetf(ios::skipws);
	fileDecrypted.open(fileNameDecrypted,ios::out);
	while(fileToDecrypt>>chars)
	{
		charsDec=chars+j;
		fileDecrypted<<charsDec;
		j++;
		if(j>10)
			j=0;
	}
	fileDecrypted.close();
	fileToDecrypt.close();
	return fileNameDecrypted;*/
	return inFileName;
}

void Game::tagReplace(string passedString, string newTag, string newReplaceString)
{
	int found=passedString.find(newTag);
	if(found!=string::npos)
	{
		passedString.replace(0,newTag.length()+1,newReplaceString);
		cout<<passedString;
	}
}

void Game::printStoryEvent(string fileName)
{
	int i=0,j=1,k=0,stringArrayIndex=0,fileFound=0,noChoice=0;
	string stringArray[5];
	string inputString;
	fstream fileUsed;
	char lastChar = fileName.at( fileName.length() - 1 );
	string storyFile=decryptFile(fileName+STORY_FILE_EXT);
	string choiceFile=decryptFile(fileName+CHOICE_FILE_EXT);
	char chars='0';
	fileUsed.open(storyFile,ios::in);
	if(!fileUsed)
	{
		errorFlag=1;
		cout<<"\nERROR OPENING FILE \""<<storyFile<<"\"";
		gameEnd();
	}
	fileUsed.unsetf(ios::skipws);
	cout<<CLRSCR;
	for(i=0,j=0;!fileUsed.eof();i++,j++)
	{
		fileUsed>>chars;
		if(lastChar!='A')
		{
			if(chars=='@')
				cout.setf(ios::right);
			else if(chars=='#')
				cout.setf(ios::left);
			else if(chars=='<')
			{
				fileUsed>>stringArray[0];
				tagReplace(stringArray[0],"HeroName",userHero->getName());
				tagReplace(stringArray[0],"HeroClass",userHero->getClass());
				j+=stringArray[0].length()-1;
			}
			else if(chars=='[')
			{
				fileUsed>>stringArray[0];
				fileUsed>>chars;
				fileUsed>>stringArray[1];
				fileUsed>>chars;
				fileUsed>>stringArray[2];
				if(stringArray[0]=="monster")
				{
					stringstream numberString(stringArray[2]);
					int newLevelNumber;
					numberString>>newLevelNumber;
					delete newMonster;
					newMonster=new Monster(stringArray[1],newLevelNumber);
				}
			}
			else if(chars=='>')
			{
				if(fileUsed>>stringArray[0])
					fileFound=1;
				else
					noChoice=1;
				goto storyComplete;
			}
			else
			{
				cout<<chars;
				if(((chars==' ')&&(j>10)&&(j%70<=10))||(chars=='\n'))
				{
					if(chars!='\n')
						cout<<endl;
					j=0;
				}
			}
		}
		else
		{
			cout<<chars;
			if(fileUsed.eof())
			{
				noChoice=1;
				goto storyComplete;
			}
		}
	}
	fileUsed.close();
	int choice;
	while(true)
	{
		askChoice:cout<<"\n";
		for(i=0;i<80;i++)
			cout<<"_";
		cout<<">:";
		getline(cin,inputString);
		stringstream numString(inputString);
		if(numString>>choice)
		{
			if(fileName=="chooseClass")
			{
				if((choice>0)&&(choice<6))
					break;
			}
			else
				if((choice>0)&&(choice<4))
					break;
		}
		cout<<REENTER_TEXT;
		goto askChoice;
	}
	if(fileName=="chooseClass")
		userHero=Hero::Create(userHero->getName(),choice);
	cout<<CLRSCR;
	i=0;
	j=1;
	k=0;
	fileUsed.open(choiceFile,ios::in);
	if(!fileUsed)
	{
		errorFlag=2;
		cout<<"\nERROR OPENING FILE \""<<choiceFile<<"\"";
		gameEnd();
	}
	fileUsed.unsetf(ios::skipws);
	for(i=0,j=0;!fileUsed.eof();i++,j++)
	{
		fileUsed>>chars;
		if(chars=='\n')
		{
			j=0;
			k++;
		}
		if(k==choice)
		{
			if(chars=='@')
				cout.setf(ios::right);
			else if(chars=='#')
				cout.setf(ios::left);
			else if(chars=='/')
			{
				gameEndFlag=1;
				break;
			}
			else if(chars=='<')
			{
				fileUsed>>stringArray[0];
				tagReplace(stringArray[0],"HeroName",userHero->getName());
				tagReplace(stringArray[0],"HeroClass",userHero->getClass());
				j+=(stringArray[0].length()+1);
			}
			else if(chars=='[')
			{
				fileUsed>>stringArray[0];
				if(stringArray[0]=="c")
					combat(*userHero,*newMonster);
				else if(stringArray[0]=="e")
					escape(*userHero,*newMonster);
			}
			else if(chars=='>')
			{
				fileUsed>>stringArray[0];
				if(stringArray[0]=="ArcEnd")
				{
					endFlag=1;
					return;
				}
				if(stringArray[0]=="GameEnd")
				{
					endFlag=2;
					gameEnd();
				}
				fileFound=1;
				goto storyComplete;
			}
			else
			{
				cout<<chars;
				if(((chars==' ')&&(j>65)&&(j%65>0))||(chars=='\n'))
				{
					if(chars!='\n')
						cout<<endl;
					j=0;
				}
			}
		}
	}
	storyComplete:cout<<"\n";
	for(i=0;i<80;i++)
		cout<<"_";
	if(fileName=="chooseHero")
	{
		cout<<"Enter name >:";
		getline(cin,stringArray[1]);
		userHero=Hero::Create(stringArray[1],userHero->getHeroType());
		//cout<<"Hero "<<userHero->getName()<<" the "<<userHero->getClass()<<" created...\n";
	}
	if((userHero->getName()!="a nobody")&&(userHero->getHeroType()!=0)&&(heroCreated==0))
	{
		cout<<STAT_UPDT<<"You are now "<<userHero->getName()<<", the "<<userHero->getClass()<<"..."<<endl;
		getch();
		heroCreated=1;
	}
	if(gameEndFlag==1)
		gameEnd();
	_getch();
	if(!noChoice)
	if(fileFound==1)
		printStoryEvent(stringArray[0]);
	else
		errorFlag=1;
}