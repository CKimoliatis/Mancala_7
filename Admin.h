#ifndef ADMIN_H
#define ADMIN_H

#include "Mancala7.h"

class Admin {
private:
    vector<UserInfo> userInfo;
    vector<PlayerData> playerData;
public:
    void readUserInfo();
    void printUserInfo();
    void readPlayerData();
    void printPlayerData();
};
#endif /* ADMIN_H */

