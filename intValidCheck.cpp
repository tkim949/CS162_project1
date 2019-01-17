/****************************************************************************************************
 * * Program name: CS162 Project1
 * * Author: Taekyoung Kim
 * * Date: 01/10/2019
 * * Description: This is intValidCheck.cpp file for CS162 project1.
 * * This function check users' input validation, so if the input is not integer, keeps asking users
 * * to input the correct input.
 ******************************************************************************************************/

#include "intValidCheck.h"
#include <iostream>

int intValidCheck(int input) {

    // Check type validation first using std::cin.fail()

    if(std::cin.fail()) {

        do {
            //std::cout << "Input" << input << std::endl;
            std::cout << "Wrong input! You need to input proper value!" << std::endl;

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');

            std::cout << "Please try again. Input here: " << std::endl;
            std::cin >> input;

        } while(std::cin.fail());
    }
    else {
        return input;
    }
    return input;
}