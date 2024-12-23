// Worked with Pranav Konijeti

#include "Board.h"
#include "Player.h"
#include "RandomEvents.h"
#include "Library.h"
#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m"  /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()



void Board::initializeBoard(int player_count, vector<bool> board_type) //initilaizes board based on amount of players and their choice of board type
{
    // Seed random number generator in your main function once

    srand(time(0));
    vector<int> pride;
    vector<int> cub;

    for (int i = 0; i < player_count; i++)
    {
        if(board_type[i] == 0){
            pride.push_back(i+1);
        }else{
            cub.push_back(i+1);
        }
    }
    initializePrideLands(pride);
    initializeCubTraining(cub);
}

void Board::initializePrideLands(vector<int> pride) // initilazies pride lands based on the amount of players who chose the pride lands
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    int half_board = _BOARD_SIZE / 2;

    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        } 
        else if (i == 0) {
            // Set the first tile as the starting tile
            temp.color = 'Y';
        } 
        else if (green_count < 20 && (rand() % (total_tiles - i) < 20 - green_count)) {
            temp.color = 'G';
            green_count++;
        }
        else
        {
                if(i < half_board){
                    // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
                    int color_chance = rand() % 100;
                    if(color_chance < 25){
                        temp.color = 'R'; //graveyard 25%
                    }else if(color_chance < 50){
                        temp.color = 'N'; //hyena 25%
                    }else if(color_chance < 70){
                        temp.color = 'P'; //advisor 20%
                    }else if(color_chance < 75){
                        temp.color = 'B'; //oasis 5%
                    }else{
                        temp.color = 'U'; //challenge 25%
                    }
                }else{
                    int color_chance = rand() % 100;
                    if(color_chance < 15){
                        temp.color = 'R'; //graveyard 15%
                    }else if(color_chance < 30){
                        temp.color = 'N'; //hyena 15%
                    }else if(color_chance < 50){
                        temp.color = 'P'; //advisor 20%
                    }else if(color_chance < 75){
                        temp.color = 'B'; //oasis 25%
                    }else{
                        temp.color = 'U'; //challenge 25%
                    }
                }
        }
        // Assign the tile to the board for the specified lane
        _tiles[0][i] = temp;
    }
}

void Board::initializeCubTraining(vector<int> cub) //initalizes cub training path based on number of players who chose cub training
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    int half_board = _BOARD_SIZE / 2;

    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'O';
        } 
        else if (i == 0) {
            // Set the last tile as Orange for "Pride Rock"
            temp.color = 'Y';
        } 
        else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count)) {
            temp.color = 'G';
            green_count++;
        }
        else
        {
                if(i < half_board){
                    // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
                    int color_chance = rand() % 100;
                    if(color_chance < 20){
                        temp.color = 'R'; //graveyard 20%
                    }else if(color_chance < 40){
                        temp.color = 'N'; //hyena 20%
                    }else if(color_chance < 55){
                        temp.color = 'P'; //advisor 15%
                    }else if(color_chance < 80){
                        temp.color = 'B'; //oasis 25%
                    }else{
                        temp.color = 'U'; //challenge 20%
                    }
                }else{
                    int color_chance = rand() % 100;
                    if(color_chance < 20){
                        temp.color = 'R'; //graveyard 20%
                    }else if(color_chance < 40){
                        temp.color = 'N'; //hyena 20%
                    }else if(color_chance < 55){
                        temp.color = 'P'; //advisor 15%
                    }else if(color_chance < 70){
                        temp.color = 'B'; //oasis 15%
                    }else{
                        temp.color = 'U'; //challenge 30%
                    }
                }
        }
        // Assign the tile to the board for the specified lane
        _tiles[1][i] = temp;
    }
}


Board::Board() // board constructor
{
    _player_count = 1;
    _pride = {0};

    // Initialize player position
    _player_position[0] = 0;

    // Initialize tiles
    initializePrideLands(_pride);
}

Board::Board(int player_count, vector<bool> board_type) // board constructor initalizes board
{
    if (player_count > _MAX_PLAYERS-1)
    {
        _player_count = _MAX_PLAYERS-1;
    }
    else
    {
        _player_count = player_count;
    }

    // Initialize player position
    for (int i = 0; i <= _player_count; i++)
    {
        _player_position[i] = 0;
    }

    // Initialize tiles

    initializeBoard(_player_count, board_type);
}

