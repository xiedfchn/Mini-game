/* EE6411
 * Group 12 :
 * Name : Anfala Aljamie , Hadeel Almogamsi, Blessing Usoro , Dongfeng Xie
 * ID:    16103262       ,  16025547       , 16043006       , 16008766
 */

/* calling Map.h (the header) */
#include "Map.h"
#include <cstdlib>
using namespace std;

/* defining the default class */
Map::Map()
{
	/* initilising the position of x */
	pos.x = 0;
	/* initilising the position of y */
	pos.y = 0;

	/*
	 * We have three possiple result in this position for example [0][0]
	 * 1.Enemy 2.Item 3.Empty
	 */

	type = rand() % 3;      /* random of these three options */

	/* defining a variable to use in switch */
	int temp = rand() % 5;  /* %5 because we have 5 Races (0 to 4) */

	/* using _race attribute from Race class */
	Race _race;

	/* strting the switch */
	switch ( temp )
	{
	case 0:
		_race = Human;
		break;
	case 1:
		_race = Elf;
		break;
	case 2:
		_race = Dwarf;
		break;
	case 3:
		_race = Hobbit;
		break;
	case 4:
		_race = Orc;
		break;
	}//end switch


	/* now we will have the anemy with _race that is the output of the
	 * previous switch */


	/* we using enemy that is from charachter class to use then in character.cpp
	 * which is creating the character of the enemy */
	enemy = CreateCharacter( _race );
}//end default Map()


/* here we define the same as previous Map function but with three parameters
 * 1.index of x 2.index of y 3.raceType
 */

Map::Map( int x, int y, int raceType )
{
	/* it means change the value of pos.x=0 to the entered parameter x */
	pos.x = x;

	/* it means change the value of pos.y=0 to the entered parameter y */
	pos.y = y;

	/*
	 * We have three possiple result in this position for example [0][0]
	 * 1.Enemy 2.Item 3.Empty
	 */

	type = rand() % 3;      /* random of these three options */

	int temp = rand()%5;    /* rand()%5; */

	/* using _race attribute from Race class */
	Race _race;

	/* starting the switch */
	switch ( temp )
	{
	case 0:
		_race = Human;
		break;


	/*we write break because if the _race=Human no need to continue
	 * the switch */
	case 1:
		_race = Elf;
		break;
	case 2:
		_race = Dwarf;
		break;
	case 3:
		_race = Hobbit;
		break;
	case 4:
		_race = Orc;
		break;
	} /* end the switch */


	/* now we will have the anemy with _race that is the output of the
	 *   previous switch */


	/* we using enemy that is from charachter class to use then in character.cpp
	 * which is creating the character of the enemy */

	enemy = CreateCharacter( _race );
}//end non-default Map()


/* here to get the current position */
Pos Map::GetPos()
{
	return(pos);
}//end GetPos()


/* This function is to tell us if there is any anemy or item or nothing at all */
string Map::GetInfo()
{
	/* Here we create a string variable to store the appropriate message
	 * that should appear to the player */
	string maptype;

	if ( type == 0 )        /* First condition: if there is an item */
	{
		maptype = "you location contain a(n) " + item.title;
	}else
	if ( type == 1 )        /* Second condition: if there is an enemy to fight with it */
	{
		/* show the message and enemy name */
		maptype = "you are facing an enemy, he is " + enemy.title + "; ";
	}else
	if ( type == 2 )        /* Third condition: if there isn't any enemy or item */
	{
		maptype = "you location is empty";
	}

	return(maptype);
}//end GetInfo()


/* here a function for setting x index with no return value */
void Map::SetX( int x )
{
	pos.x = x;
} /* end SetX function */


/* here a function for setting y index with no return value */
void Map::SetY( int y )
{
	pos.y = y;
}  /* end SetY  function */
