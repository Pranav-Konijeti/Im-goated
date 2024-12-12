// Worked with Eddie Chiu

#include "Player.h"

// Constructors
Player::Player(){
    _name = "";
    _age = 1;
    _stamina = 100;
    _strength = 100;
    _wisdom = 100;
    _pos = 0;
}

Player::Player(string name, int strength, int stamina, int wisdom){
    _name = name;
    _pos = 0;

    if(strength < 100 || strength > 1000){
        _strength = 100;
    }else{
        _strength = strength;
    }

    if(stamina < 100 || stamina > 1000){
        _stamina = 100;
    }else{
        _stamina = stamina;
    }

    if(wisdom < 100 || wisdom > 1000){
        _wisdom = 100;
    }else{
        _wisdom = wisdom;
    }
}

// Getters
string Player::getName(){ // gets name of player
    return _name;
}

int Player::getStrength(){ // gets strength of player
    return _strength;
}

int Player::getStamina(){ // gets stamina of player
    return _stamina;
}

int Player::getWisdom(){ // gets wisdom of player
    return _wisdom;
}

int Player::getPridePoints(){ // gets pride points of player
    return _pride_points;
}

int Player::getAge(){ // gets age of player
    return _age;
}

int Player::getTilePosition(){ // gets position of player
    return _pos;
}


// Setters
void Player::setName(string name){ // sets player's name
    _name = name;
}

void Player::setStrength(int strength){ // sets player's strength
    _strength = strength;
}

void Player::setStamina(int stamina){ // sets player's stamina
    _stamina = stamina;

}

void Player::setWisdom(int wisdom){ // sets player's wisdom
    _wisdom = wisdom;

}

void Player::setPridePoints(int pride_points){ // sets player's pride points
    _pride_points = pride_points;
}

void Player::setAge(int age){ // sets player's age
    _age = age;
}

void Player::setTilePosition(int pos){ // set's player's position
    _pos = pos;
}

// Adders
void Player::addStrength(int strength){ // adds strength to player based on input
    _strength += strength;
    if(_strength < 100){
        _strength = 100;
    }
}

void Player::addStamina(int stamina){ // adds stamina to player based on input
    _stamina += stamina;
    if(_stamina < 100){
        _stamina = 100;
    }
}

void Player::addWisdom(int wisdom){ // adds wisdom to player based on input
    _wisdom += wisdom;
    if(_wisdom < 100){
        _wisdom = 100;
    }
}

void Player::addPridePoints(int pride_points){ // adds pride points to player based on input
    _pride_points += pride_points;
}

// Other
void Player::toCubTraining(int strength, int stamina, int wisdom){ // cub training path
    _pride_points -= 5000;
    _strength += strength;
    _stamina += stamina;
    _wisdom += wisdom;
}

void Player::toPrideLands(int strength, int stamina, int wisdom){ // straight to pridelands path
    _pride_points += 5000;
    _strength += strength;
    _wisdom += stamina;
    _stamina += wisdom;
}

void Player::printStats(){ // prints player stats
    cout << "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
    cout << "Player Stats:" << endl << endl;
    cout << _name << ", age " << _age << endl;
    cout << "Strength: " << _strength << endl;
    cout << "Stamina: " << _stamina << endl;
    cout << "Wisdom: " << _wisdom << endl;
    cout << "Pride Points: " << _pride_points << endl;
    cout << "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
}
