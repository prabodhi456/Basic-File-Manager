#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

void listFiles(const string& path) {
    ifstream dir(path.c_str());
    if (!dir) {
        cerr << "Error: Unable to open directory." << endl;
        return;
    }
    string item;
    while (getline(dir, item)) {
        cout << item << endl;
    }
    dir.close();
}

/*void createDirectory(const string& path) {
    if (mkdir(path.c_str()) == 0)
        cout << "Directory created successfully." << endl;
    else
        cerr << "Error: Unable to create directory." << endl;
}*/

void copyFile(const string& source, const string& destination) {
    ifstream sourceFile(source.c_str(), ios::binary);
    ofstream destFile(destination.c_str(), ios::binary);
    destFile << sourceFile.rdbuf();
    sourceFile.close();
    destFile.close();
    cout << "File copied successfully." << endl;
}

void moveFile(const string& source, const string& destination) {
    if (rename(source.c_str(), destination.c_str()) == 0)
        cout << "File moved successfully." << endl;
    else
        cerr << "Error: Unable to move file." << endl;
}

void viewFile(const string& filename) {
    ifstream file(filename.c_str());
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Error: Unable to open file." << endl;
    }
}

int main() {
    string command;
    string path = "."; // Start from the current directory

    while (true) {
        cout << "Current directory: " << path << endl;
        cout << "Enter command (list, create, copy, move, view, exit): ";
        cin >> command;

        if (command == "list") {
            listFiles(path);
        } else if (command == "create") {
            string dirname;
            cout << "Enter directory name: ";
            cin >> dirname;
            //createDirectory(path + "/" + dirname);
        } else if (command == "copy") {
            string source, destination;
            cout << "Enter source file path: ";
            cin >> source;
            cout << "Enter destination file path: ";
            cin >> destination;
            copyFile(source, destination);
        } else if (command == "move") {
            string source, destination;
            cout << "Enter source file path: ";
            cin >> source;
            cout << "Enter destination file path: ";
            cin >> destination;
            moveFile(source, destination);
        } else if (command == "view") {
            string filename;
            cout << "Enter file name: ";
            cin >> filename;
            viewFile(path + "/" + filename);
        } else if (command == "exit") {
            break;
        } else {
            cerr << "Invalid command. Please try again." << endl;
        }
    }


    return 0;
}
