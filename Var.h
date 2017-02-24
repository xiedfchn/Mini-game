/* EE6411
 * Group 12 :
 * Name : Anfala Aljamie , Hadeel Almogamsi, Blessing Usoro , Dongfeng Xie
 * ID:    16103262       ,  16025547       , 16043006       , 16008766
 */

// Check in every file that use Var.h if it's not defined 
#ifndef VAR_H
//If not, define it 
#define VAR_H

/* we use enum to enable all the related file to ues it */

enum Command
{
/* move commands */
	North,
	South,
	East,
	West,

/* other commands */
	PickUp,
	Drop,
	Attack,
	Defence,
	Look,
	Inventory,
	Exit,

/* unknown command */
	Error
};

/* enum class for gametime */
enum GameTime
{
	Daytime, /* 1. Daytime (default Gametime) */
	Nighttime /* 2. Nighttime */
};

/* struct for position */ 
struct Pos
{
	int	x; /* first index x */
	int	y; /* second index y */
};

/* declaring all classes without any functions and attributes */
class Character;
class Map;
class Item;
class Control;

#endif
