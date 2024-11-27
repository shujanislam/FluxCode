#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>  // to split each line
#include <map>
#include "headers/header.hpp"
#include "headers/commands.hpp"

using namespace std;

// Main function
int main(int argc, char* argv[]) {
    // Checking if command line argument is valid or not
    if (argc < 2) {
        cout << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    // Reading the source file
    ifstream sourceFile(argv[1]);
    if (!sourceFile) {
        cout << "Error opening file: " << argv[1] << endl;
        return 1;
    }
    // Function to check if the source file has .lx extension
    checkSourceFile(argv[1]);

    checkCommands(sourceFile);

    // Closing the source file
    sourceFile.close();
    return 0;
}
