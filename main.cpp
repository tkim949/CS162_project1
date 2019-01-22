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
#include "inputVal.h"


//Function to show users menus for choosing to quit or start and get user's choice.
int chooseMenu(){

    double option;
    int menu;

    std::cout<<"Welcome to Langton's Ant simulation. Choose your option."<<std::endl;
    std::cout<<"1. Start Langton's Ant simulation"<<std::endl;
    std::cout<<"2. Quit the simulation"<<std::endl;
	std::cout<<"If you input nothing and click enter key, it will wait until you finally input something and click enter key."<<std::endl;
	std::cout<<"Please input your choice here: ";
    std::cin>>option;
    menu = inputVal(option);
  
    /**********************************************************************************************************
	* * This if statement check if the user's input is 1 or 2.
	* * In fact, when we use 'switch statement,' this might not seem necessary because the 'default' 
	* * makes the process stop when users input something other than the cases(1 or 2) in the switch statement.
	* * However, The instruction requires the program asks users to input correct data until they do, I added it.
	************************************************************************************************************/
	
    if (!(menu == 1 || menu == 2)){
		
		 do {
            std::cout << "Wrong input! You need to input 1 or 2! Input here: ";
			 /***********************************************************************************************************
		     * * I added below two lines where user input something, in the case the program didn't wait for user input. 
			 * * They clear the residue or unnecessary data on the program. Otherwise, the program might have an error.
		     *************************************************************************************************************/
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cin>> option;
            menu = inputVal(option);
			   
        } while (!(menu == 1 || menu == 2));
	}

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
    
    return menu;
}

