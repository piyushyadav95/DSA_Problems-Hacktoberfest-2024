#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class LudoGame {
public:
    static const int BOARD_SIZE = 52;
    
    LudoGame() {
        // Initialize player position at the start
        playerPosition = 0;
    }
    
    void play() {
        srand(time(0));  // Seed for random dice rolls
        while (playerPosition < BOARD_SIZE) {
            int diceRoll = rollDice();
            cout << "You rolled a " << diceRoll << "!" << endl;
            
            moveToken(diceRoll);
            
            cout << "Your current position is " << playerPosition << endl;
            if (playerPosition == BOARD_SIZE) {
                cout << "Congratulations! You've reached the end and won the game!" << endl;
                break;
            }
            
            cout << "Press Enter to roll the dice again..." << endl;
            cin.get();
        }
    }

private:
    int playerPosition;
    
    int rollDice() {
        // Returns a random number between 1 and 6 (inclusive)
        return rand() % 6 + 1;
    }
    
    void moveToken(int diceRoll) {
        if (playerPosition + diceRoll <= BOARD_SIZE) {
            playerPosition += diceRoll;
        } else {
            cout << "Roll exceeds the board limit! No movement this turn." << endl;
        }
    }
};

int main() {
    cout << "Welcome to the Ludo game!" << endl;
    LudoGame game;
    game.play();
    
    return 0;
}
