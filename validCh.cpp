/****************************************************************************************************
* * Program name: CS162 Project1
* * Author: Taekyoung Kim
* * Date: 01/10/2019
* * Description: This is validCh.cpp file for CS162 project1.
* * This function check users' input validation using string stream.
* * So, if the input is not valid, it keeps asking users to input the correct data.
******************************************************************************************************/


#include "validCh.h"
#include <iostream>
#include <string>
#include <sstream>

int validCh(std::string info) {


    int num = 0;
    bool cond = true;

    while (true) {
        //std::cout << "Enter num: " << std::endl;
        //getline(std::cin, info);
        std::stringstream sstr(info);
        if (sstr >> num && num >0) {
            break;
        }

        //std::cin.clear();
        //std::cin.ignore(INT_MAX, '\n');
        std::cout << "Invalid input! please try again" << std::endl;
        getline(std::cin, info);


    }

    return num;
}
