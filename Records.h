#ifndef RECORDS_H
#define RECORDS_H

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <vector>
#include "Player.h"

using namespace std;

// cmp function to compare the wins


class Records { // Records
private:
  vector<Player *> p;
  int Pcount;

public:
  Records() { Pcount = 0; }
  void addPlayer(Player *);
  void deactivate(string);
  void delPlayer(string);
  void printLeaderboard();
  void printAll();
  void readBoard();
  void writeBoard();
};

#endif