// Worked with Eddie Chiu

#ifndef BOARD_H
#define BOARD_H
#include "Tile.h"
#include "Player.h"
#include "RandomEvents.h"
#include <vector>

class Board
{
private:
    static const int _BOARD_SIZE = 52;
    Tile _tiles[5][_BOARD_SIZE];
    static const int _MAX_PLAYERS = 5;
    int _player_count;
    vector<int> _pride;
    int _player_position[_MAX_PLAYERS];
    int _hyenaTile = 0;
    void displayTile(vector<int> player_indexs, int pos, bool board_type);
    void initializeCubTraining(vector<int> cub);
    void initializePrideLands(vector<int> pride);
    bool isPlayerOnTile(int player_index, int pos);

public:
    Board();
    Board(int player_count, vector<bool> board_type);
    void displayTrack(vector<int> player_indexs, bool board_type);
    void initializeBoard(int player_count, vector<bool> board_type);
    void displayBoard(vector<bool> board_type);
    bool movePlayer(int player_index, bool board_type, Player playerData[5], RandomEvents randomEvents[8], int chosenAdvisor[6], RandomEvents riddles[3]);
    void playerEvent(int player_index, bool board_type, Player playerData[5], RandomEvents randomEvents[8], int chosenAdvisor[6], RandomEvents riddles[3]);
    int getPlayerPosition(int player_index) const;
    int evaluatePlayer(int player_index, Player playerData[5]);
};

#endif
