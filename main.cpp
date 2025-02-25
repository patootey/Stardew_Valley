#include "Common.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void readAllNames(const string &filename);
void readSingularName(const string &filename, int index);
int countLines(const string &filename);
void menu();

int main() {
    string filename = "names.txt";
    int totalLines = countLines(filename);
    char command;
    menu();
    command = readChar("Write a command");

    while (command != 'Q') {
        switch (command) {
        case 'A':
            readAllNames(filename);
            break;

        case 'S':
            int nameIndex;
            nameIndex = readInt("Write index of the name: ", 1, totalLines);
            readSingularName(filename, nameIndex);
            break;
        default:
            menu();
            break;
        }
        command = readChar("Write a command: ");
    }

    return 0;
}

void readAllNames(const string &filename) {
    // Read from the file
    string nameText;
    ifstream namefile(filename);
    if (namefile.is_open()) {
        while (getline(namefile, nameText)) {
            cout << "Name: " << nameText << '\n';
        }
        namefile.close();
    }

    else
        cout << "Unable to open file";
}

void readSingularName(const string &filename, int index) {
    string nameText;
    ifstream namefile(filename);
    if (namefile.is_open()) {
        int currentLine = 1;
        while (getline(namefile, nameText)) {
            if (currentLine == index) {
                cout << nameText << '\n';
            }
            currentLine++;
        }
        namefile.close();
    }

    else
        cout << "Unable to open file";
}

int countLines(const string &filename) {
    ifstream file(filename);
    int lineCount = 0;
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            lineCount++;
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }

    return lineCount;
}

void menu() {
    cout << "This the menu choices: " << "A: Read all the villager names"
         << "S: read a singular villager name" << endl;
}