/* EE6411
 * Group 12 :
 * Name : Anfala Aljamie , Hadeel Almogamsi, Blessing Usoro , Dongfeng Xie
 * ID:    16103262       ,  16025547       , 16043006       , 16008766
 */


//calling cstdlib library 
#include <cstdlib>
/* call the item header */
#include "Item.h"

// item initialize function, return a random kind of staff, like sword.
Item::Item()
{

  	//intilise the characters to 0
	weight = attack = defence = health = strength = 0;

	/*random number from 0-7 which is the number of items that are used 
    in the switch */
	int temp = rand() % 8;

  	/* starting the switch */
	switch ( temp )
	{
	case 0: /* Sword */
		title	= "Sword";
		weight	= 10;
		attack	= 10;
		type	= Weapon;
		break;
	case 1: /* Dagger */
		title	= "Dagger";
		weight	= 5;
		attack	= 5;
		type	= Weapon;
		break;
	case 2: /* Plate Armour */
		title	= "Plate Armour";
		weight	= 40;
		attack	= -5;
		defence = 10;
		type	= Armour;
		break;
	case 3: /* Leather Armour */
		title	= "Leather Armour";
		weight	= 20;
		defence = 5;
		type	= Armour;
		break;
	case 4: /* Large Shield */
		title	= "Large Shield";
		weight	= 30;
		attack	= -5;
		defence = 10;
		type	= Shield;
		break;
	case 5: /* Small Shield */
		title	= "Small Shield";
		weight	= 10;
		defence = 5;
		type	= Shield;
		break;
	case 6: /* Ring of Life */
		title	= "Ring of Life";
		weight	= 1;
		health	= 10;
		type	= Ring;
		break;
	case 7: /* Ring of Strength */
		title		= "Ring of Strength";
		weight		= 1;
		health		= -10;
		strength	= 50;
		type		= Ring;
		break;
	}//end switch
}//end function
