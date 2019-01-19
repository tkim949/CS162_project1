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
#include "AntStep.h"
#include "validCh.h"

//function inValidOneorTwo check if the input is 1 or 2.
int inValidOneOrTwo(int input) {

    if (input == 1 || input == 2) {
        return input;
    }

    else {
        do {
            std::cout << "Wrong input! You need to input 1 or 2!" <<std::endl;
			/************************************************************************************
			**I added below two lines when program didn't wait for user input. It worked well.
			** However, sometimes, it rather made input delayed or needed a enter key twice.
			** So, I deleted them, but if it doesn't wait for user's input, it might be needed.
            **std::cin.clear();
            **std::cin.ignore(INT_MAX, '\n');
			************************************************************************************/ 
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
    menu = inValidOneOrTwo(menu);

    switch(menu){
        case 1:
            std::cout<<"You chose 1. Start the simulation. Let's choose your board!"<<std::endl;
            break;
        case 2:
            std::cout<<"You chose 2. Quit the simulation. Good buy!"<<std::endl;
            break;
        default:
            std::cout<<"You didn't choose 1 or 2"<<std::endl;
    }
    std::cout<<std::endl;
    return menu;
}

int main() {

    int choiceResult;
    int playAgain;
	std::string playA;

    //Call menu function to show users the menu and get user's choice
    choiceResult = chooseMenu1();

    if(choiceResult == 1) {
        int lengthCol, widthRow, numOfStep, choiceForRanNum, startRow, startCol;
        std::string length, width, steps, choice, userRow, userCol;

        do {
            std::cout<<"If it is needed, you might hit enter key again while inputting data"<<std::endl;
            /*****************************************************************************************************
			* * I put below two lines here because these two line can clear garbage input data.
			* * However, two many line clears might cause key board delay.
            * * Two set of clear lines are okay, but if users make always correct inputs or there is little
			* * invalid input, it also might cause key board delay or have user click enter key again.
			*******************************************************************************************************/
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');

			//Ask user to input Board's Length and Width and call input validation function for two inputs.
            std::cout <<"Please choose a board size, please input 200 or less positive numbers, "<<std::endl;
            std::cout<<"First number for length here(for column): ";
            std::getline(std::cin, length);
            lengthCol = validCh(length);

            if (lengthCol >200){

                while (lengthCol > 200) {
                    std::cout <<"Wrong input! Please try again. please input 200 or less for length: "<< std::endl;
                    std::getline(std::cin, length);
                    lengthCol = validCh(length);
                }
            }

            std::cout <<"Next input Width, 200 or less number (for row): ";
            std::getline(std::cin, width);
            widthRow = validCh(width);

            if (widthRow >200){

                while (widthRow > 200) {
                    std::cout <<"Wrong input! Please try again. please input 200 or less for width: "<< std::endl;
                    std::getline(std::cin, width);
                    widthRow = validCh(width);
                }
            }


            //Ask user to input the number of steps of ant and call input validation function.
            std::cout <<"How many steps do you want the ant goes? Please input positive integer number 25000 or less: "<< std::endl;
            std::getline(std::cin, steps);
            numOfStep = validCh(steps);

            if (numOfStep > 25000){

                while (numOfStep > 25000) {
                    std::cout <<"Wrong input! Input up to 25000!"<< std::endl;
                    std::cout <<"Please try again. Input number for ant step 25000 or less: " << std::endl;
                    std::getline(std::cin, steps);
                    numOfStep = validCh(steps);
                }
            }
           
            std::cout <<"Do you want to choose a starting point for the ant or make it start at a random location?\n";
            std::cout<<"If you want a random location, input number 1 Or,\n";
			std::cout<<"if you want to choose it by yourself input 2 "<<std::endl;
            std::getline(std::cin, choice);
            choiceForRanNum =validCh(choice);
            choiceForRanNum = inValidOneOrTwo(choiceForRanNum);

            if (choiceForRanNum == 1) {

                std::random_device ran;
                std::mt19937 mt(ran());
                std::uniform_int_distribution <int> dist(0, widthRow-1);
                startRow = dist(mt);

                std::uniform_int_distribution <int> dist2(0, lengthCol-1);
                startCol = dist2(mt);
				
				std::cout<<"The random location for you is: ["<<startRow<<" : "<<startCol<<"]"<<std::endl;
				std::cout<<"Now start the simulation!"<<std::endl;
				
            }

            else { // choiceForRanNum == 2
                //The second line clear set
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');

                //Ask user to input the start point and then call the input validation function.
                std::cout <<"Please choose start row and column points within the board size!"<<std::endl;
				std::cout<<"Input your Row number that is "<<widthRow<<" or less:\n";
                std::getline(std::cin, userRow);
                startRow = validCh(userRow)-1;

                if (startRow > widthRow-1){

                    while (startRow >  widthRow-1) {
                        std::cout <<"Wrong input! Please try again. please input number that is "<<widthRow<<" or less"<<std::endl;
                        std::getline(std::cin, userRow);
                        startRow = validCh(userRow)-1;
                    }
                }
               
                std::cout <<"Now, Input starting Column that is "<<lengthCol<<" or less:\n ";
                std::getline(std::cin, userCol);
                startCol =validCh(userCol)-1;

                if (startCol > lengthCol-1){

                    while (startCol > lengthCol-1) {
                        std::cout <<"Wrong input! Please try again. please input number that is "<<lengthCol<<" or less"<<std::endl;
                        std::getline(std::cin, userCol);
                        startCol =validCh(userCol)-1;
                    }
                }
				std::cout<<"Your choice for the start points: ["<<startRow<<" : "<<startCol<<"]"<<std::endl;
				std::cout<<"Now start the simulation!"<<std::endl;
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

            //To call the AntStep class function
            AntStep antS(array, startRow, startCol, numOfStep, widthRow, lengthCol, EAST, WHITE);

            antS.antLocate();

            //Clear the array
            for (int i = 0; i < widthRow; i++) {

                delete[] array[i];
            }
            delete[] array;

            std::cout<<"Do you want to play again?\nIf you want to play, input number 1. Otherwise, click any key!"<< std::endl;
			std::cin>>playAgain;
			
        } while (playAgain==1);

        std::cout << "You want to quit. Good buy! See you again!" << std::endl;
    }
    return 0;
}
