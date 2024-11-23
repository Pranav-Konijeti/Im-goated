#include <iostream>
#include <string>
using namespace std;

class Player{
private:
    string _name;
    int _strength, _stamina, _wisdom, _pride_points, _age;

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

    //Setters
    void setName(string name);
    void setStrength(int strength);
    void setStamina(int stamina);
    void setWisdom(int wisdom);
    void setPridePoints(int pride_points);
    void setAge(int age);

    //Other
    void trainCub(int strength, int stamina, int wisdom);
    void toPrideLands();
    void printStats();
};