bool Board::isPlayerOnTile(int player_index, int pos) // checks if player is on tile using their position index
{
    if(_player_position[player_index] > 51){
        _player_position[player_index] = 51;
    }
    if (_player_position[player_index] == pos)
    {
        return true;
    }
    return false;
}

void Board::displayTile(vector<int> player_indexs, int pos, bool board_type) // displays tile, utilized in the display trakc funciton
{
    int playerIndexSize = player_indexs.size();
    string color = "";
    vector<bool> players;
    vector<int> onPos;
    int temp;
    for(int i = 0; i < playerIndexSize; i++){  // this checks if each player is on the tile
        temp = isPlayerOnTile(player_indexs[i], pos);
        players.push_back(temp);
    }
    for(int i = 0; i < playerIndexSize; i++){ // this pushes the players that are on the tiles
        if(players[i] == 1){
            onPos.push_back(player_indexs[i]);
        }
    }
    int onPosSize = onPos.size(); 

    // Determine color to display
    if (_tiles[board_type][pos].color == 'R')
    {
        color = RED;
    }
    else if (_tiles[board_type][pos].color == 'G')
    {
        color = GREEN;
    }
    else if (_tiles[board_type][pos].color == 'B')
    {
        color = BLUE;
    }
    else if (_tiles[board_type][pos].color == 'U')
    {
        color = PURPLE;
    }
    else if (_tiles[board_type][pos].color == 'N')
    {
        color = BROWN;
    }
    else if (_tiles[board_type][pos].color == 'P')
    {
        color = PINK;
    }
    else if (_tiles[board_type][pos].color == 'O')
    {
        color = ORANGE;
    }
    else if (_tiles[board_type][pos].color == 'Y')
    {
        color = GREY;
    }

    if(onPosSize > 0){ 
        if(onPosSize == 1){
            cout << color << "|" << (onPos[0]) << "|" << RESET; // this displays the player if there is only one player on the tile
        }
        else{
            cout << color << "|"; // this is the display for multiple players on the tile
            for(int i = 0; i < onPosSize; i++){
                cout << onPos[i];
                if(i < onPosSize-1){
                    cout << "&";
                }
            }
            cout << "|" << RESET;
        }
        
    }
    else{ // this is if there are no players on the tile
        cout << color << "| |" << RESET;
    }
}

void Board::displayTrack(vector<int> player_indexs, bool board_type) // displays every tile in the track
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(player_indexs, i, board_type);
    }
    cout << endl;
}

void Board::displayBoard(vector<bool> board_type) // displays the two tracks as one board
{
    int boardTypeSize = board_type.size();
    vector<int> pride;
    vector<int> cub;
    for(int i = 0; i < boardTypeSize; i++){
        if(board_type[i] == 0){
            pride.push_back(i+1);
        }else{
            cub.push_back(i+1);
        }
    }
    displayTrack(pride, 0);
    cout << endl;
    displayTrack(cub, 1);
    cout << endl;
    
}


bool Board::movePlayer(int player_index, bool board_type, Player playerData[5], RandomEvents randomEvents[8], int chosenAdvisor[6], RandomEvents riddles[3]) // this moves the player and also handles any events that happens through the interntalized player event file
{
    playerData[player_index].setTilePosition(0);
    // Increment player position
    Library lib;

    int moves = lib.runSpinner(player_index);

    cout << "You spun a " << moves << "!" << endl;

    _player_position[player_index+1] += moves;
    playerEvent(player_index, board_type, playerData, randomEvents, chosenAdvisor, riddles);
    if(_hyenaTile == 1){ // checks if there on a hyena tile
        _hyenaTile = 0;
        _player_position[player_index+1] -= moves;
    }
    if(_player_position[player_index+1] < 0){ // in case the players somehow go behind the track
        _player_position[player_index+1] = 0;
    }
    if(_player_position[player_index] > 51){ // this makes sure hte player cant go beyond hte track
        _player_position[player_index] = 51;
        return true;
    }
    if (_player_position[player_index] == _BOARD_SIZE - 1) 
    {
        // Player reached last tile
        return true;
    }
    return false;
}