int main() {

    int choiceResult;
    int playAgain;

    //Call menu function to show users the menu and get user's choice
    choiceResult = chooseMenu();
	
	std::cout<<std::endl;

    if(choiceResult == 1) {
        int lengthCol, widthRow, numOfStep, choiceForRanNum, startRow, startCol;
        double length, width, steps, choice, userRow, userCol;

        do {
             /***********************************************************************************************************
		     * * I added below two lines where user input something, in the case the program didn't wait for user input. 
			 * * They clear the residue or unnecessary data on the program. Otherwise, the program might have an error.
		     *************************************************************************************************************/
            std::cin.clear();
            std::cin.ignore(INT_MAX, '\n');
						
			//Ask user to input Board's Length and Width and call input validation function for two inputs.
            std::cout <<"Please choose a board size, please input 150 or less positive numbers, "<<std::endl;
            std::cout<<"First number for length here(for column): ";
            std::cin>> length;
            lengthCol = inputVal(length);

            if (lengthCol > 150){

                while (lengthCol > 150) {
					std::cin.clear();
			        std::cin.ignore(INT_MAX, '\n');
                    std::cout <<"Wrong input! Please try again. please input 150 or less for length: ";
                    std::cin >> length;
                    lengthCol = inputVal(length);
                }
            }

            std::cout <<"Next input Width, 120 or less number (for row): ";
            std::cin>> width;
            widthRow = inputVal(width);

            if (widthRow > 150){

                while (widthRow > 150) {
					std::cin.clear();
			        std::cin.ignore(INT_MAX, '\n');
                    std::cout <<"Wrong input! Please try again. please input 150 or less for width: ";
                    std::cin>> width;
                    widthRow = inputVal(width);
                }
            }

            //Ask user to input the number of steps of ant and call input validation function.
            std::cout <<"How many steps do you want the ant goes?\n";
			std::cout<<"Please input positive integer number 18000 or less: ";
            std::cin>> steps;
            numOfStep = inputVal(steps);

            if (numOfStep > 18000){

                while (numOfStep > 18000) {
					std::cin.clear();
			        std::cin.ignore(INT_MAX, '\n');
                    std::cout <<"Wrong input! Input up to 18000!"<< std::endl;
                    std::cout <<"Please try again. Input number for ant step 18000 or less: ";
                    std::cin>> steps;
                    numOfStep = inputVal(steps);
                }
            }
            //Ask user if they want random location or want to choose it by themselves.
            std::cout <<"Do you want to choose a starting point for the ant or make it start at a random location?\n";
            std::cout<<"If you want a random location, input number 1 Or,\n";
			std::cout<<"if you want to choose it by yourself input 2: ";
            std::cin>>choice;
            choiceForRanNum = inputVal(choice);
            
			//Ask user to input only 1 or 2.
			 if (!(choiceForRanNum == 1 || choiceForRanNum == 2)){
		
		        do {
					std::cin.clear();
			        std::cin.ignore(INT_MAX, '\n');
					std::cout << "Wrong input! You need to input 1 or 2! Input here: ";
					std::cin>> choice;
					choiceForRanNum = inputVal(choice);
            
				} while(!(choiceForRanNum == 1 || choiceForRanNum == 2));
			}
            //Get the random numbers for the starting points.
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

                //Ask user to input the start point and then call the input validation function.
                std::cout <<"Please choose start row and column points within the board size!"<<std::endl;
				std::cout<<"Input your Row number that is "<<widthRow<<" or less: ";
                std::cin>> userRow;
                startRow = inputVal(userRow)-1;

                if (startRow > widthRow-1){

                    while (startRow >  widthRow-1) {
						std::cin.clear();
			            std::cin.ignore(INT_MAX, '\n');
                        std::cout <<"Wrong input! Please try again. please input number that is "<<widthRow<<" or less: ";
                        std::cin>> userRow;
                        startRow = inputVal(userRow)-1;
                    }
                }
                //Get the starting column number.
                std::cout <<"Now, input your starting Column number that is "<<lengthCol<<" or less: ";
                std::cin>> userCol;
                startCol = inputVal(userCol)-1;

                if (startCol > lengthCol-1){

                    while (startCol > lengthCol-1) {
						std::cin.clear();
			            std::cin.ignore(INT_MAX, '\n');
                        std::cout <<"Wrong input! Please try again. please input number that is "<<lengthCol<<" or less: ";
                        std::cin>> userCol;
                        startCol = inputVal(userCol)-1;
                    }
                }
				std::cout<<"Your choice for the start points in the board: ["<<startRow<<" : "<<startCol<<"]"<<std::endl;
				std::cout<<"Now start the simulation!"<<std::endl;
			}
			
            //set array
            char **array = new char *[widthRow];

            //Initialize the pointer.
            for (int i = 0; i < widthRow; i++) {
                array[i] = new char[widthRow];
            }
            //Set the board cell color to the White.
            for (int row = 0; row < widthRow; row++) {
                for (int col = 0; col < lengthCol; col++) {
                    array[row][col] = ' ';
                }
            }

            //To call the AntStep class function
            AntStep antS(array, startRow, startCol, numOfStep, widthRow, lengthCol, EAST, WHITE);

            antS.antLocate();
			
			std::cout<<"The starting location in the board was: ["<<startRow<<" : "<<startCol<<"]"<<std::endl;
			std::cout<<"The starting points in the board shows one less than your choice because of the board number system."<<std::endl;
			std::cout<<"The board size was Length(Column): "<<lengthCol<<" and Width(Row): "<<widthRow<<std::endl;
			std::cout<<"The ant moved "<<numOfStep<<" steps"<<std::endl;
			std::cout<<std::endl;
			
            std::cout<<"Do you want to play again?\nIf you want to play, input number 1. Otherwise, click any key here: ";
			std::cin>> playAgain;
			std::cout<<std::endl;
			
			 //Clear the array
            for (int i = 0; i < widthRow; i++) {
                delete[] array[i];
            }
            delete[] array;
			
        } while (playAgain==1);

        std::cout <<"You want to quit. Good buy! See you again!" << std::endl;
    }
    return 0;
}
