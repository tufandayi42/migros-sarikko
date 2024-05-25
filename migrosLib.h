#ifndef MIGROSLIB_H
#define MIGROSLIB_H

#include <iostream>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <filesystem>
#include <conio.h>

using namespace std;

void wait(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

void clear() {
    system("cls");
}

string lowerCase(string string) {
    for (char& c: string) { c = std::tolower(c); }
    return string;
}


int mainSystem() {
    clear();
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


    while(true) {

        if(lowerCase(keyword) == "isos") {cout << "isos veri caliyor migros better"; return 0;}
        if(lowerCase(keyword) == "dorukay") {cout << "DORUKAYA KIVI YEDIRT"; return 0;}

        cout << computerName << "/> ";
        string command;

        cin >> command;
        command == lowerCase(command);

        if(command == "exit") { //exit

            cout << "Goodbye!" << endl;
            return 0;

        } else if (command == "settings") {

            cout << "Here is the list of commands you can run in the settings:" << endl;
            cout << "   'purge data': Deletes your data file." << endl;

        } else if (command == "purge-data") {

            filesystem::remove("data.sarikko");
            cout << "Deleted your data file.";
            cout << "\n";
            return 0;

        }
    }

    return 0;
}


int setupSystem() {
    clear();

    ifstream dataFileRead("data.sarikko");

    if (dataFileRead.is_open()) {
        string line;

        while (dataFileRead >> line) {

            if(line == "setupComplete") {
                clear();
                dataFileRead.close();
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

    clear();

    cout << "Press a key. You will use this key while navigating UP in menus." << endl;
    char upKey = getch();
    clear();

    cout << "Press a key. You will use this key while navigating DOWN in menus." << endl;
    char downKey = getch();
    clear();

    cout << "Press a key. You will use this key to confirm something (you will use this key instead of enter)" << endl;
    char enterKey = getch();
    clear();

    cout << "Add a custom keyword to your system? This might affect your experience. If you don't want to add something, you can just ignore this." << endl;
    string keyword;
    cin >> keyword;
    clear();

    cout << "What would you like to name this computer?" << endl;
    string computerName;
    cin >> computerName;

    clear();

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
    clear();
    cout << "Setup is complete! Please restart your system." << endl;
    wait(3);
    return 0;
}

#endif
