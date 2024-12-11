#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
using namespace std;

class Player{
private:
    string _name;
    int _strength, _stamina, _wisdom, _pride_points, _age, _pos;

public:
    //Constructors
    Player();
    Player(string name, int strength, int stamina, int wisdom);

    //Getters
    string getName();
    int getStrength();
    int getStamina();
    int getWisdom();
    int getPridePoints();
    int getAge();
    int getTilePosition();

    //Setters
    void setName(string name);
    void setStrength(int strength);
    void setStamina(int stamina);
    void setWisdom(int wisdom);
    void setPridePoints(int pride_points);
    void setAge(int age);
    void setTilePosition(int pos);


    //Adders
    void addStrength(int strength);
    void addStamina(int stamina);
    void addWisdom(int wisdom);
    void addPridePoints(int pride_points);

    //Other
    void toCubTraining(int strength, int stamina, int wisdom);
    void toPrideLands(int strength, int stamina, int wisdom);
    void printStats();
};

#endif