void Board::playerEvent(int player_index, bool board_type, Player playerData[5], RandomEvents randomEvents[8], int chosenAdvisor[6], RandomEvents riddles[3])
{
    char tile = _tiles[board_type][_player_position[player_index+1]].color; // finds the tile the player is on and takes the corresponding character from it
    switch(tile)
    {   case 'G': // case that they are on a regular grassland tile
            int greenEvent;
            greenEvent = rand() % 2;
            if(greenEvent == 0){
                break;
            }
            else if(greenEvent == 1){
                int actualEvent;
                if(board_type == 0){
                    actualEvent = rand() % 6 + 2;
                }
                if(board_type == 1){
                    actualEvent = rand() % 4;
                    if(actualEvent == 2){
                        actualEvent = 6;
                    }
                    if(actualEvent == 3){
                        actualEvent = 7;
                    }
                }
                cout << "Random Event: " << randomEvents[actualEvent].getDescription() << "." << endl;
                if(chosenAdvisor[player_index] == randomEvents[actualEvent].getAdvisor() && chosenAdvisor[player_index] != 0){
                    cout << "Due to your advisor's ability, the event was nullified." << endl;
                    break;
                }
                if(randomEvents[actualEvent].getPridePoints() > 0){
                    cout << "You gained " << randomEvents[actualEvent].getPridePoints() <<  " pride points." << endl;
                }
                if(randomEvents[actualEvent].getPridePoints() < 0){
                    cout << "You lost " << -1*randomEvents[actualEvent].getPridePoints() <<  " pride points." << endl;
                }
                playerData[player_index].addPridePoints(randomEvents[actualEvent].getPridePoints());
            }
            break;
        case 'B': // this is the oasis tile
            cout << "Player " << player_index+1 << ", you've found a peaceful oasis! This grants the player an extra turn to keep moving forward—take a deep breath and relax; you also gain 200 Stamina, Strength, and Wisdom Points." << endl << endl;
            playerData[player_index].addStamina(200);
            playerData[player_index].addStrength(200);
            playerData[player_index].addWisdom(200);
            playerData[player_index].setTilePosition(2);
            break;
        case 'P': // this is the enrichment tile
            cout << "Player " << player_index+1 << ", welcome to the land of enrichment - when landing on this tile, your Stamina, Strength, and Wisdom Points increase by 300, and you get to choose an advisor from the available list of advisors on your next turn. If you already have an advisor, you can switch your advisor out for a different one from the list or keep your original advisor. Don’t forget - an advisor can protect you from random events that negatively impact your Pride Points." << endl << endl;
            playerData[player_index].addStamina(300);
            playerData[player_index].addStrength(300);
            playerData[player_index].addWisdom(300);
            playerData[player_index].setTilePosition(1);
            break;
        case 'R': // this is the graveyard tile
            cout << "Player " << player_index+1 << ", uh-oh, you've stumbled into the Graveyard! This forces the player to move back 10 tiles and lose 100 Stamina, Strength, and Wisdom Points." << endl << endl;
            playerData[player_index].addStamina(-100);
            playerData[player_index].addStrength(-100);
            playerData[player_index].addWisdom(-100);
            _player_position[player_index+1] -= 10;
            if(_player_position[player_index+1] < 0){
                _player_position[player_index+1] = 0;
            }
            break;
        case 'N': // this is the hyena tile
            cout << "Player " << player_index+1 << ", the Hyenas are on the prowl! They drag you back to where you were last, and the journey comes at a cost. This returns the player to their previous position. In addition, the player's Stamina Points decrease by 300 Points." << endl << endl;
            playerData[player_index].addStamina(-300);
            _hyenaTile = 1;
            break;
        case 'U': // this is the challenge tile
            cout << "Player " << player_index+1 << ", time for a test of wits! Land here, and you'll face a riddle randomly pulled from the riddles.txt file. Answer correctly, and you'll earn a boost of 500 Points to your Wisdom Trait—your cleverness pays off!" << endl << endl;
            int riddleEvent = rand() % 3;
            string answer;
            cout << riddles[riddleEvent].getRiddleDescription() << endl;
            cin >> answer;
            if(answer == riddles[riddleEvent].getRiddleAnswer()){
                cout << "That's correct! You got 500 additional points in wisdom." << endl;
                playerData[player_index].addWisdom(500);
            }else{
                cout << "That's incorrect. Unfortunately, you don't get any points added." << endl;
            }
            break;
    }
}

int Board::getPlayerPosition(int player_index) const // gets player position utilizng their number stored in the player position array
{
    if (player_index >= 0 && player_index <= _player_count)
    {
        return _player_position[player_index];
    }
    return -1;
}

int Board::evaluatePlayer(int player_index,  Player playerData[5]){ // converts their leadership traits to pride points
    int points = playerData[player_index].getPridePoints() + (playerData[player_index].getStamina() * 10) + (playerData[player_index].getStrength() * 10) + (playerData[player_index].getWisdom() * 10);
    return points;
}
