/* EE6411
 * Group 12 :
 * Name : Anfala Aljamie , Hadeel Almogamsi, Blessing Usoro , Dongfeng Xie
 * ID:    16103262       ,  16025547       , 16043006       , 16008766
 */

//call the Control header file
#include "Control.h"
//use part of namespace which is std
using namespace std;
/*start the init function that's used to intilise:
1. the border indexes x and y
2. the gametime
3. the commands that the player will use
4. the current location
 */
void Control::init()
{
  //initialise the gametime as Daytime in the first round
	gameTime = Daytime;
  //the first round
	rounds = 1;
	
	// setBorder, useful for move,pick,etc;
	setBorder();
	
	// initialize maps vector
	map = InitMap( border.x, border.y, selectRace());
	
	// initialize location info, necessary!!, pick, thrown, attack use it.
	whereAmI();
	
	// manipulation
	inputCommand();
}//end init()

// non-returned function to get localtion info, save it to currentPos; 
void Control::whereAmI()
{
	Map temp; //using object from Map class

    //start the for loop that get the player position
	for ( int i = 0; i < map.size(); i++ )
	{
		if ( map[i].GetPos().x == player.GetPos().x && map[i].GetPos().y == player.GetPos().y )
		{
			currentPos = &map[i];
		}//end if 
	}//end for loop 
};//end whereAmI function

// look, show up location info; 
void Control::look()
{
	cout << endl;
	//get if there is any enemy or item or nothing in this location
	cout << currentPos->GetInfo() << endl;
};//end look()

// para gametime, turn computer data into english. return gametime in english words.
string Control::ParseTime( GameTime g )
{
	return( (g == Daytime) ? "Day time" : "Night time");
};//end ParseTime


/*-------------------------
 * Function Name: SwitchTime
 * Parameters:GameTime
 * Return Value: GameTime
 * Desc:switch the day time from night to day and from day to night
 * ---------------------------*/
GameTime Control::switchTime( GameTime temp )
{
	GameTime x = ( (temp == Daytime) ? Nighttime : Daytime);
	
	// every time switch, change attributes for Orc; 
	player.changeOrcAttri(x);
	
	return x;
};//end switchTime()

// specific command implement, para command, return info of process.
string Control::ExecCommand( Command cmd )
{

	// some command depend on staffs on map;
	whereAmI(); //calling WhereAmI() which is defined in this cpp

	// maximun of borders 
	Pos border = map.back().GetPos();
	
	if ( cmd == North )  /* North command */
	{
		player.Move( cmd, border);
		
		return("Heading North..");
	}else
	if ( cmd == East )  /*East command */
	{
		player.Move( cmd, border);
		return("Heading East..");
	}else
	if ( cmd == West ) /*West command */
	{
		player.Move( cmd, border);
		return("Heading West..");
	}else
	if ( cmd == South )  /* south command */
	{
		player.Move( cmd, border);
		return("Heading South..");
	}else
	if ( cmd == PickUp )  /* pickup command */
	{
		if ( currentPos->type == 0 )
		{
			if(player.PickUp( currentPos->item, border)){
				currentPos->type = 2;
				cout << "You PickUp " <<  currentPos->item.title << endl;
			} 
			return("Picking Up Item"); /* there is an item */
		}
		return("there is no Item Picking Up!"); /* no item to pick */
	}else
	if ( cmd == Drop )  /* Drop command */
	{
		int x;
		if ( player.inventory() != -1 ) /* if the inventory not empty */
		{
			cout << "enter the number of the Item You want to Drop:";
			
			 //player enter the number of items that're wanted to drop
			cin >> x;
			if(player.Drop( x, border )){
				currentPos->type = 0;
			} 
		}
		return("");
	}else
	if ( cmd == Attack ) /*attack command */
	{
		if ( currentPos->type == 1 )  /*there is an enemy */
		{
			
			if(player.Attack( currentPos->enemy, gameTime )){
				player.gold += currentPos->enemy.defence;
				currentPos->type = 2;
				cout << "Enemy is dead ,you get " << currentPos->enemy.defence << " gold" << endl;
			} else {
				if(currentPos->enemy.Attack( player, gameTime )){ 
					cout << "Game Over!" << endl;
					cout << "Your Score is " << player.gold << endl;
				} else {
					cout << "Player " << player.title << "'s Health : " << player.health << endl;
					cout << "Enemy " << currentPos->enemy.title << "'s Health : " << currentPos->enemy.health << endl;
				}
			}
			
			return("You are Attacking " + currentPos->enemy.title);
		}
		//if there is no enemy to attack
		return ("there is no enemy to attack!");
	}else
	if ( cmd == Defence ) /* defence command */
	{
		player.Defence( 0 );
		return("Defence Mode");
	}else
	if ( cmd == Look ) /* look command */
	{
		look();
		return("..........");
	}else
	if ( cmd == Inventory )  /* inventory command */
	{
		player.inventory();
		return("..........");
	}else
	if ( cmd == Exit ) /* exit command */
	{
		/* showing the gaining Gold for player */
		cout << "Your Score is " << player.gold << endl;
		return("Good By");
	}
	return("Unknown Command!");
}//end ExecCommand()

