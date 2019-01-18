/************************************************************************************************************
 * * Program name: CS162 Project1
 * * Author: Taekyoung Kim
 * * Date: 01/10/2019
 * * Description: This is main.cpp file for the CS 162 project1. This project shows Langton's Ant simulation.
 * * To do so, this project uses menu functions and AntStep class function.
 ************************************************************************************************************/

#include <iostream>
#include <random>
#include <climits>
#include <string>
#include "intValidCheck.h"
#include "AntStep.h"
#include "validCh.h"


//function positNumCheck checks if the input is positive number.
int positNumCheck(int input){

    if(input > 0) {
        return input;
    }

    else {
        do {
            //std::cout << "Input" << input << std::endl;
            std::cout << "Wrong input! You need to input positive integer!" << std::endl;

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');

            std::cout << "Please try again. Input here: " << std::endl;
            std::cin >> input;

        } while(input<=0);
    }
    return input;
}

//function inValidOneorTwo check if the input is 1 or 2.
int inValidOneOrTwo(int input) {

    if (input == 1 || input == 2) {
        return input;
    }

    else {
        do {
            std::cout << "Wrong input! You need to input 1 or 2!" <<std::endl;

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');

            std::cout << "Please try again. Input here: "<<std::endl;
            std::cin >> input;
        } while (input != 1 && input != 2);
    }
    return input;
}

//Function to show users menus for choosing to quit or start and get user's choice.
int chooseMenu1(){

    std::string option;
    int menu;

    std::cout<<"Welcome to Langton's Ant simulation. Choose your option."<<std::endl;
    std::cout<<"1. Start Langton's Ant simulation"<<std::endl;
    std::cout<<"2. Quit the simulation"<<std::endl;
    //std::cin>>choice;
    std::getline(std::cin, option);
    menu = validCh(option);

    //Call input validation functions.
    //choice = intValidCheck(choice);
   // choice = inValidOneOrTwo(choice);

    switch(menu){
        case 1:
            std::cout<<"You chose 1. Start the simulation. Let's start!"<<std::endl;
            break;
        case 2:
            std::cout<<"You chose 2. Quit the simulation. Good buy!"<<std::endl;
            break;
        default:
            std::cout<<"You didn't choose 1 or 2"<<std::endl;
    }

    return menu;
}

int main() {

    int choiceResult;
    int playAgain;

    //Call menu function to show users the menu and get user's choice
    choiceResult = chooseMenu1();

    if(choiceResult == 1) {
        int numOfStep=0, startRow, startCol, choiceForRanNum;
        int lengthCol=0, widthRow =0;
        std::string length, width, steps, choice, userRow, userCol;

        do {

            //Ask user to input Board's Length and Width and call input validation function for two inputs.
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Please choose a board size, input positive integer number for length: "<< std::endl;
            std::getline(std::cin, length);
            lengthCol = validCh(length);

             //std::cin >> lengthCol;
             //lengthCol = intValidCheck(lengthCol);
             //lengthCol = positNumCheck(lengthCol);

            std::cout << "Please input positive integer number for width: "<< std::endl;
            std::getline(std::cin, width);
            widthRow = validCh(width);
            //std::cin >> widthRow;
            //widthRow = intValidCheck(widthRow);
            //widthRow = positNumCheck(widthRow);

            //Ask user to input the number of steps of ant and call input validation function.
            std::cout << "How many steps do you want the ant goes? Please input positive integer number for steps: "<< std::endl;
             std::getline(std::cin, steps);
             numOfStep = validCh(steps);
            // std::cin >> numOfStep;
            // numOfStep = intValidCheck(numOfStep);
            // numOfStep = positNumCheck(numOfStep);

            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
            std::cout << "Do you want to choose a starting point for the ant or make it start at a random location?"<<
                      "\nIf you want a random location, input number 1. Or, if you want to choose it by yourself input 2.: "
                      << std::endl;
            std::getline(std::cin, choice);
            choiceForRanNum =validCh(choice);
           // std::cin >> choiceForRanNum;
            //valid check for random choice
            //choiceForRanNum = intValidCheck(choiceForRanNum);
            //one or check for random choice
            choiceForRanNum = inValidOneOrTwo(choiceForRanNum);

            if (choiceForRanNum == 1) {

                std::random_device ran;
                std::mt19937 mt(ran());
                std::uniform_int_distribution <int> dist(0, widthRow-1);
                startRow = dist(mt);

                std::uniform_int_distribution <int> dist2(0, lengthCol-1);
                startCol = dist2(mt);
            }

            else { // choiceForRanNum == 2

                //Ask user to input the start point and then call the input validation function.
                std::cout << "Please choose the start point, input starting Row: " << std::endl;
                std::getline(std::cin, userRow);
                //std::cin >> startRow;
                startRow = validCh(userRow)-1;
                //startRow = intValidCheck(startRow);

                std::cout << "Input starting Column here: " << std::endl;
                //std::cin >> startCol;
                std::getline(std::cin, userCol);
                startCol =validCh(userCol)-1;
               //startCol = intValidCheck(startCol);

                if (!((startRow < widthRow) && (startCol < lengthCol))){

                    while (!((startRow < widthRow) && (startCol < lengthCol))) {
                        std::cout << "Wrong input! You need to input between the board size" << std::endl;

                        //std::cin.clear();
                        //std::cin.ignore(INT_MAX, '\n');

                        std::cout << "Please try again. Input start Row: " << std::endl;
                        //std::cin >> startRow;
                        //startRow = intValidCheck(startRow);
                        std::getline(std::cin, userRow);
                        startRow = validCh(userRow)-1;

                        std::cout <<"Start Column number here: "<<std::endl;
                        //std::cin >> startCol;
                        //startCol = intValidCheck(startCol);
                        std::getline(std::cin, userCol);
                        startCol =validCh(userCol)-1;
                    }
                }
            }
            //set array
            char **array = new char *[widthRow];

            //Initialize the pointer
            for (int i = 0; i < widthRow; i++) {
                array[i] = new char[widthRow];
            }

            for (int row = 0; row < widthRow; row++) {
                for (int col = 0; col < lengthCol; col++) {
                    array[row][col] = ' ';
                }
            }
            std::cout<<"start location: ["<<startRow<<" : "<<startCol<<"]\n";
            std::cout<<"Total number of Steps: "<<numOfStep<<"\n";
            std::cout<<"The board size is Width(row): "<<widthRow<<" , Length(column): "<<lengthCol<<"\n";
            std::cout<<std::endl;

            //To call the AntStep class function
            AntStep antS(array, startRow, startCol, numOfStep, widthRow, lengthCol, EAST, WHITE);

            antS.antLocate();

            //Clear the array
            for (int i = 0; i < widthRow; i++) {

                delete[] array[i];
            }
            delete[] array;

            std::cout<< "Do you want to play again?\nIf you want to play, input number 1. Otherwise, click any key!"<< std::endl;
            std::cin >> playAgain;

        } while (playAgain==1);

        std::cout << "You want to quit. Good buy! See you again!" << std::endl;
    }
    return 0;
}
