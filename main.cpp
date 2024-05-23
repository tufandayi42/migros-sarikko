#include "migrosLib.h"


int main() {

    system("clear");

    ifstream dataFileRead("data.sarikko");

    if (dataFileRead.is_open()) {
        string line;

        while (dataFileRead >> line) {
            if(line == "setupComplete") {
                
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

    cout << "Add a custom keyword to your system? This might affect your experience. If you don't want to add something, you can just ignore this." << endl;
    string keyword;
    cin >> keyword;

    system("clear");

    ofstream dataFile("data.sarikko");

    if (dataFile.is_open()) {
        dataFile << upKey << endl;
        dataFile << downKey << endl;
        dataFile << keyword << endl;
        dataFile << "setupComplete";
        dataFile.close();
    }


}