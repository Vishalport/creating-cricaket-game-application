#include "game.h"

using namespace std;

Game :: Game() {

	playerPerTeam = 4;
	maxBalls = 6;
	totalPlayers = 11;

	players[0] = "KL Rahul";
	players[1] = "Rohit Sharma";
	players[2] = "Shreyas Lyear";
	players[3] = "Prithvi Show";
	players[4] = "Hardik Pandya";
	players[5] = "Shivam Dubey";
	players[6] = "Ishan Kishan";
	players[7] = "Jadeja";
	players[8] = "Bumrah";
	players[9] = "Shammi";
	players[10] = "Bhuwaneshwar";

	isFirstInning = false;
	teamA.name = "Team-A";
	teamB.name = "Team-B";
}

 void Game :: welcome() {

	cout << "--------------------------------------" << endl;
	cout << "|==============CRICKET-IN============|" << endl;
	cout << "|                                    |" << endl;
	cout << "|    Welcome to Virtual Cricket Game |" << endl;
	cout << "|------------------------------------|" << endl;

	cout << endl << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "|===================Instruction====================|" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << "|                                                  |" << endl;
	cout << "| 1. Create 2 teams (Team-A and Team-B with 4      |" << endl;
	cout << "|    players each) from a given pool of 11 players.|" << endl;
	cout << "| 2. Lead the toss and decide the choice of play.  |" << endl;
	cout << "| 3. Each innings will be of 6 balls.              |" << endl;
	cout << "----------------------------------------------------" << endl;
}

 void Game :: showAllPlayers() {

	 cout << endl << endl;
	 cout << "---------------------------------------------------" << endl;
	 cout << "|==================Pool of Players================|" << endl;
	 cout << "---------------------------------------------------" << endl;
	 cout << endl;

	 for (int i = 0; i< totalPlayers; i++) {
		 cout << "\t\t[" << i << "]" << players[i] << endl;
	 }
 }

int Game :: takeIntegerInput() {

	int n;

	while (!(cin >>n)) {

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		cout << "Invalid input! Please try again with valid input";
	}
	return n;
}

void Game :: selectPlayers() {

	cout << endl << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "|===============Create Team-A and Team-B==============|" << endl;
	cout << "-------------------------------------------------------" << endl;

	for(int i =0; i<playerPerTeam; i++) {

		//Add player to Team-A
		teamASelection:
		cout << endl << "Select player " << i+1 << " of Team-A  :";

		int playerIndexTeamA=takeIntegerInput();

		if (playerIndexTeamA <0 || playerIndexTeamA >10) {

            cout << " Please select from the given players." << endl;
            goto teamASelection;
		}
		else if (!validateSelectedPlayer(playerIndexTeamA)) {

            cout << " Player has been already selected." << endl;
            cout << "Please selected onother player." << endl;
            goto teamASelection;
		}
		else {

            Player teamAPlayer;
            teamAPlayer.id = playerIndexTeamA;
            teamAPlayer.name=players[playerIndexTeamA];
            teamA.players.push_back(teamAPlayer);
		}

		//Add player to Team-B
		teamBSelection:
		cout << endl << "Select player " << i+1 << " of Team-B  :";

		int playerIndexTeamB=takeIntegerInput();

		if (playerIndexTeamB <0 || playerIndexTeamB >10) {

            cout << " Please select from the given players." << endl;
            goto teamBSelection;
		}
		else if (!validateSelectedPlayer(playerIndexTeamB)) {

            cout << " Player has been already selected." << endl;
            cout << "Please selected onother player." << endl;
            goto teamBSelection;
		}
		else {
            Player teamBPlayer;
            teamBPlayer.id = playerIndexTeamB;
            teamBPlayer.name=players[playerIndexTeamB];
            teamB.players.push_back(teamBPlayer);
		}
	}
}

bool Game :: validateSelectedPlayer(int index) {

    int n;
    vector<Player> players;

    players = teamA.players;
    n = players.size();
    for ( int i = 0; i<n; i++) {
        if (players[i].id == index) {
            return false;
        }
    }

    players = teamB.players;
    n = players.size();
    for ( int i = 0; i<n; i++) {
        if (players[i].id == index) {
            return false;
        }
    }

    return true;
}

void Game :: showTeamPlayers() {

    vector<Player> teamAPlayer = teamA.players;
    vector<Player> teamBPlayer = teamB.players;

    cout << endl << endl;
    cout << "--------------------\t\t\t--------------------" << endl;
    cout << "|======Team-A======|\t\t\t|======Team-B======|" << endl;
    cout << "--------------------\t\t\t--------------------" << endl;

    for (int i = 0;i <playerPerTeam; i++) {

        cout << "|\t" << "[" << i+1 << "]" << teamAPlayer[i].name << "\t |"
        << "\t\t"
        << "|\t" << "[" << i+1 << "]" << teamBPlayer[i].name << " |" << endl;
    }
    cout << "--------------------\t\t\t--------------------" << endl << endl;
}

