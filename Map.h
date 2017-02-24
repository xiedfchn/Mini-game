/* EE6411
 * Group 12 :
 * Name : Anfala Aljamie , Hadeel Almogamsi, Blessing Usoro , Dongfeng Xie
 * ID:    16103262       ,  16025547       , 16043006       , 16008766
 */

//To check if MAP header is not defiened 
#ifndef MAP_H
//if not define it
#define MAP_H

//calling input/output library
#include <iostream>

//calling alla related headers
#include "Var.h"
#include "Item.h"
#include "Character.h"


/* declaring Map class */ 
class Map
{
public:
	Map();                                  /* default constructor */
	Map( int x, int y, int raceType );      /* position */
	Pos GetPos();                           /* where are you */


	void SetX( int x );                     /* to set x */


	void SetY( int y );                     /* to set y */


	std::string GetInfo();                  /* show is there any item or enemy or nothing and the position of the player */


	int type;                               /* 0 => item , 1=> enemy , 2 => empty */

	Character	enemy;                  /* call class character */
	Item		item;                   /* call class item */


private:
	Pos pos;                                /* to deal with the position inside this class */
};//end class

#endif
