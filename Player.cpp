#include "Player.h"

//Constructors
Player::Player(){
    _name = "";
    _age = 1;
    _stamina = 100;
    _strength = 100;
    _wisdom = 100;
}

Player::Player(string name, int strength, int stamina, int wisdom){
    _name = name;

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

//Getters
string Player::getName(){
    return _name;
}

int Player::getStrength(){
    return _strength;
}

int Player::getStamina(){
    return _stamina;
}

int Player::getWisdom(){
    return _wisdom;
}

int Player::getPridePoints(){
    return _pride_points;
}

int Player::getAge(){
    return _age;
}

//Setters
void Player::setName(string name){
    _name = name;
}

void Player::setStrength(int strength){
    _strength = strength;
}

void Player::setStamina(int stamina){
    _stamina = stamina;

}

void Player::setWisdom(int wisdom){
    _wisdom = wisdom;

}

void Player::setPridePoints(int pride_points){
    _pride_points = pride_points;
}

void Player::setAge(int age){
    _age = age;
}

//Other
void Player::trainCub(int strength, int stamina, int wisdom){
    _pride_points -= 5000;
    _strength += strength;
    _stamina += stamina;
    _wisdom += wisdom;
}

void Player::toPrideLands(){
    _pride_points += 5000;
    _strength -= 2000;
    _wisdom -= 2000;
    _stamina -= 2000;
}

void Player::printStats(){
    cout << "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
    cout << "Player Stats:" << endl << endl;
    cout << _name << ", age " << _age << endl;
    cout << "Strength: " << _strength << endl;
    cout << "Stamina: " << _stamina << endl;
    cout << "Wisdom: " << _wisdom << endl;
    cout << "Pride Points: " << _pride_points << endl;
    cout << "~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*" << endl;
}
