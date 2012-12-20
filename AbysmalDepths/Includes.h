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