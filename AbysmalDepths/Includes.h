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

#ifndef INCLUDES_H
#define INCLUDES_H

//Main Includes
#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
#include<sstream>

//Namespace declaration
using namespace std;

//Project Header Includes
#include"Defines.h"
#include"Prototypes.h"
#include"Hero.h"
#include"Monster.h"
#include"Game.h"

//Global Includes
//Cannot include here, as this file has been included in all other headers and cpp files
//Will cause Redefinition or Redeclaration of Global Variables
//#include"ExtGlobals.h"
//#include"Globals.h"

#endif