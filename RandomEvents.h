#ifndef RANDOMEVENTS_H
#define RANDOMEVENTS_H
#include <iostream>
using namespace std;

class RandomEvents{
private:
    string _description;
    string _riddleDescription;
    string _riddleAnswer;
    int _pathType;
    int _advisor;
    int _pridePoints;


public:
    RandomEvents();
    RandomEvents(string description, int pathType, int advisor, int pridePoints);

    string getRiddleDescription();
    string getRiddleAnswer();

    string getDescription();
    int getPathType();
    int getAdvisor();
    int getPridePoints();

    string setRiddleDescription(string description2);
    string setRiddleAnswer(string answer);

    string setDescription(string description);
    int setPathType(int pathType);
    int setAdvisor(int advisor);
    int setPridePoints(int pridePoints);
};

#endif
