/* EE6411
 * Group 12 :
 * Name : Anfala Aljamie , Hadeel Almogamsi, Blessing Usoro , Dongfeng Xie
 * ID:    16103262       ,  16025547       , 16043006       , 16008766
 */

//check if Control header is not defined 
#ifndef CONTROL_H
//if not, define it
#define CONTROL_H
//calling the appropriate libraries
#include <iostream>/* input/output library */
#include <cstdlib>
#include <time.h>   /* time */
#include <limits> /* Check data type */
#include <vector>/* dynamic array, it means we can change it's size */

// calling all the related headers 
#include "Map.h"
#include "Var.h"

/* class for user control. start Control class */
class Control {
public:
	// gametime
	GameTime gameTime;
	// play rounds
	int rounds;
	// player
	Character	player;
    // whole map info
	std::vector<Map> map;
	// border, use for verifing border;
	Pos border;
	// current location
	Map *currentPos;

	// initialize
	void init();
	
	// get localtion info, save it to currentPos; 
	void whereAmI();

	// show location info; 
	void look();

	// execute command; 
	std::string ExecCommand( Command cmd );
 
	// a small function for computer data to english word;
	std::string ParseTime( GameTime g );

	// a small function for english word to computer data;
	Command parser( std::string com );

	// init function for map
	std::vector<Map> InitMap( int x, int y, int raceType );
	
	// timechange
	GameTime switchTime( GameTime temp );

	// turn plus; 
	void roundsPlus();
	// return turn ; 
	int getRounds();

private:
	
	// get command from user
	int inputCommand();
	// show basic info
	int showBasicInfo();
	// show instrument and select race
	int selectRace();
	// set border
	void setBorder();
	
	 
};

#endif
