// Worked with Eddie Chiu

#include "Board.h"
#include "Tile.h"
#include "RandomEvents.h"
#include "Library.h"
#include "Player.h"
#include <iostream>
#include <fstream>

int main() {
    Library lib;

    string tempName;
    string tempChoice;
    string pathChoice;
    string playerCount;
    string characterLine;
    string advisor[5] = {"Rafiki", "Nala", "Sarabi", "Zazu", "Sarafina"};
    string next;
    
    int playerCountCounter = 0;
    int playerChoiceCounter = 0;
    int breaker1 = 0;
    int pathChoiceInteger;
    int pathChoiceCounter = 0;
    int actualPlayerCount;
    int counter = 0;
    int counter2 = 0;
    int wonCount = 0;

    RandomEvents randomEvents[8];
    RandomEvents riddles[2];

    vector<bool> boardType;
    vector<string> playerName;
    vector<Player> playerData;
    vector<Player> characterList;
    vector<string> chosenCharacters;
    vector<int> chosenAdvisor;
    vector<bool> endReached;
    vector<int> playerPoints;

    bool advisorAvail[6] = {false, false, false, false, false, false};

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
    actualPlayerCount = stoi(playerCount);
    
    for(int i = 0; i < actualPlayerCount; i++){
        cout << "Player " << i + 1 << ", Please enter your name: ";

        do{
            getline(cin, tempName);
        }while(tempName.empty());
        playerName.push_back(tempName);
        endReached.push_back(false);

        int characterListSize = characterList.size();
        for(int l = 0; l < characterListSize; l++){
            characterList[l].printStats();
        }

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
                characterList.erase(characterList.begin() + k);
            }
        }
    }

    Player playerData2[5];
    for(int i = 0; i < playerData.size(); i++){
        playerData2[i] = playerData[i];
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
            playerData2[i].toPrideLands(200, 200, 200);
            cout << "You chose: Pride Lands. You gained 200 strength, 200 stamina, 200 wisdom, and 5000 pride points. Unfortunately, you do not get to choose an advisor at this time." << endl;
            chosenAdvisor.push_back(0);
        }
        else{
            playerData2[i].toCubTraining(500, 500, 1000);
            bool choiceCompleted = false;
            while(!choiceCompleted){
                cout << endl << "Available advisors:" << endl;
                for(int j = 1; j <= 5; j++){
                    if(!advisorAvail[j]){
                        switch(j){
                            case 1:
                                cout << "1. Rafiki - Invisibility (the ability to become un-seen)" << endl;
                                break;
                            case 2:
                                cout << "2. Nala - Night Vision (the ability to see clearly in darkness)" << endl;
                                break;
                            case 3:
                                cout << "3. Sarabi - Energy Manipulation (the ability to shape and control the properties of energy)" << endl;
                                break;
                            case 4:
                                cout << "4. Zazu - Weather Control (the ability to influence and manipulate weather patterns)" << endl;
                                break;
                            case 5:
                                cout << "5. Sarafina - Super Speed (the ability to run 4x faster than the maximum speed of lions)" << endl;
                        }
                    }
                }

                string advisorChoice;
                getline(cin, advisorChoice);
                int cAdvisorSize = chosenAdvisor.size();

                if (advisorChoice == "1" || advisorChoice == "2" || advisorChoice == "3" || advisorChoice == "4" || advisorChoice == "5") {
                    if(!advisorAvail[stoi(advisorChoice)]){
                        if(cAdvisorSize > i && chosenAdvisor[i] != 0){
                            advisorAvail[chosenAdvisor[i]] = false;
                        }

                        if(cAdvisorSize <= i){
                            chosenAdvisor.push_back(stoi(advisorChoice));
                        }else{
                            chosenAdvisor[i] = stoi(advisorChoice);
                        }

                        advisorAvail[stoi(advisorChoice)] = true;
                        cout << "You have chosen " << advisor[stoi(advisorChoice) - 1] << " successfully!" << endl;
                        choiceCompleted = true;
                    }else{
                        cout << "This advisor has already been chosen by another player. Please select a different advisor." << endl << endl;
                    }
                } else {
                    cout << "Invalid choice. Please choose a valid advisor." << endl << endl;
                }
            }
        }
        pathChoiceCounter = 0;
    }

    int chosenAdvisor2[6];
    for(int i = 0; i < chosenAdvisor.size(); i++){
        chosenAdvisor2[i] = chosenAdvisor[i];
    }

    Board board(actualPlayerCount, boardType);
    board.displayBoard(boardType);

    ifstream eventfile("random_events.txt");
    if (!eventfile.is_open()){
        cout << "Error could not open file 'random_events.txt'" << endl;
        return -1;
    }
    string eventline;

    
    while (getline(eventfile, eventline)){
        if (eventline.empty()){
            continue;
        }
        string events[4];
        lib.split(eventline, '|', events, 4);
        
        randomEvents[counter].setDescription(events[0]);
        randomEvents[counter].setPathType(stoi(events[1]));
        randomEvents[counter].setAdvisor(stoi(events[2]));
        randomEvents[counter].setPridePoints(stoi(events[3]));
        counter++;
    }

    ifstream eventfile2("riddles.txt");
    if (!eventfile2.is_open()){
        cout << "Error could not open file 'random_events.txt'" << endl;
        return -1;
    }
    string eventline2;

    
    while (getline(eventfile2, eventline2)){
        if (eventline2.empty()){
            continue;
        }
        string events2[2];
        lib.split(eventline2, '|', events2, 2);
        
        riddles[counter2].setRiddleDescription(events2[0]);
        riddles[counter2].setRiddleAnswer(events2[1]);
        
        counter2++;
    }

    bool wonGame = false;
    int currentPlayer = 0;
    string advisorChoice2;

    while(!wonGame){
        cout << "It is now Player " << currentPlayer + 1 << "'s turn." << endl;
        bool turnEnd = false;

        while(!turnEnd){
            int choice = lib.runMenu("0");

            switch(choice){
                case 1:
                    cout << playerName[currentPlayer] << "'s Strength: " << playerData2[currentPlayer].getStrength() << endl;
                    cout << playerName[currentPlayer] << "'s Stamina: " << playerData2[currentPlayer].getStamina() << endl;
                    cout << playerName[currentPlayer] << "'s Wisdom: " << playerData2[currentPlayer].getWisdom() << endl;
                    cout << playerName[currentPlayer] << "'s Pride points: " << playerData2[currentPlayer].getPridePoints() << endl;
                    cout << "Would you like to display your full stats? Press Y to display full stats, press anything else to go back to main menu." << endl;
                    char statsChoice1;
                    cin >> statsChoice1;
                    if (toupper(statsChoice1) == 'Y') {
                        playerData2[currentPlayer].printStats();
                    }
                    break;
                case 2:
                    cout << playerName[currentPlayer] << "'s Character: " << playerData2[currentPlayer].getName() << endl;
                    cout << playerName[currentPlayer] << "'s Age: " << playerData2[currentPlayer].getAge() << endl;
                    cout << "Would you like to display your full stats? Press Y to display full stats, press anything else to go back to main menu." << endl;
                    char statsChoice2;
                    cin >> statsChoice2;
                    if (toupper(statsChoice2) == 'Y') {
                        playerData2[currentPlayer].printStats();
                    }
                    break;
                case 3:
                    board.displayBoard(boardType);
                    break;
                case 4:
                    switch(chosenAdvisor[currentPlayer]){
                        case 0:
                            cout << playerName[currentPlayer] << " does not have an advisor." << endl;
                            break;
                        case 1:
                            cout << playerName[currentPlayer] << " has Rafiki as their advisor." << endl;
                            cout << "Special Ability: Invisibility (the ability to become un-seen)" << endl;
                            break;
                        case 2:
                            cout << playerName[currentPlayer] << " has Nala as their advisor." << endl;
                            cout << "Special Ability: Night Vision (the ability to see clearly in darkness)" << endl;
                            break;
                        case 3:
                            cout << playerName[currentPlayer] << " has Sarabi as their advisor." << endl;
                            cout << "Special Ability: Energy Manipulation (the ability to shape and control the properties of energy)" << endl;
                            break;
                        case 4:
                            cout << playerName[currentPlayer] << " has Zazu as their advisor." << endl;
                            cout << "Special Ability: Weather Control (the ability to influence and manipulate weather patterns)" << endl;
                            break;
                        case 5:
                            cout << playerName[currentPlayer] << " has Sarafina as their advisor." << endl;
                            cout << "Special Ability: Super Speed (the ability to run 4x faster than the maximum speed of lions)" << endl;
                            break;
                        }
                        char choice;
                        if(chosenAdvisor[currentPlayer] == 0){
                            cout << "Would you to like to choose an advisor? Press Y to choose an advisor, press anything else to go back to main menu." << endl;
                            cin >> choice;

                        }else{
                            cout << "Would you like to change your advisor? Press Y to choose an advisor, press anything else to go back to main menu." << endl;
                            cin >> choice;
                        }

                        if (toupper(choice) == 'Y') {
                            if(playerData[currentPlayer].getTilePosition() == 0 || playerData[currentPlayer].getTilePosition() == 2){
                                cout << "Not on counseling tile. You can only choose or change an advisor on the counseling tile." << endl;
                                break;
                            }else{
                                bool choiceCompleted = false;
                                while(!choiceCompleted){
                                    cout << "Available advisors:" << endl;

                                    for(int i = 1; i <= 5; i++){
                                        if(!advisorAvail[i]){
                                            switch(i){
                                                case 1:
                                                    cout << "1. Rafiki - Invisibility (the ability to become un-seen)" << endl;
                                                    break;
                                                case 2:
                                                    cout << "2. Nala - Night Vision (the ability to see clearly in darkness)" << endl;
                                                    break;
                                                case 3:
                                                    cout << "3. Sarabi - Energy Manipulation (the ability to shape and control the properties of energy)" << endl;
                                                    break;
                                                case 4:
                                                    cout << "4. Zazu - Weather Control (the ability to influence and manipulate weather patterns)" << endl;
                                                    break;
                                                case 5:
                                                    cout << "5. Sarafina - Super Speed (the ability to run 4x faster than the maximum speed of lions)" << endl;
                                            }
                                        }
                                    }
                                    
                                    getline(cin, advisorChoice2);
                                    int cAdvisorSize = chosenAdvisor.size();

                                    if(advisorChoice2.empty()){
                                        getline(cin, advisorChoice2);
                                    }

                                    if (advisorChoice2 == "1" || advisorChoice2 == "2" || advisorChoice2 == "3" || advisorChoice2 == "4" || advisorChoice2 == "5") {
                                        if(!advisorAvail[stoi(advisorChoice2)]){
                                            if(cAdvisorSize > currentPlayer && chosenAdvisor[currentPlayer] != 0){
                                                advisorAvail[chosenAdvisor[currentPlayer]] = false;
                                            }

                                            if(cAdvisorSize <= currentPlayer){
                                                chosenAdvisor.push_back(stoi(advisorChoice2));
                                            }else{
                                                chosenAdvisor[currentPlayer] = stoi(advisorChoice2);
                                            }

                                            advisorAvail[stoi(advisorChoice2)] = true;
                                            cout << "You have chosen " << advisor[stoi(advisorChoice2) - 1] << " successfully!" << endl;
                                            choiceCompleted = true;
                                        }else{
                                            cout << "This advisor has already been chosen by another player. Please select a different advisor." << endl;
                                        }
                                    } else {
                                        cout << "Invalid choice. Please choose a valid advisor." << endl;
                                    }
                                }
                            }
                        }
                    break;
                case 5:
                    playerData2[currentPlayer].setTilePosition(0);
                    board.movePlayer(currentPlayer, boardType[currentPlayer], playerData2, randomEvents, chosenAdvisor2, riddles);
                    board.displayBoard(boardType);
                    if (board.getPlayerPosition(currentPlayer+1) == 51){
                        cout << playerName[currentPlayer] << " has reached the pride rock!" << endl;
                        wonCount++;
                        endReached[currentPlayer] = true;
                    }
                    if(wonCount != actualPlayerCount){
                        cout << "Press anything and click enter to go to the next player's turn" << endl;
                        cin >> next;
                    }
                    if(playerData2[currentPlayer].getTilePosition() == 2){
                        playerData2[currentPlayer].setTilePosition(0);
                        continue;
                    }
                    turnEnd = true;
                    break;
                default:
                    cout << "Invalid input. Please select a valid option." << endl;
                    break;
            }
        }
        //cycles players turns and skips over players that have already reached the end
        
        if(wonCount == actualPlayerCount){
            turnEnd = true;
            wonGame = true;
            break;
        }

        do{
            currentPlayer = (currentPlayer + 1) % actualPlayerCount;
        }while(endReached[currentPlayer] == true);
    }

    playerData2[0].printStats();
    playerData2[1].printStats();

    for(int i = 0; i < actualPlayerCount; i++){
        int points = board.evaluatePlayer(i, playerData2);
        playerPoints.push_back(points);
    }

    //selection sort player points
    int n = playerPoints.size();
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(playerPoints[j] < playerPoints[min]){
                min = j;
            }
        }
        if(min != i){
            int temp = playerPoints[i];
            playerPoints[i] = playerPoints[min];
            playerPoints[min] = temp;
        }
    }

    //prints sorted player points
    cout << "Leaderboard:" << endl;
    for(int i = actualPlayerCount - 1, j = 0; i >= 0; i--, j++){
        cout << j + 1 << " - " << playerName[i] << ": " << playerPoints[i] << endl;
    }
    cout << endl;

    cout << endl << "Winner(s):" << endl;
    cout << 1 << " - " << playerName[actualPlayerCount - 1] << ": " << playerPoints[actualPlayerCount - 1] << endl;
    for(int i = actualPlayerCount - 2, j = 1; i >= 0; i--, j++){
        if(playerPoints[i] == playerPoints[actualPlayerCount - 1]){
            cout << j + 1 << " - " << playerName[i] << ": " << playerPoints[i] << endl;
        }
    }

    ofstream gameStats("endstats.txt");

    for(int i = 0; i < actualPlayerCount; i++){
        gameStats << "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
        gameStats << "Player Stats:" << endl << endl;
        gameStats << playerData[i].getName() << ", age " << playerData[i].getAge() << endl;
        gameStats << "Strength: " << playerData[i].getStrength() << endl;
        gameStats << "Stamina: " << playerData[i].getStamina() << endl;
        gameStats << "Wisdom: " << playerData[i].getWisdom() << endl;
        gameStats << "Pride Points: " << playerData[i].getPridePoints() << endl;
        gameStats << "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl << endl;
    }

    return 0;
}
