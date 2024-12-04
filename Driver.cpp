#include "Board.h"
#include "Tile.h"
#include "Library.h"
#include "Player.h"
#include <iostream>
#include <fstream>
// Worked on by Eddie Chiu and Pranav Konijeti

int main() {
    Library lib;

    string tempName;
    string tempChoice;

    string pathChoice;
    string playerCount;
    int playerCountCounter = 0;
    //int pathChoiceCounter = 0;

    vector<string> playerName;
    vector<Player> playerData;
    
    ifstream file("characters.txt");
    if (!file.is_open()){
        cout << "Error could not open file 'characters.txt'" << endl;
        return -1;
    }
    string line;

    getline(file, line);
    
    while (getline(file, line)){
        if (line.empty()){
            continue;
        }

        string player[6];
        lib.split(line, '|', player, 6);

        Player currentPlayer(player[0], stoi(player[2]), stoi(player[3]), stoi(player[4]));
        currentPlayer.setAge(stoi(player[1]));
        currentPlayer.setPridePoints(stoi(player[5]));
        currentPlayer.printStats();
        
        cout << endl;
    }

    cout << "Welcome to Game of Life" << endl;
    cout << "Enter the number of players that will participate, between 2 and 5." << endl;
    
    do{
        if(playerCountCounter > 0){
            cout << "Invalid player count chosen. Please choose a player count between 2 and 5" << endl;
        }
        getline(cin, playerCount);

        playerCountCounter++;
    } while(playerCount != "2" && playerCount != "3" && playerCount != "4" && playerCount != "5");
    
    for(int i = 0; i < stoi(playerCount); i++){
        cout << "Player " << i + 1 << ", Please enter your name: ";
        cin >> tempName;

        cout << endl << "Thank you, " << tempName << ". Choose your character from the list above." << endl;
        cin >> tempChoice;
    }
    return 0;
}
