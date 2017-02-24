/* EE6411
 * Group 12 :
 * Name : Anfala Aljamie , Hadeel Almogamsi, Blessing Usoro , Dongfeng Xie
 * ID:    16103262       ,  16025547       , 16043006       , 16008766
 */


//calling the appropriate libraries
#include <stdio.h>
#include <cstdlib>

/* calling all the related header */

#include "Character.h"
#include "Item.h"
#include "Map.h"

//using parit of namespace which is std
using namespace std;

/* this function is to creat a charachter for the enemy */
Character CreateCharacter( Race _race )
{
	Character temp( _race );
	return(temp); // return a character
}//end CreateCharacter function

//start InitCharacter function with parameter _race from Race class
void Character::InitCharacter( Race _race )
{
	/* an attribute race that is declared in character.cpp from class 
    Race = _race */
	race = _race;
	/* intialise the position of */
	pos.x = 0;
	/* instilise the position of y */
	pos.y = 0;
	/* intilise the position of gold */
	gold = 0;
	
	/*intilise weight with 0 */
	weight = 0;

	/* starting to chose a charecter from the player from this switch */
	switch ( _race )
	{
	/* Humen case and ll the race details are initilzed */
	case Human:
		title		= "Human";
		attack		= 30;
		attackChance	= 2.0 / 3;
		defence		= 20;
		defecneChance	= 1.0 / 2;
		health		= 60;
		strength	= 100;
		/*
		 * to finish the switch if Humen are chosen
		 * because if we don't do that it will continue with the switch
		 */
		break;
	/* -----------------// */
	case Elf: /*Elf character */
		title		= "Elf";
		attack		= 40;
		attackChance	= 1.0;
		defence		= 10;
		defecneChance	= 1.0 / 4;
		health		= 40;
		strength	= 70;
		break;
	/* -----------------// */
	case Dwarf: /* Dwarf character */
		title		= "Dwarf";
		attack		= 30;
		attackChance	= 2.0 / 3;
		defence		= 20;
		defecneChance	= 2.0 / 3;
		health		= 50;
		strength	= 130;
		break;
	/* -----------------// */
	case Hobbit: /* Hobbit character */
		title		= "Hobbit";
		attack		= 25;
		attackChance	= 1.0 / 3;
		defence		= 20;
		defecneChance	= 2.0 / 3;
		health		= 70;
		strength	= 85;
		break;
	/* -----------------// */
	case Orc: /* orc character */

		/* orc's characters default value*/

		title = "Orc";
		attack		= 25;
		attackChance	= 1.0 / 4;
		defence		= 10;
		defecneChance	= 1.0 / 4;
		health		= 50;
		strength	= 130;
		break;
	}//end switch
}//end InitCharacter function


/*  change Orc attribute. orc's characters have two different value for attack, attackchance,
* defence and defence time */

//start non-return changeOrcAttri function with x parameter from GameTime class
void Character::changeOrcAttri(GameTime x) {
	if(title == "Orc") {

  		/* Set attack according to game time
           if Daytime attack = attack - 20
           if Nighttime attack=attack + 20
	    */
		attack		= (x == Daytime) ? attack-=20 : attack+=20;
		
		/* Set attackChance according to game time
           if Daytime attackChance = attackChance - .75
           if Nighttime attackChance = attackChance + .75
	    */
		attackChance	= (x == Daytime) ? attackChance-= 0.75 : attackChance += 0.75 ;
		
		/* Set defence according to game time
         if Daytime defence = defencee - 15
          if Nighttime defence = defence + 15
	 	*/
		defence		= (x == Daytime) ? defence-=15 : defence+=15;
		
		/* Set defenceChance according to game time
             if Daytime defenceChance = attackChance - .25
             if Nighttime defenceChance = attackChance + .25
	     */
		defecneChance	= (x == Daytime) ? defecneChance-= 0.25 : defecneChance+= 0.25;
	
	}//end if

}// end changeOrcAttri function

/* calling default constructor with initilise rece Human */
Character::Character()
{
	InitCharacter( Human );
}//end character constructor


/* calling the non-default character with chosen Race */
Character::Character( Race _race )
{
	InitCharacter( _race );
}//end non-default character  constructor


/*
 * starting attack function and rules
 * it's called from class character that's declared in character.h
 * it has two parameter the pointer to temp(enemy) and Gametime from Var.h
 */

