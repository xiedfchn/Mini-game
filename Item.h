/* EE6411
Group 12 :
Name : Anfala Aljamie , Hadeel Almogamsi, Blessing Usoro , Dongfeng Xie
ID:    16103262       ,  16025547       , 16043006       , 16008766     
*/



//check if this header not defined before
#ifndef ITEM_H
//if not define it
#define ITEM_H

//using input/outpt library
#include<iostream>

//we use class from enum type inorder to use the type in any file 

//enum Type has the type of item that are used in this game
enum Type
{
	Weapon,
	Armour,
	Shield,
	Ring,
}; //end the class

// class for all item in game
class Item
{
public:


//default constructor
Item();

/* for example Leather Armour */
std::string title; 

/* from class Type for example Armour*/
Type type; 

/* item forplayer or enemy characters */
int weight;
int attack;
int defence;
int health;
int strength;
}; //end the class

#endif
