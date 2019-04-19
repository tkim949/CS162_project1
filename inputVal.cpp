/****************************************************************************************************
 * * Program name: CS162 Project1
 * * Author: Taekyoung Kim
 * * Date: 01/21/2019
 * * Description: This is inputVal.cpp file for CS162 Project1.
 * * This function check users' input validation, so if the input is not integer, keeps asking users
 * * to input the correct data.
 ******************************************************************************************************/

#include "inputVal.h"
#include <iostream>
#include <climits>

int inputVal(double input) {

    // Check type validation first using std::cin.fail()
	//Then check if the input is positive number
	//Then check if the input is integer or decimal

    if( std::cin.good() && input > 0 && (input - (int)input == 0)) {
           return (int)input;
        }

    else{
        do {
            
            std::cout << "Wrong input! You need to input proper value!" << std::endl;
            //Clear the previous residue or garbage data
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');

            std::cout << "Please try again. Input here: " << std::endl;
            std::cin >> input;
           
        } while(!(std::cin.good() && input > 0 && (input - (int)input == 0) ));
    }

    return (int)input;
}