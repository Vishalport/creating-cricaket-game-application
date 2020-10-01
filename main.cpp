//============================================================================
// Name        : CRICKET-IN
// Author      : vishal kuamr
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : CRICKET GAME in C++
//============================================================================

#include<iostream.h>
#include<cstdlib.h>
#include<ctime.h>
#include "game.h"  // <iostream> , <cstdlib> , <ctime> , <limits> , "team.h

using namespace std;

int main() {

    system("color 1e");
	Game game;

	game.welcome();

	cout << endl <<endl;
	cout << "      Press Enter to Continue...";
	getchar();


	game.showAllPlayers();

	cout << endl <<endl;
	cout << "      Press Enter to Continue...";
	getchar();

	game.selectPlayers();
    game.showTeamPlayers();

    cin.ignore(numeric_limits<streamsize>::max(),'\n');  // To clear input buffer

	cout << "\n Press enter to toss..." << endl;
	getchar();

	game.toss();

	game.startFirstInning();

	// game.startSecondInning();
	return 0;
}
