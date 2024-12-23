// Worked with Pranav Konijeti

#include "RandomEvents.h"

// constructors
RandomEvents::RandomEvents(){
    _description = "";
    _pathType = 0;
    _advisor = 0;
    _pridePoints = 0;
    _riddleDescription = "";
    _riddleAnswer = "";
}

RandomEvents::RandomEvents(string description, int pathType, int advisor, int pridePoints){
    _description = description;
    _pathType = pathType;
    _advisor = advisor;
    _pridePoints = pridePoints;
}


//getters for riddles
string RandomEvents::getRiddleDescription(){
    return _riddleDescription;
}
string RandomEvents::getRiddleAnswer(){
    return _riddleAnswer;
}

//getters for random events
string RandomEvents::getDescription(){
    return _description;
}
int RandomEvents::getPathType(){
    return _pathType;
}
int RandomEvents::getAdvisor(){
    return _advisor;
}
int RandomEvents::getPridePoints(){
    return _pridePoints;
}

//setters for random events
string RandomEvents::setDescription(string description){
    _description = description;
    return _description;
}
int RandomEvents::setPathType(int pathType){
    _pathType = pathType;
    return _pathType;
}
int RandomEvents::setAdvisor(int advisor){
    _advisor = advisor;
    return _advisor;
}
int RandomEvents::setPridePoints(int pridePoints){
    _pridePoints = pridePoints;
    return _pridePoints;
}

//setters for riddles

string RandomEvents::setRiddleDescription(string description2){
    _riddleDescription = description2;
    return _riddleDescription;
}
string RandomEvents::setRiddleAnswer(string answer){
    _riddleAnswer = answer;
    return _riddleAnswer;
}
