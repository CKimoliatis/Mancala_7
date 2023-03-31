#include "AdminUser.h"

void gameLoop(Board &);
bool isAdmin(string, string);
void displayLeaderboard();
bool compare(UserInfo, UserInfo);

int main() {
    Board board;
    string username, password;

    //    Admin testadmin;
    //    testadmin.username = "piadmin";
    //    testadmin.password = "piadmin";
    //    fstream adminDB("AdminData.dat", ios::out | ios::binary);
    //    adminDB.seekp(ios::beg);
    //    adminDB.write(reinterpret_cast<char *> (&testadmin), sizeof (testadmin));
    //    adminDB.close();

    char login = ' ';
    cout << "Welcome to Mancala V99" << endl;
    do {
        char input;
        cout << "R) To Register For an Account \t L) To Log In to an Account" << endl;
        cin >> input;
        login = input;
    } while (login != 'R' && login != 'L');

    if (login == 'R') {
        cout << "Set Username : ";
        cin >> username;
        cout << "Set Password : ";
        cin >> password;
    } else if (login == 'L') {
        cout << "Username : ";
        cin >> username;
        cout << "Password : ";
        cin >> password;
    }

    if (isAdmin(username, password)) {
        cout << "Admin" << endl;
        AdminUser test;
    } else {
        User user;
        user.setUser(username, password);
        displayLeaderboard();
    }
}

bool isAdmin(string username, string password) {
    fstream adminDB("AdminData.dat", ios::in | ios::app | ios::binary);
    Admin temp;

    adminDB.seekg(ios::beg);
    while (adminDB.read(reinterpret_cast<char *> (&temp), sizeof (temp))) {
        if (temp.username == username && temp.password != password) {
            string password;
            do {
                cout << "Incorrect Password Try Again : ";
                cin>>password;
            } while (password != temp.password);
            return 1;
        } else if (temp.username == username && temp.password == password) {
            return 1;
        }
    }
    adminDB.close();

    return 0;
}

void displayLeaderboard() {
    fstream userDB("UserData.dat", ios::in | ios::app | ios::binary);
    UserInfo temp;
    vector<UserInfo> leaderboard;
    
    userDB.seekg(ios::beg);
    while (userDB.read(reinterpret_cast<char *> (&temp), sizeof (temp))) {
        leaderboard.push_back(temp);
    }
    sort(leaderboard.begin(), leaderboard.end(), compare(left, right));
    
    cout << endl << "Username \t Highscore" << endl;
    for(UserInfo user : leaderboard){
        cout<<user.username<<" \t "<<user.highScore<<endl;
    }
    
    userDB.close();
}

bool compare(UserInfo left, UserInfo right){
    left.highScore < right.highScore;
}

void gameLoop(Board &board) {
    int playerTurn = 1;
    while (!board.gameOver()) { //Game ends when either side as 0 marbles in all pits
        if (playerTurn == 1) {
            int play, marbles;
            board.printBoard();
            cout << "Player 1's Turn. Enter a number 1 - 6 (L to R)" << endl;
            cin>>play;

            int currCell = play + 1;
            board.playerOneMove(currCell, play, marbles);
            currCell--; //Back off one to check if capture or go again

            board.checkOneMove(currCell, playerTurn);
        } else {
            int play, marbles;
            board.printBoard();
            cout << "Player 2's Turn. Enter a number 1 - 6 (L to R)" << endl;
            cin>>play;

            play = 14 - play;
            int currCell = play + 1;
            board.playerTwoMove(currCell, play, marbles);
            currCell--;

            board.checkTwoMove(currCell, playerTurn);
        }
    }
}