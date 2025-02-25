#include "Common.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int SEASONS = 4;

void readFile(const string &filename);
void readFileLine(const string &filename, int index);
void readFileBundle(const string &filename, int index);
int countLines(const string &filename);
void menu();

int main() {
    string villagerNames = "villagers.txt";
    string season = "seasons.txt";
    string foraging_bundle = "foraging_bundle.txt";
    int totalLines = countLines(villagerNames);
    char command;
    menu();
    command = readChar("Write a command");

    while (command != 'Q') {
        switch (command) {
        case 'A':
            readFile(villagerNames);
            break;
        case 'N':
            int nameIndex;
            nameIndex = readInt("Write index of the name: ", 1, totalLines);
            readFileLine(villagerNames, nameIndex);
            break;
        case 'S':
            readFile(season);
            break;
        case 'B':
            int seasonIndex;
            seasonIndex = readInt("What season do you want? (Spring/Summer/Fall/Winter)", 1, SEASONS);
            readFileBundle(foraging_bundle, seasonIndex);
            // print out each bundle to the right season
            break;
        default:
            menu();
            break;
        }
        command = readChar("Write a command: ");
    }

    return 0;
}

void readFileBundle(const string &filename, int index) {
    ifstream file(filename);
    string line;
    bool found = false;

    if (file.is_open()) {
        while (getline(file, line)) {
            // Check if the line is a number (section identifier)
            if (!line.empty() && isdigit(line[0])) {
                int section = stoi(line); // Convert string to integer

                if (section == index) {
                    found = true;
                    continue; // Skip printing the section number
                } else if (found) {
                    break; // Stop when the next section number is found
                }
            }

            if (found) {
                cout << line << '\n';
            }
        }
        file.close();

        if (!found) {
            cout << "Section " << index << " not found.\n";
        }
    } else {
        cout << "Unable to open file.\n";
    }
}

void readFile(const string &filename) {
    // Read from the file
    ifstream file(filename);
    string line;
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << '\n';
        }
        file.close();
    }

    else
        cout << "Unable to open file";
}

void readFileLine(const string &filename, int index) {
    ifstream file(filename);
    string line;
    if (file.is_open()) {
        int currentLine = 1;
        while (getline(file, line)) {
            if (currentLine == index) {
                cout << line << '\n';
            }
            currentLine++;
        }
        file.close();
    }

    else
        cout << "Unable to open file";
}

int countLines(const string &filename) {
    ifstream file(filename);
    string line;
    int lineCount = 0;

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
    cout << "This the menu choices \n"
         << "A: Read all the villager names\n"
         << "N: read a singular villager name\n"
         << "S: Read all the seasons\n"
         << "B: Read a season bundle of choice" << endl;
}