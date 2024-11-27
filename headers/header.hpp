#ifndef HEADER_HPP
#define HEADER_HPP

#include<iostream>
#include <string>
#include<cstdlib>
#include<sstream>
#include<map>
#include "errors.hpp"

std::map<std::string, int> intVars;
std::map<std::string, float> floatVars;
std::map<std::string, char> chrVars;
std::map<std::string, std::string> strVars;

// Checking Source File
void checkSourceFile(std::string sourceFile){
	std::string fileName;
	std::string fileExt;
	size_t dotPosition = sourceFile.find('.');
    if (dotPosition != std::string::npos) {
        fileName = sourceFile.substr(0, dotPosition);
        fileExt = sourceFile.substr(dotPosition + 1);
    }

	if(fileExt != "fx"){
		std::cout<<"Incorrect file encoding"<<std::endl;
		exit(1);
		
	}
}

// Function to remove space before a line

std::string removeSpace(std::string value) {
    // Remove leading spaces and tabs
    size_t start = value.find_first_not_of(" \t");
    if (start != std::string::npos) {
        value = value.substr(start);
    } else {
        // If the string is all spaces/tabs, return an empty string
        return "";
    }

    // Remove trailing spaces and tabs
    size_t end = value.find_last_not_of(" \t");
    if (end != std::string::npos) {
        value = value.substr(0, end + 1);
    }

    return value;
}


// Function definitions
void print(std::string argument) {
    argument = removeSpace(argument);

    std::cout << argument << std::endl;
}

void add(std::string ar1, std::string ar2) {
    int num1 = atoi(ar1.c_str());
    int num2 = atoi(ar2.c_str());
    std::cout << (num1 + num2) << std::endl;
}

void subtract(std::string ar1, std::string ar2) {
    int num1 = atoi(ar1.c_str());
    int num2 = atoi(ar2.c_str());
    std::cout << (num1 - num2) << std::endl;
}

void multiply(std::string ar1, std::string ar2) {
    int num1 = atoi(ar1.c_str());
    int num2 = atoi(ar2.c_str());
    std::cout << (num1 * num2) << std::endl;
}

void division(std::string ar1, std::string ar2) {
    int num1 = atoi(ar1.c_str());
    int num2 = atoi(ar2.c_str());
    if (num2 != 0) {
        std::cout << (num1 / num2) << std::endl;
    } else {
        std::cout << "Division by zero error!" << std::endl;
    }
}

// Function to declare a variable
void declareVariable(std::string varName, std::string varType, std::string varValue){
	if (varType == "int") {
        intVars[varName] = std::stoi(varValue.c_str());  // Assign the integer value
    } else if (varType == "float") {
        floatVars[varName] = std::stof(varValue.c_str());  // Assign the float value
    } else if (varType == "str") {
        strVars[varName] = varValue;  // Assign the string value
    } else if (varType == "chr") {
        chrVars[varName] = varValue[0];  // Assign the character value (first char)
    } else {
        std::cout << "Unknown variable type: " << varType << std::endl;
    }
}

// Function to print a variable
void printVariable(std::string varName) {
    // Check if the variable exists and print its value
    if (intVars.find(varName) != intVars.end()) {
        std::cout << intVars[varName] << std::endl;
    } else if (floatVars.find(varName) != floatVars.end()) {
        std::cout << floatVars[varName] << std::endl;
    } else if (strVars.find(varName) != strVars.end()) {
        std::cout << strVars[varName] << std::endl;
    } else if (chrVars.find(varName) != chrVars.end()) {
        std::cout << chrVars[varName] << std::endl;
    } else {
        missingVariable(varName);
    }
}

// Function to declare a function
void func(std::string ar_main, std::string ar1, std::string ar2) {
    if (ar_main == "+") {
        add(ar1, ar2);
    }
    if (ar_main == "-") {
        subtract(ar1, ar2);
    }
    if (ar_main == "*") {
        multiply(ar1, ar2);
    }
    if (ar_main == "/") {
        division(ar1, ar2);
    }
}

// Function for conditional operator
void conditionalOperation(std::string ar1, std::string ar_op, std::string ar2) {
    int a = atoi(ar1.c_str());
    int b = atoi(ar2.c_str());

    bool result = false;

    if (ar_op == "==") {
        result = (a == b);
    } else if (ar_op == "!=") {
        result = (a != b);
    } else if (ar_op == "<") {
        result = (a < b);
    } else if (ar_op == ">") {
        result = (a > b);
    } else if (ar_op == "<=") {
        result = (a <= b);
    } else if (ar_op == ">=") {
        result = (a >= b);
    } else {
        std::cout << "Unknown operator: " << ar_op << std::endl;
        return;
    }

    std::cout << (result ? "true" : "false") << std::endl;
}

// Function for a loop
void loop(std::string ar1, std::string ar_op, std::string ar2){
	int index = std::atoi(ar1.c_str());
	int final_index = std::atoi(ar2.c_str());

	if(ar_op == "to"){
		for(int i = index; i <= final_index; i++){
			std::cout<<i<<" ";
		}
	}
}

// Function to create array
void makeArray(std::string arrayName, int n, int *arr){
    int* newArr = new int[n];

    for(int i = 0; i < n; i++){
        newArr[i] = arr[i];
    }

    for(int j = 0; j < n; j++){
        std::cout<<newArr[j]<<std::endl;
    }

    delete[] newArr; // Delete the array after the program is executed

}

#endif // HEADER_HPP
