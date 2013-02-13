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