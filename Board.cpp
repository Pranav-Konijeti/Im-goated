#include "Board.h"
#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m"  /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"

void Board::initializeBoard(int player_count, vector<bool> board_type)
{
    // Seed random number generator in your main function once
    for (int i = 0; i < player_count; i++)
    {
        if(board_type[i] == 0){
            initializePrideLands(i);
        }else{
            initializeCubTraining(i);
        }
// This ensures each lane has a unique tile distribution
    }
}

#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

void Board::initializePrideLands(int player_index)
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
                    if(color_chance < 25){
                        temp.color = 'R'; //graveyard 25%
                    }else if(color_chance < 50){
                        temp.color = 'B'; //hyena 25%
                    }else if(color_chance < 70){
                        temp.color = 'P'; //advisor 20%
                    }else if(color_chance < 75){
                        temp.color = 'B'; //oasis 5%
                    }else{
                        temp.color = 'P'; //challenge 25%
                    }
                }else{
                    int color_chance = rand() % 100;
                    if(color_chance < 15){
                        temp.color = 'R'; //graveyard 15%
                    }else if(color_chance < 30){
                        temp.color = 'B'; //hyena 15%
                    }else if(color_chance < 50){
                        temp.color = 'P'; //advisor 20%
                    }else if(color_chance < 75){
                        temp.color = 'B'; //oasis 25%
                    }else{
                        temp.color = 'P'; //challenge 25%
                    }
                }
        }
        // Assign the tile to the board for the specified lane
        _tiles[player_index][i] = temp;
    }
}

void Board::initializeCubTraining(int player_index)
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
        else if (green_count < 20 && (rand() % (total_tiles - i) < 20 - green_count)) {
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
                        temp.color = 'B'; //hyena 20%
                    }else if(color_chance < 55){
                        temp.color = 'P'; //advisor 15%
                    }else if(color_chance < 80){
                        temp.color = 'B'; //oasis 25%
                    }else{
                        temp.color = 'P'; //challenge 20%
                    }
                }else{
                    int color_chance = rand() % 100;
                    if(color_chance < 20){
                        temp.color = 'R'; //graveyard 20%
                    }else if(color_chance < 40){
                        temp.color = 'B'; //hyena 20%
                    }else if(color_chance < 55){
                        temp.color = 'P'; //advisor 15%
                    }else if(color_chance < 70){
                        temp.color = 'B'; //oasis 15%
                    }else{
                        temp.color = 'P'; //challenge 30%
                    }
                }
        }
        // Assign the tile to the board for the specified lane
        _tiles[player_index][i] = temp;
    }
}


Board::Board()
{
    _player_count = 1;
    _board_type = {0};

    // Initialize player position
    _player_position[0] = 0;

    // Initialize tiles
    initializePrideLands(_player_position[0]);
}

Board::Board(int player_count, vector<bool> board_type)
{
    if (player_count > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = player_count;
    }



    // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
        _player_position[i] = 0;
    }

    // Initialize tiles

    initializeBoard(player_count, board_type);
}

bool Board::isPlayerOnTile(int player_index, int pos)
{
    if (_player_position[player_index] == pos)
    {
        return true;
    }
    return false;
}

void Board::displayTile(int player_index, int pos, bool board_type)
{
    // string space = "                                       ";
    string color = "";
    int player = isPlayerOnTile(player_index, pos);

    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| <reset color> <line filler space> <endl>

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

     if (player == true)
    {
        cout << color << "|" << (player_index + 1) << "|" << RESET;
    }
    else
    {
        cout << color << "| |" << RESET;
    }
}

void Board::displayTrack(int player_index, bool board_type)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(player_index, i, board_type);
    }
    cout << endl;
}

void Board::displayBoard(vector<bool> board_type)
{
    for (int i = 0; i < board_type.size(); i++)
    {
        displayTrack(i, board_type[i]);
        if (i == 0) {
            cout << endl;  // Add an extra line between the two lanes
        }
    }
}

bool Board::movePlayer(int player_index)
{
    // Increment player position
    _player_position[player_index]++;
    if (_player_position[player_index] == _BOARD_SIZE - 1)
    {
        // Player reached last tile
        return true;
    }
    return false;
}

int Board::getPlayerPosition(int player_index) const
{
    if (player_index >= 0 && player_index <= _player_count)
    {
        return _player_position[player_index];
    }
    return -1;
}
