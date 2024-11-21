#ifndef BOARD_H
#define BOARD_H
#include "Tile.h"
#include <vector>

class Board
{
private:
    static const int _BOARD_SIZE = 52;
    Tile _tiles[2][_BOARD_SIZE];
    static const int _MAX_PLAYERS = 2;
    int _player_count;
    vector<bool> _board_type;
    int _player_position[_MAX_PLAYERS];
    void displayTile(int player_index, int pos, bool board_type);
    void initializeCubTraining(int player_index);
    void initializePrideLands(int player_index);
    bool isPlayerOnTile(int player_index, int pos);

public:
    Board();
    Board(int player_count, vector<bool> board_type);
    void displayTrack(int player_index, bool board_type);
    void initializeBoard(int player_count, vector<bool> board_type);
    void displayBoard(vector<bool> board_type);
    bool movePlayer(int player_index);
    void playerStatus(int player_index);
    int getPlayerPosition(int player_index) const;
};

#endif
