#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include "team.h"  //"player.h" , <string> , <vector>

class Game {
public:
	Game();

	int playerPerTeam;
	int maxBalls;
	int totalPlayers;
	std :: string players[11];

	bool isFirstInning;
	Team teamA,teamB;
	Team *battingTeam , *bowlingTeam;
	Player *batsman , *bowler;

	void showAllPlayers();
	void welcome();
	int takeIntegerInput();
	void selectPlayers();
	bool validateSelectedPlayer(int);
	void showTeamPlayers();
	void toss();
	void tossChoice(Team);
	void startFirstInning();
	void initializePlayer();
	void playInning();
	void bat();
	bool validateInningScore();
	void showGameScoreCard();
	// void startSecondInning();
};

