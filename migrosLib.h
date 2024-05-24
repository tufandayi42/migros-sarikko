#ifndef MIGROSLIB_H
#define MIGROSLIB_H

#include <iostream>
#include <unistd.h>
#include <termios.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

void wait(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

char getch() {
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if (read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    return buf;
}


int mainSystem() {
    system("clear");
    ifstream file("data.sarikko");

    string line;
    vector<string> lines;

    while (getline(file, line)) {
        lines.push_back(line);
    }

    string upKey = lines[0];
    string downKey = lines[1];
    string enterKey = lines[2];
    string keyword = lines[3];
    string computerName = lines[4];

    file.close();


    cout << "Migros Ticaret A.S MigrOS Sarikko" << "\n" << endl;
    cout << computerName << "/>" << endl;

    return 0;
}


int setupSystem() {
    system("clear");

    ifstream dataFileRead("data.sarikko");

    if (dataFileRead.is_open()) {
        string line;

        while (dataFileRead >> line) {

            if(line == "setupComplete") {
                system("clear");
                mainSystem();
                return 0;
            }
        }
    
        dataFileRead.close();
    }

    cout << "Welcome to MigrOS Sarikko setup! Would you like to continue? [y/n]" << endl;
    string yesno;
    cin >> yesno;
    if(yesno=="n" or yesno=="N") {cout << "Goodbye!" << endl; return 0;}
    if(yesno!="y" and yesno!="Y") {cout << "\n Incorrect answer." << endl; return 0;}

    system("clear");

    cout << "Press a key. You will use this key while navigating UP in menus." << endl;
    char upKey = getch();
    system("clear");

    cout << "Press a key. You will use this key while navigating DOWN in menus." << endl;
    char downKey = getch();
    system("clear");

    cout << "Press a key. You will use this key to confirm something (you will use this key instead of enter)" << endl;
    char enterKey = getch();
    system("clear");

    cout << "Add a custom keyword to your system? This might affect your experience. If you don't want to add something, you can just ignore this." << endl;
    string keyword;
    cin >> keyword;
    system("clear");

    cout << "What would you like to name this computer?" << endl;
    string computerName;
    cin >> computerName;

    system("clear");

    ofstream dataFile("data.sarikko");

    if (dataFile.is_open()) {
        dataFile << upKey << endl;
        dataFile << downKey << endl;
        dataFile << enterKey << endl;
        dataFile << keyword << endl;
        dataFile << computerName << endl;
        dataFile << "setupComplete";
        dataFile.close();
    }

    cout << "Saving your options." << endl;
    wait(2);
    system("clear");
    cout << "Setup is complete! Please restart your system." << endl;
    wait(3);
    return 0;
}

#endif