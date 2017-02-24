/* EE6411
 * Group 12 :
 * Name : Anfala Aljamie , Hadeel Almogamsi, Blessing Usoro , Dongfeng Xie
 * ID:    16103262       ,  16025547       , 16043006       , 16008766
 */


//check if it's not defined 
#ifndef CHARACTER_H
//if not, define it
#define CHARACTER_H

//calling the appropriate libraries
#include <iostream>
#include <vector>

//calling all related headers
#include "Var.h"
#include "Item.h"

/* declaring all Race here with enum class type to enable us to use them anywhere in the project */

enum Race
{
/* Declaring the reces */
	Human, Elf, Dwarf, Hobbit, Orc
};

/* class character */
class Character
{
public:
	/* then name of the race */
	std::string title;

	
	/* default constructor */
	Character();

	/* constructor with one parameter which is from class Race that's declared in Var.h */
	Character( Race race );

	// change Atrri for Orc
	void changeOrcAttri(GameTime x);
	
	/* add attributes of items into characters */
	void addAttributes (Item item); 
	
	/* Here we give all races' characters the value that are given in the question */
	void InitCharacter( Race _race );


	/* Here is the attack character with two parameter 1.pointer to the anemy
	 * that player want to attack 2.gametime */
	float Attack( Character &temp, GameTime gameTime );


	/* defence function that wouldn't do any thing in this project */
	float Defence( float attck );


	/* declaring Move function */
	/* we define it in character.cpp with one parameter from command class that's declared in Var.h */
	void Move( Command Dir, Pos border);


	/* declar Pickup function */
	/* Here we can pickup the available Item such as Sword */
	int PickUp( Item item, Pos boarder );


	/* dropping item that the player carry it */
	int Drop( int itemIndex, Pos boarder );


	/* storing the item that the player carrys */
	int inventory();


	/* to get the current position */
	Pos GetPos();


	/* declaring the attributes of all characters */
	float	attack;
	float	attackChance;
	float	defence;
	float	defecneChance;
	float	health;
	float	strength;
	int	weight;

	/* declaring an attribute for the gaining gold */
	int gold;

	/* declaring race from Race class to let 'Character' function deal with it */
	Race race;

	/* declaring gameTime */
	GameTime gameTime;
private:

	/* declaring attribute for Pos function */
	Pos pos;

	/*
	 * declaring vector for carrying player's Item
 	 * vectors work like an array
 	 */
	std::vector<Item> Inventory;
};

/* declaring a function to creat character */
Character CreateCharacter( Race _race );


#endif