float Character::Attack( Character &temp, GameTime gameTime )
{
	/* 1. condition if this enemy is not dead */
	if ( temp.health > 0 )
	{
		// 1.1 attact miss
    		if((rand()%100) > attackChance*100) {
				cout << title << " hit the " << temp.title <<", but missed.\n";
			} else { //1.2 attract not miss
			
				int damage = attack  - temp.defence;
				damage = damage < 0 ? 0 : damage ; 
				int rDamage = 0;
				
				// defense success, different races have different function.
				if((rand()%100)  < temp.defecneChance * 100){
					switch(temp.race) {
						case Human: /* Human */
							damage = 0;
							break;
						case Elf: /* Elf */
							temp.health += 1;
							break;
						case Dwarf: /* Dwarf */
							damage = 0;
							break;
						case Hobbit: /* Hobbit */
							rDamage = rand()%6;
							health = health - rDamage;
							break;
						case Orc: /*Orc */
							// need one function to generate daytime or nighttime
							if(gameTime = Daytime) {
								rDamage = (temp.attack  - defence)/4;
								health = health - rDamage;
								break; 
							} else {
								temp.health += 1;
							}
							break;//end switch
					}//end if
				}
				
				if(damage == 0){ //if there is no damage
					cout << title << " hit the " << temp.title <<", but the "<< temp.title <<" defenses up.";
				} else {
					cout << title << " hit the " << temp.title <<", create a " << damage  << " damage. ";
					if(rDamage != 0){
						cout << temp.title << " return " << rDamage <<" damage to " << title;
					}
				}
				cout << "\n";
				if(damage < 0 ) damage = 0;
				temp.health = temp.health - damage; 
			}//end condition 1.2
		
	}//end condition 1

	return(temp.health <= 0);
}//end function


/* defence function doesn't do any thing as it's appear in the project sheet */
// start Defence function with returned float value and one parameter attack
float Character::Defence( float attck )
{
	return(0);
}//end Defence function


/*
 * We put move function in order to change our direction (Dir) and find an enemy or item
 * We'er calling this function from character.h with parameter (Dir) from (enum command)
 * enum command is defiend in Var.h
 */

void Character::Move( Command Dir, Pos border)
{
	
	/* if we press North */
	if ( Dir == North )
	{
		if ( pos.y < border.y )
			pos.y++;
		else 
			cout << "You reach the border.";
	/* if we press East */
	} else if ( Dir == East )
	{
		if ( pos.x < border.x )
			pos.x++;
		else 
			cout << "You reach the border.";
	}
	else if ( Dir == West ) {
		/*
		 * if we press West we need to check if x>0 or not
		 * if x>0 it means we pressed East before and so substract one from it
		 */
		if ( pos.x > 0 )
			pos.x--;
		else 
			cout << "You reach the border.";
	}
	else if ( Dir == South ) {
				/*
			 * if we press South we need to check if y>0 or not
			 * if y>0 it means we pressed North before and so substract one from it
			 */
		if ( pos.y > 0 )
			pos.y--;	
		else 
			cout << "You reach the border.";
	}

} /* finish the move function */


/* starting pickup function which is pressed when player find an item in his position
 * after (look) */

/*
 * It's declared in character.h with parameter
 * It's parameter is from class Item which is (item)
 */


/* We use push_back() because we need to add the chosen item into the inventory
 * so we can know later what the player carrys */

int Character::PickUp( Item item, Pos border )
{

	int count = Inventory.size();
	
	/* only one except ring */
	if ( item.type != Ring ) //if 1
	{
		for ( int i = 0; i < count; i++ )
		{
			if ( item.type == Inventory[i].type ) //if 1.1
			{
				cout << "You already have a(n) ";
				//switch show the item that the player has
				switch (Inventory[i].type) {
					case Weapon: 
						cout << "weapon."<< endl;
						break;
					case Armour: 
						cout << "armour."<< endl;
						break;
					case Shield: 
						cout << "shield."<< endl;
						break;
				}//end the switch
				return(0);
			}//if 1.1
		}//end for loop
	}//end if 1

	/* is over weight? */
	if ( item.weight + weight > strength )
	{
		cout << "Your bag is too full " << endl;
		return(0);
	}

	Inventory.push_back( item ); //add the item to the Inventory
	
	addAttributes(item);
	
	return 1;
}

// add attributes from equipments
void Character::addAttributes (Item item){
	attack		+= item.attack;
	defence		+= item.defence;
	health		+= item.health;
	strength	+= item.strength;
	weight		+= item.weight;
}//end addAttributes function


/* This function is used to drop the item that the player carry in a certin 
   place 
   It has the index of the item (where it is x,y) and the border that the 
   plyer in
*/
int Character::Drop( int itemIndex, Pos border )
{
	/*
	 * it's stored in the inventory
	 * '[itemIndex-1]' it means the last elemnt in the array
	 */
	Item dropItem = Inventory[itemIndex - 1];
	
	cout << dropItem.title << " has been droped" << endl;

	/* after drope it, we need to delete it from the inventory */
	Inventory.erase( Inventory.begin() + (itemIndex - 1) );
	
	// decresase attack,defense ...
	attack	-= dropItem.attack;
	defence	-= dropItem.defence;
	health	-= dropItem.health;
	strength -= dropItem.strength;
	weight	-= dropItem.weight;
	
	return 1;
}//end drop function


/* inventory is stored all what the player carrys */

int Character::inventory()
{
	/* It means here if it's not empty */
	if ( Inventory.size() > 0 )
	{
		/* show what the inventory has */
		cout << "Your Inventory Contain : " << endl;
		/* loop because it's an array */
		for ( int i = 0; i < Inventory.size(); i++ )
		{
			cout << i + 1 << "\\" << Inventory[i].title << endl;
		}
		return(0);
	}else  { /* if the inventory empty return -1 */
		cout << "Your Inventory is empty!" << endl;
		return(-1);
	}
}//end Inventory function


/*
 * this class is from Map.cpp
 * it's get the current position for the player
 */

Pos Character::GetPos()
{
	return(pos);
}//end GetPos function
