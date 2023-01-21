#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <math.h>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class Log {
	public:
		static void info(string message = "") {
			cout << message << endl;
		}
};

class Dice {
public:
    Dice() {
        cout << "Enter the number of sides on the dice: ";
        cin >> numSides;
    }

    int roll() {
        int result = (rand() % numSides) + 1;
        
        ostringstream ss;
        ss << "Dice roll: " << result;
        Log::info(ss.str());
        
        return result;
    }

private:
    int numSides;
};

class Pawn {
	public:
		int position;
		string fullName;
		
		Pawn() {}
		
		Pawn(string fullName) {
			this->fullName = fullName;
			this->position = 0;
			
			Log::info(fullName + " joined the game.");
		}
	};
	
class Game {
public:
    vector<string> playerFirstNames = {"Adam", "Ewa", "Jan", "Katarzyna", "Marek", "Agata", "Piotr", "Anna", "Tomasz", "Joanna"};
    vector<string> playerLastNames = {"Nowak", "Kowalski", "Wisniewski", "Dabrowski", "Lewandowski", "Wujcik", "Kaminski", "Kowalczyk", "Zielinski", "Szymanski"};
    vector<Pawn> pawns;
    int numberOfPlayers = rand() % 11 + 2;
public:
	
//	int random NumberOfPlayers = rand() % 11 + 2;
	
    Game(int numberOfPlayers) {
        this->numberOfPlayers = numberOfPlayers;
    }

    void assignPlayerNames() {
        for (int i = 0; i < numberOfPlayers; i++) {
            int randomFirstNameIndex = rand() % playerFirstNames.size();
            int randomLastNameIndex = rand() % playerLastNames.size();
            string fullName = playerFirstNames[randomFirstNameIndex] + " " + playerLastNames[randomLastNameIndex];
            cout << "Player " << (i + 1) << ": " << fullName << endl;
            pawns.push_back(Pawn(fullName));
            playerFirstNames.erase(playerFirstNames.begin() + randomFirstNameIndex);
            playerLastNames.erase(playerLastNames.begin() + randomLastNameIndex);
        }
    }
};



class Board {
    public:
        static const int maxPosition = 100;
        int maxPositions;
        vector<Pawn> pawns;
        Dice dice;
        Pawn winner;
        int turnsCounter;
        
        Board() {
            this->turnsCounter = 0;
            cout << "Enter the maximum number of positions: ";
            cin >> this->maxPositions;
        }
        
        void performTurn() {
            this->turnsCounter++;
            
            ostringstream ss;
            ss << "Turn " << this->turnsCounter;
            Log::info();
            Log::info(ss.str());
            
            for(int i = 0; i < this->pawns.size(); i++) {
                int rollResult = this->dice.roll();
                Pawn &pawn = this->pawns.at(i);
                pawn.position += rollResult;
                
                ostringstream ss;
                ss << pawn.fullName << " new position: " << pawn.position;
                Log::info(ss.str());
                                
                if(pawn.position >= this->maxPositions) {
                    this->winner = pawn;
                    throw "Winner was called!";
                }
            }
        }
};

int main() {
	int numberOfPlayers;
	srand(time(NULL));
	Board board = Board();
	board.dice = Dice();
    Game game(numberOfPlayers);
    game.assignPlayerNames();
    board.pawns = game.pawns;
	try {
		while(true) {
			board.performTurn();
		}
	} catch(const char* exception) {
		Log::info();
		Log::info(board.winner.fullName + " won");
	}
	
	return 0;
}

