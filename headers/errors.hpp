#ifndef ERRORS_HPP
#define ERRORS_HPP

#include "header.hpp"
#include <iostream>
#include <string>
#include<cstdlib>
#include<fstream>
#include<sstream>

// Function to display error whenever a required parameter is missing for a command
void missingParameters(){
    std::cout<<"Error: Missing parameters for the command"<<std::endl;
    exit(1);
}

void missingVariable(std::string varName){
    std::cout<<"Runtime Error: Null reference exception. Variable "<<varName<<" is not initialized."<<std::endl;
    exit(1);
}

#endif // ERRORS_HPP