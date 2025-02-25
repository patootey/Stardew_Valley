#include "Common.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void readAllNames();
void menu();

int main() {

    char command;
    menu();
    command = lesChar("Write a command");

    while (command != 'Q') {
        switch (command) {
        case 'A':
            readAllNames();
            break;

        case 'S':
            // read a singular name
            break;
        default:
            menu();
            break;
        }
        command = lesChar("Write a command: ");
    }

    return 0;
}

void readAllNames() {
    // Read from the file
    string nameText;
    ifstream namefile("names.txt");
    if (namefile.is_open()) {
        while (getline(namefile, nameText)) {
            cout << nameText << '\n';
        }
        namefile.close();
    }

    else
        cout << "Unable to open file";
}

void menu() {
    cout << "This the menu choices: " << "A: Read all the villager names"
         << "S: read a singular villager name" << endl;
}