// show up basic info and command;
int Control::showBasicInfo() {
	cout << "\nIt is " << ParseTime( gameTime ) << "("<< getRounds() << ")"<< endl;
	cout << "Your location is " << player.GetPos().x << "," << player.GetPos().y << endl; 
	cout << "Player:" << player.title << ";";
	cout << "attack=" << player.attack << "; ";
	cout << "attackChance=" << player.attackChance << "; ";
	cout << "defence=" << player.defence << "; ";
	cout << "defecneChance=" << player.defecneChance << "; ";
	cout << "health=" << player.health << "; ";
	cout << "gold= " << player.gold << "; ";
	cout << "carry: " << player.weight << " of " << player.strength << endl;
	
	cout << "Move: (N)orth, (S)outh, (E)ast, (W)est \nCommand: (A)ttack, (P)ickup, (D)rop, (L)ook, (I)nventory, or e(X)it: ";
	
}//end showbasicInfo function

/* start inputCommand function, which gets input command from user */
int Control::inputCommand()
{
	string	input;
	string flag;
	Command cmd;
	cout << "-----------------------" << endl;
	cout << "-        Welcome      -" << endl;
	while ( cmd != Exit )
	{
		if ( player.health > 0 )
		{
			showBasicInfo();
			cin >> input;
			cout << "------------------------" << endl;
			cmd = parser( input );
			flag = ExecCommand( cmd ); 
			if(flag != "Unknown Command!"){
				
				if ( rounds%5 == 0)
				{
					gameTime = switchTime( gameTime );
				}
				rounds++;
			}
			cout << "\nCommand Result: " << flag << endl;
		} else {
			break;
		}
	}
};


/* change quick letter key into command data, return command
   for example user enter n it'll return North 
 */
Command Control::parser( std::string com )
{
	if ( !com.compare( "n" ) )
		return(North);
	else
	if ( !com.compare( "s" ) )
		return(South);
	else
	if ( !com.compare( "e" ) )
		return(East);
	else
	if ( !com.compare( "w" ) )
		return(West);
	else
	if ( !com.compare( "p" ) )
		return(PickUp);
	else
	if ( !com.compare( "d" ) )
		return(Drop);
	else
	if ( !com.compare( "a" ) )
		return(Attack);
	else
	if ( !com.compare( "l" ) )
		return(Look);
	else
	if ( !com.compare( "i" ) )
		return(Inventory);
	else
	if ( !com.compare( "x" ) )
		return(Exit);

	return(Error);
}// command parser()


/* get input from user for width and height of board */
void Control::setBorder()
{
	cout << "Please set width of board: ";
	cin >> border.x;
    while(cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
        std::cout << "Please enter a NUMBER for width: ";
        std::cin >> border.x;
    }
	cout << "Please set height: ";
	cin >> border.y;
    while(cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
        std::cout << "Please enter a NUMBER for height: ";
        std::cin >> border.y;
    }
}//end setBorder()

/* select a race as player */
int Control::selectRace()
{

	int	raceType = 1; //intilise race type = 1
	string	raceDesc; //race description
	
	
	cout << "\n------------------------" << endl;
	cout << "	Select your race"<< endl;
	cout << "1.Human" << endl;
	cout << "2.Elf" << endl;
	cout << "3.Dwarf" << endl;
	cout << "4.Hobbit" << endl;
	cout << "5.Orc" << endl;
	cout << "------------------------" << endl;

	/*player enter racenumber */
	cin >> raceType;

	/* if raceType is not exist, do the following statements */ 
    while(cin.fail() || raceType > 5 || raceType < 0)
    {
        std::cin.clear(); //clear
        std::cin.ignore(numeric_limits<streamsize>::max(),'\n'); //ignore
        std::cout << "Please enter a NUMBER 1-5 : "; //enter the number 1-5
        std::cin >> raceType; //player can enter
    }

    //start witch of races
	switch ( raceType )
	{
	case 1:
		player = Character( Human );
		break;
	case 2:
		player = Character( Elf );
		break;
	case 3:
		player = Character( Dwarf );
		break;
	case 4:
		player = Character( Hobbit );
		break;
	case 5:
		player = Character( Orc );
		break;
	}//end switch

	return raceType;
}//end selectRace function//end IniMap

/* 
 *use vector to construct a whole map, include all position and what there is.
 * Ex. at(1,0),there is a enemy Human with a sword.
 * para border width and height, raceType
 * return this vector map
 */
vector<Map> Control::InitMap( int x, int y, int raceType )
{
	std::vector<Map> map;
	srand( time( NULL ) );
	
	// double to initialize 2 dimension array-like map
	for ( int i = 0; i <= x; i++ ) 
		for ( int j = 0; j <= y; j++ )
		{
			Map temp( i, j, raceType );
			
			// Enermy with 0 or 1 equipment
			for (int i =0, j = rand()%2 ; i < j; i++) {
				Item tempItem;
				temp.enemy.PickUp(tempItem, border);
			}
			map.push_back( temp );
		}
		
	return(map);

}//end IniMap

// rounds plus
void Control::roundsPlus (){
	rounds++; 
} //end roundsPlus

// return rounds 
int Control::getRounds (){
	return rounds; 
} //end getRounds function

