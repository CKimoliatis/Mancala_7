#include "Player.h"

Player:: Player() {
    name = "";
    win = 0;
    loss = 0;
    active = 0;
}

Player::Player(string n) {
    name = n;
    win = 0;
    loss = 0;
    active = 1;
}

Player::Player(string n, int w, int l) {
    name = n;
    win = w;
    loss = l;
    active = 1;
}

bool Player::getActive() {
    bool temp;
    active ? temp = 1 : temp = 0;
    return temp;
}

void Player::print() {
    cout << "Name: " << name << endl;
    cout << "Wins: " << win << endl;
    cout << "Loses: " << loss << endl;
}

void Player::adminPrint() {
    cout << "Name: " << name << endl;
    cout << "Wins: " << win << endl;
    cout << "Loses: " << loss << endl;
    cout << "Active: " << boolalpha << active << endl;
}