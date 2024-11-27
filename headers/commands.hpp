#ifndef COMMANDS_HPP
#define COMMANDS_HPP

#include "header.hpp"
#include <iostream>
#include <string>
#include<cstdlib>
#include<fstream>
#include<sstream>
#include"errors.hpp"

void checkCommands(std::ifstream& sourceFile){
    // Reading the file line by line
    std::string line;
    std::string firstline, lastline; 
    
    getline(sourceFile, firstline); // Retrieving the first line of the program

    if(firstline == "start()"){ // checking if the file has an initiator function
        while (getline(sourceFile, line)) {
        std::stringstream ss(line);
        std::string command;

        // Extracting the command (first word of the line)
        ss >> command;

        // Process based on the command
        if (command == "pr") {
            std::string argument;
            std::getline(ss, argument);  // Get the rest of the line as argument
            if(argument.length() != 0){
                print(argument);
            }
            else{
                missingParameters();
            }
        } else if (command == "+") {
            std::string ar1, ar2;
            ss >> ar1 >> ar2;
            if(ar1.length() != 0 && ar2.length() != 0){ // checking if argument is null or not
                add(ar1, ar2);
            }else{
                missingParameters();
            }
        } else if (command == "-") {
            std::string ar1, ar2;
            ss >> ar1 >> ar2;
            if(ar1.length() != 0 && ar2.length() != 0){ // checking if argument is null or not
                subtract(ar1, ar2);
            }else{
                missingParameters();
            }
        } else if (command == "*") {
            std::string ar1, ar2;
            ss >> ar1 >> ar2;
            if(ar1.length() != 0 && ar2.length() != 0){ // checking if argument is null or not
                multiply(ar1, ar2);
            }else{
                missingParameters();
            }
        } else if (command == "/") {
            std::string ar1, ar2;
            ss >> ar1 >> ar2;
            if(ar1.length() != 0 && ar2.length() != 0){ // checking if argument is null or not
                division(ar1, ar2);
            }else{
                missingParameters();
            }
        } else if (command == "int") {
            std::string varName, value;
            ss >> varName >> value;  // Declare an int variable with value
            declareVariable(varName, "int", value);
        } else if (command == "float") {
            std::string varName, value;
            ss >> varName >> value;  // Declare a float variable with value
            declareVariable(varName, "float", value);
        } else if (command == "str") {
            std::string varName, value;
            ss >> varName;
            std::getline(ss, value);  // Get the rest of the line as std::string value
            

            declareVariable(varName, "str", value);
        } else if (command == "chr") {
            std::string varName, value;
            ss >> varName >> value;  // Declare a char variable with value
            value = removeSpace(value);
            declareVariable(varName, "chr", value);
        }
        else if (command == "_pr") {
            std::string varName;
            ss >> varName;
            printVariable(varName);  // Print variable value
        }
        // adding the function command
        else if (command == "func") {
            // ar_main = command, ar1 and ar2 are values/arguments
            std::string ar_main, ar1, ar2;
            ss >> ar_main >> ar1 >> ar2;
            func(ar_main, ar1, ar2);
        } else if (command == "if") {
            // ar_op = operation, ar1 and ar2 are arguments
            std::string ar1, ar_op, ar2;
            ss >> ar1 >> ar_op >> ar2;
            conditionalOperation(ar1, ar_op, ar2);
        } 
        else if(command == "loop"){
            std::string ar1, ar_op, ar2;
            ss >> ar1 >> ar_op >> ar2;
            loop(ar1, ar_op, ar2);
        }
        else if(command == "arr"){
            std::string ar, eq, el; // intializing the array name, equal sign and elements
            int n; // size of the array
            int arr[n];
            ss >> ar >> n >> eq;

            for(int i = 0; i < n; i++){
                ss >> el; // retrieving the array elements
                arr[i] = atoi(el.c_str()); // putting the elements in the array
            }

            if(ar.length() != 0){
                makeArray(ar, n, arr); // passing the array name, size and array
            }
            else{
                missingParameters();
            }
        }

        else if(command == "" || command == " " || command == "//"){} // Ignores blank lines and comments 
        else {
            std::cout << "Invalid command";
        }
    }
    }
    else{
        std::cout<<"There is no initiator function"<<std::endl;
        exit(1);
    }
}

#endif // COMMANDS_HPP