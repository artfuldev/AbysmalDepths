//Inludes Header
#include"Includes.h"
//Globals Includes
#include"ExtGlobals.h"
#include"Globals.h"

void main()
{
	cout<<AD_NAME<<endl<<AD_PROG_VERSION<<endl<<AD_AUTHOR<<endl<<endl;
	//_getch();
	int beginChoice;
	string firstChoice;	
#ifdef DEBUG_TEXT_ON
	cout<<"This is a buggy beta version. Please enter expected inputs only. Thank You.";
	_getch();
	cout<<CLRSCR;
#endif
	while(true)
	{
		initialMenu:cout<<"\n\n1.Start Adventure\n2.Exit\n";
		for(int i=0;i<80;i++)
			cout<<"_";
		cout<<">:";			
		getline(cin,firstChoice);
		stringstream numStream(firstChoice);
		if(numStream>>beginChoice)
			break;
		cout<<REENTER_TEXT;
		goto initialMenu;
	}
	switch(beginChoice)
	{
		case 1:
			abysmalDepths.gameRun();
			break;
		case 2:
			exit(0);
			break;
		default:
			cout<<REENTER_TEXT;
			goto initialMenu;
	}
}