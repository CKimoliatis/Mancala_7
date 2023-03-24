#ifndef PLAYER_H
#define PLAYER_H

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Player {
private:
  string name;
  int win;
  int loss;
  bool active;

public:
  Player();
  Player(string);
  Player(string, int, int);
  //Setters
  void setName(string n) { name = n; }
  void setWin(int w) { win = w; }
  void setLoss(int l) { loss = l; }
  void swapActive() { active = !active; }
  //Getters
  string getName() { return name; }
  int getWin() { return win; }
  int getLoss() { return loss; }
  bool getActive();
  //Print Functions
  void print();
  void adminPrint();
};

#endif