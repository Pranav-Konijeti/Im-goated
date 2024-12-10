#include "Board.h"
#include "Tile.h"
#include "Library.h"
#include "Player.h"
#include <iostream>
#include <fstream>
// Worked on by Eddie Chiu and Pranav Konijeti

int main() {
    Library lib;
    Board board;

    string tempName;
    string tempChoice;
    string pathChoice;
    string playerCount;
    string characterLine;
    string advisor[5];
    
    int playerCountCounter = 0;
    int playerChoiceCounter = 0;
    int breaker1 = 0;
    int pathChoiceInteger;
    int pathChoiceCounter = 0;
    int advisorChoiceCounter = 0;

    vector<int> boardType;
    vector<string> playerName;
    vector<Player> playerData;
    vector<Player> characterList;
    vector<string> chosenCharacters;
    vector<int> chosenAdvisor;
    vector<int> randomEvents;

    ifstream cfile("characters.txt");
    if (!cfile.is_open()){
        cout << "Error could not open file 'characters.txt'" << endl;
        return -1;
    }
    string cline;

    getline(cfile, cline);
    
    while (getline(cfile, cline)){
        if (cline.empty()){
            continue;
        }

        string player[6];
        lib.split(cline, '|', player, 6);

        Player currentPlayer(player[0], stoi(player[2]), stoi(player[3]), stoi(player[4]));
        currentPlayer.setAge(stoi(player[1]));
        currentPlayer.setPridePoints(stoi(player[5]));

        characterList.push_back(currentPlayer);

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
        getline(cin, tempName);
        playerName.push_back(tempName);

        cout << endl << "Thank you, " << tempName << ". Choose your character from the list above." << endl;
        do{
            breaker1 = 0;

            if(playerChoiceCounter > 0){
                cout << "Invalid character chosen. Please choose a valid character that hasn't been chosen." << endl;
            }
            
            getline(cin, tempChoice);

            int chosenSize = chosenCharacters.size();

            for(int j = 0; j < chosenSize; j++){
                if(tempChoice == chosenCharacters[j]){
                    cout << "Character has already been chosen. Please choose another character." << endl;
                    playerChoiceCounter = 0;
                    breaker1++;
                    break;
                }
            }

            if(breaker1 == 0){
                playerChoiceCounter++;
            }
            
        } while((tempChoice != "Mel" && tempChoice != "Miqel" && tempChoice != "Ryk" && tempChoice != "Mog" && tempChoice != "Ren") || breaker1 > 0);
        playerChoiceCounter = 0;
        chosenCharacters.push_back(tempChoice);
        for(int k = 0; k < 5; k++){
            if(tempChoice == characterList[k].getName()){
                playerData.push_back(characterList[k]);
            }
        }
    }

    for(int i = 0; i < stoi(playerCount); i++){
        cout << "Player " << playerName[i] << ", enter 1 or 2 to choose the path your character shall embark on." << endl << endl << "Path 1: Pride Lands           Path 2: Cub Training" << endl;
        
        
        do{
            if(pathChoiceCounter > 0){
                cout << "Invalid path choice chosen. Please type 1 to choose Pride Lands or type 2 to choose Cub Training." << endl;
            }
            getline(cin, pathChoice);
            pathChoiceCounter++;
        } while(pathChoice != "1" && pathChoice != "2");
        pathChoiceInteger = stoi(pathChoice);
        
        boardType.push_back(pathChoiceInteger-1);

        pathChoiceCounter = 0;

        if(pathChoice == "1"){
            playerData[i].toPrideLands(200, 200, 200);
            cout << "You chose: Pride Lands. You gained 200 strength, 200 stamina, 200 wisdom, and 5000 pride points. Unfortunately, you do not get to choose an advisor at this time." << endl;
            chosenAdvisor.push_back(0);
        }
        else{
            playerData[i].toCubTraining(500, 500, 1000);
            cout << "You chose: Cub Training. You gained 500 strength, 500 stamina, 1000 wisdom, but lost 5000 pride points. Now please choose an advisor from the list below by typing their name." << endl << endl;
            cout << "1. Rafiki - Invisibility (the ability to become un-seen)" << endl;
            cout << "2. Nala - Night Vision (the ability to see clearly in darkness)" << endl;
            cout << "3. Sarabi - Energy Manipulation (the ability to shape and control the properties of energy)" << endl;
            cout << "4. Zazu - Weather Control (the ability to influence and manipulate weather patterns)" << endl;
            cout << "5. Sarafina - Super Speed (the ability to run 4x faster than the maximum speed of lions)" << endl;
            do{
                if(advisorChoiceCounter > 0){
                    cout << "Invalid advisor chosen. Please choose an advisor from the list above." << endl;
                }
                getline(cin, advisor[i]);
                advisorChoiceCounter++;
            } while(advisor[i] != "Rafiki" && advisor[i] != "Nala" && advisor[i] != "Sarabi" && advisor[i] != "Zazu" && advisor[i] != "Sarafina");
            cout << "You chose: " << advisor[i] << "." << endl;
            if(advisor[i] == "Rafiki"){
                chosenAdvisor.push_back(1);
            }
            if(advisor[i] == "Nala"){
                chosenAdvisor.push_back(2);
            }
            if(advisor[i] == "Sarabi"){
                chosenAdvisor.push_back(3);
            }
            if(advisor[i] == "Zazu"){
                chosenAdvisor.push_back(4);
            }
            if(advisor[i] == "Sarafina"){
                chosenAdvisor.push_back(5);
            }
        }
        advisorChoiceCounter = 0;
    }

    ifstream eventfile("random_events.txt");
    if (!eventfile.is_open()){
        cout << "Error could not open file 'random_events.txt'" << endl;
        return -1;
    }
    string eventline;

    getline(eventfile, eventline);
    
    while (getline(eventfile, eventline)){
        if (eventline.empty()){
            continue;
        }

        string events[5];
        lib.split(cline, '|', events, 5);

        int pride_points = stoi(events[5]);
        randomEvents.push_back(pride_points);
        // maybe make another constructor
        // create main menu
    }

    bool wonGame = false;
    int currentPlayer = 0;

    while(!wonGame){
        cout << "It is now Player " << currentPlayer + 1 << "'s turn." << endl;
        bool turnEnd = false;

        while(!turnEnd){
            int choice = lib.runMenu(0);

            switch(choice){
                case 1:
                    cout << playerName[currentPlayer] << "'s Pride points: " << playerData[currentPlayer].getPridePoints() << endl;
                    cout << playerName[currentPlayer] << "'s Stamina: " << playerData[currentPlayer].getStamina() << endl;
                    cout << playerName[currentPlayer] << "'s Strength: " << playerData[currentPlayer].getStrength() << endl;
                    cout << playerName[currentPlayer] << "'s Wisdom: " << playerData[currentPlayer].getWisdom() << endl;
                    break;
                case 2:
                    cout << playerName[currentPlayer] << "'s Character: " << playerData[currentPlayer].getName() << endl;
                    cout << playerName[currentPlayer] << "'s Age: " << playerData[currentPlayer].getAge() << endl;
                    break;
                case 3:
                    // display board function
                    break;
                case 4:
                    switch(chosenAdvisor[currentPlayer]){
                        case 0:
                            cout << playerName[currentPlayer] << " does not have an advisor." << endl;
                            break;
                        case 1:
                            cout << playerName[currentPlayer] << " has Rafiki as their advisor." << endl;
                            cout << "Special Ability: Invisibility (the ability to become un-seen)" << endl;
                            continue;
                        case 2:
                            cout << playerName[currentPlayer] << " has Nala as their advisor." << endl;
                            cout << "Special Ability: Night Vision (the ability to see clearly in darkness)" << endl;
                            continue;
                        case 3:
                            cout << playerName[currentPlayer] << " has Sarabi as their advisor." << endl;
                            cout << "Special Ability: Energy Manipulation (the ability to shape and control the properties of energy)" << endl;
                            continue;
                        case 4:
                            cout << playerName[currentPlayer] << " has Zazu as their advisor." << endl;
                            cout << "Special Ability: Weather Control (the ability to influence and manipulate weather patterns)" << endl;
                            continue;
                        case 5:
                            cout << playerName[currentPlayer] << " has Sarafina as their advisor." << endl;
                            cout << "Special Ability: Super Speed (the ability to run 4x faster than the maximum speed of lions)" << endl;
                            continue;
                    }
                    cout << "Would you like to change your advisor? (Y/N)" << endl;
                    char choice;
                    cin >> choice;
                    bool change = false;
                    while(!change){
                        switch(choice){
                        case 'Y':
                            cout << "1. Rafiki - Invisibility (the ability to become un-seen)" << endl;
                            cout << "2. Nala - Night Vision (the ability to see clearly in darkness)" << endl;
                            cout << "3. Sarabi - Energy Manipulation (the ability to shape and control the properties of energy)" << endl;
                            cout << "4. Zazu - Weather Control (the ability to influence and manipulate weather patterns)" << endl;
                            cout << "5. Sarafina - Super Speed (the ability to run 4x faster than the maximum speed of lions)" << endl;
                            cout << "Who would you like to change your advisor to?" << endl;
                        case 'N':
                            change = true;
                            break;
                        default:
                            cout << "Invalid choice. Please enter a valid input." << endl;
                            continue;
                        }
                    }
                    break;
                case 5:
                    turnEnd = true;
                    break;
                default:
                    cout << "Invalid input. Please select a valid option." << endl;
                    break;
            }
        }
        if (!wonGame){
            currentPlayer = (currentPlayer + 1) % stoi(playerCount);
        }else{
            cout << playerData[currentPlayer].getName() << " has reached the end!" << endl;
            currentPlayer = (currentPlayer + 1) % stoi(playerCount);
        }
    }

    return 0;
}