void Game :: toss() {

    cout << endl;
    cout << "----------------------------------------------" << endl;
    cout << "|================ Let's Toss ================|" << endl;
    cout << "----------------------------------------------" << endl << endl;

    cout << "Tossing the coin..." << endl << endl;

    srand(time(NULL));
    int randomValue = rand() % 2;   //0 or 1

    switch (randomValue) {
    case 0:
        cout << "Team-A won the toss" << endl << endl;
        tossChoice(teamA);
        break;
    case 1:
        cout << "Team-B won the toss" << endl << endl;
        tossChoice(teamB);
        break;
    }
}

void Game :: tossChoice(Team tossWinnerteam) {

    cout << "Enter 1 to bat or 2 to ball" << endl;
    cout << "1. Bat" << endl;
    cout << "2. Boll" << endl;
    int tossInput = takeIntegerInput();

    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    switch(tossInput) {

    case 1 :
        cout << endl << tossWinnerteam.name << " won the toss and elected to bat first." << endl << endl;
        if (tossWinnerteam.name.compare("Team-A") == 0) {

            battingTeam = &teamA;      // If Team-A is the toss winner.
            bowlingTeam = &teamB;
        }
        else {

            battingTeam = &teamB;       // If Team-B is the toss winner.
            bowlingTeam = &teamA;
        }
        break;
    case 2 :
        cout << endl << tossWinnerteam.name << " won the toss and choose the boll first." << endl << endl;
        if (tossWinnerteam.name.compare("Team-A") == 0) {

            battingTeam = &teamB;      // If Team-A is the toss winner.
            bowlingTeam = &teamA;
        }
        else {

            battingTeam = &teamA;       // If Team-B is the toss winner.
            bowlingTeam = &teamB;
        }
        break;
    default :
        cout << endl << "Invalid input. Please try again...";
        tossChoice(tossWinnerteam);
        break;
    }
}

void Game :: startFirstInning() {

    cout << "\t\t ||| First Innings starts ||| " << endl << endl;

    isFirstInning = true;
    initializePlayer();
    playInning();
}

void Game :: initializePlayer() {

    batsman = &battingTeam->players[0];
    bowler = &bowlingTeam->players[0];

    cout << battingTeam->name << "-" << batsman->name << " is playing." << endl;
    cout << bowlingTeam->name << "-" << bowler->name << " is bowling." << endl;


}

void Game :: playInning() {

    for (int i = 0; i < maxBalls; i++) {

        cout << "Press enter to bowl..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        getchar();
        cout << "Bowling..." << endl;

        bat();

        if (!validateInningScore()) {

            break;
        }
    }
}

void Game :: bat() {

    srand(time(NULL));
    int runsScored = rand() % 7;

    // Updating batting team and batsman score.
    batsman->runsScored += runsScored;
    battingTeam->totalRunsScored += runsScored;
    batsman->ballsPlayed += 1;

    // Updating bowling team and bowler score.
    bowler->ballsBowled += 1;
    bowlingTeam->totalBallsBowled += 1;
    bowler->runsScored += runsScored;



    if (runsScored != 0) {

        cout << endl << bowler->name << " to " << batsman->name << " " << runsScored << " runs!" << endl << endl;
        showGameScoreCard();
    }
    else {

        cout << endl << bowler->name << " to " << batsman->name << " out!" << endl << endl;
        battingTeam->wicketsLost += 1;
        bowler->wicketTaken += 1;

        showGameScoreCard();

        // Initialize next batsman.
        int nextPlayerIndex = battingTeam->wicketsLost;
        batsman = &battingTeam->players[nextPlayerIndex];
    }
}

bool Game :: validateInningScore() {

    if (isFirstInning) {

        if (battingTeam->wicketsLost == playerPerTeam || bowlingTeam->totalBallsBowled == maxBalls) {

            cout << endl << endl << "||| First Inning Ends |||" << endl << endl;
            cout << battingTeam->name << " " << battingTeam->totalRunsScored << "-"
            << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ")" << endl;

            cout << bowlingTeam->name << " needs " << battingTeam->totalRunsScored + 1
            << " runs to win the match." << endl << endl;
            return false;
        }
    }
    else {      // Else 2nd innings.

        return true;
    }
}

void Game :: showGameScoreCard() {

    cout << "----------------------------------------------------------------" << endl;

    cout << "\t" << battingTeam->name << " " << battingTeam->totalRunsScored << "-"
    << battingTeam->wicketsLost << " (" << bowlingTeam->totalBallsBowled << ") | " << batsman->name
    << " " << batsman->runsScored << " (" << batsman->ballsPlayed << ") \t" << bowler->name << " "
    << bowler->ballsBowled << " - " << bowler->runsGiven << " - " << bowler->wicketTaken << "\t" <<endl;

    cout << "----------------------------------------------------------------" << endl << endl;
}
