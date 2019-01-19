/****************************************************************************************************
 * * Program name: CS162 Project1
 * * Author: Taekyoung Kim
 * * Date: 01/10/2019
 * * Description: This class function track ant's steps checking the board color and direction.
 * * Then, show the steps step by step with black with #, ant with *.
 ***************************************************************************************************/

#include "AntStep.h"
#include <iostream>

//constructor
AntStep::AntStep(char **a, int r, int c, int s, int sizeOfBR, int sizeOfBC, Direction di, BColor co){
    arr = a;
    rowAnt = r;
    colAnt = c;
    numOfSteps = s;
    sizeOfBoardRow = sizeOfBR;
    sizeOfBoardCol = sizeOfBC;
    direct = di;
    color =co;
}

//Destructor
AntStep::~AntStep() = default;
//Accessor
Direction AntStep::getDirection(){
    return direct;
}
//Modifier
void AntStep::setDirection(Direction dir){
    direct = dir;
}
//Accessor
BColor AntStep::getBColor(){
    return color;
}
//Modifier
void AntStep::setBColor(BColor co){
    color = co;
}
//Accessor
int AntStep::getRowLocate(){
    return rowAnt;
}
//Modifier
void AntStep::setRowLocate(int rowA){
    rowAnt = rowA;
}
//Accessor
int AntStep::getColLocate(){
    return colAnt;
}
//Modifier
void AntStep::setColLocate(int colA){
    colAnt = colA;
}

//Function
void AntStep::antLocate() {


    for (int i = 0; i < numOfSteps; i++) {

        int preRowSteps[numOfSteps-1];
        int preColSteps[numOfSteps-1];
        preRowSteps[i] = getRowLocate();
        preColSteps[i] = getColLocate();

        //Track the cell that ant stayed and return to the original color.
        if (i > 0) {
            if (getBColor() == W_ANT) {

               arr[preRowSteps[i-1]][preColSteps[i-1]] = ' ';
               setBColor(WHITE);
            }
            else if (getBColor() == B_ANT) {
               arr[preRowSteps[i-1]][preColSteps[i-1]] = '#';
               setBColor(BLACK);
            }
         }
        //Show the current step number, current location, and direction.
        std::cout<<std::endl;
        std::cout<<i+1<<": the Ant step number"<<std::endl;
        std::cout<<"Current Ant Direction: "<<getDirection()<<std::endl;
        std::cout <<"Current Ant location ["<<getRowLocate()<<" , " <<getColLocate()<<"]"<<std::endl;
        

        //When the cell color is white.
        if (arr[getRowLocate()][getColLocate()] == ' ') {
            arr[getRowLocate()][getColLocate()] = '*';

            std::cout << "The cell color is White." << std::endl;
			std::cout<<std::endl;
			 //Change the board color to black with ant so that we can track the cell.
            setBColor(B_ANT);
			
            //Go to East when the direction is north if the cell color is white.
            if (getDirection() == NORTH) {
                setDirection(EAST);
                if (getColLocate()  < sizeOfBoardCol-1) {
                    setColLocate(getColLocate() + 1);
                }
                else {
                    setColLocate(0);
                }
                std::cout <<"New Ant location when North ["<<getRowLocate()<<" , " <<getColLocate()<<"]"<<std::endl;
                std::cout<<"New Ant Direction when North: "<<getDirection()<<std::endl;
            }
            //Go to West when the direction is South if the cell color is white.
            else if (getDirection() == SOUTH) {
                setDirection(WEST);
                if (getColLocate() > 0) {
                    setColLocate(getColLocate() - 1);

                }
                else {
                    setColLocate(sizeOfBoardCol-1);
                }
                std::cout <<"New Ant location when South: ["<<getRowLocate()<<" , " <<getColLocate()<<"]"<<std::endl;
                std::cout<<"New Ant Direction When South: "<<getDirection()<<std::endl;
            }
            //Go to South when the direction is East if the cell color is white.
            else if (getDirection() == EAST) {
                setDirection(SOUTH);
                if (getRowLocate() < sizeOfBoardRow -1) {
                    setRowLocate(getRowLocate()+ 1);
                }
                else {
                    setRowLocate(0);
                }
                std::cout <<"New Ant location when East: ["<<getRowLocate()<<" , " <<getColLocate()<<"]"<<std::endl;
                std::cout<<"New Ant Direction when East: "<<getDirection()<<std::endl;
            }
            //Go to North when the direction is West if the cell color is white.
            else if(getDirection() == WEST) {
                setDirection(NORTH);
                if (getRowLocate() > 0) {
                    setRowLocate(getRowLocate() - 1);

                }
                else {
                    setRowLocate(sizeOfBoardRow-1);
                }
                std::cout <<"New Ant location when West: ["<<getRowLocate()<<" , " <<getColLocate()<<"]"<<std::endl;
                std::cout<<"New Ant Direction when West: "<<getDirection()<<std::endl;
            }
           

        }
        //When the cell color is black.
        else if (arr[getRowLocate()][getColLocate()]== '#') {
            arr[getRowLocate()][getColLocate()] = '*';
			
            std::cout << "The cell color is Black." << std::endl;
			std::cout<<std::endl;
			
			//Change the board color to white with ant so that we can track the cell.
            setBColor(W_ANT);

            //Go to West when the direction is North if the cell color is Black.
            if (getDirection() == NORTH) {
              setDirection(WEST);

                if (getColLocate() > 0) {
                    setColLocate(getColLocate() - 1);
                }
                else {
                    setColLocate(sizeOfBoardCol-1);
                }
                std::cout <<"New Ant location when North: ["<<getRowLocate()<<" , " <<getColLocate()<<"]"<<std::endl;
                std::cout<<"New Ant Direction when North: "<<getDirection()<<std::endl;
            }
            //Go to Eest when the direction is South if the cell color is Black.
            else if (getDirection() == SOUTH) {
                setDirection(EAST);

                if (getColLocate()  < sizeOfBoardCol -1) {
                   setColLocate(getColLocate() + 1);
                }
                else {
                   setColLocate(0);
                }
                std::cout <<"New Ant location when South: ["<<getRowLocate()<<" , " <<getColLocate()<<"]"<<std::endl;
                std::cout<<"New Ant Direction when South: "<<getDirection()<<std::endl;
            }
            //Go to North when the direction is East if the cell color is Black.
            else if (getDirection() == EAST) {
                setDirection(NORTH);

                if (getRowLocate() > 0) {
                    setRowLocate(getRowLocate()-1);
                }
                else {
                    setRowLocate(sizeOfBoardRow-1);
                }
                std::cout <<"New Ant location when East: ["<<getRowLocate()<<" , " <<getColLocate()<<"]"<<std::endl;
                std::cout<<"New Ant Direction when East: "<<getDirection()<<std::endl;
            }
            //Go to South when the direction is West if the cell color is Black.
            else if (getDirection() == WEST) {
                setDirection(SOUTH);

                if (getRowLocate() < sizeOfBoardRow -1) {
                    setRowLocate(getRowLocate() + 1);
                }
                else {
                     setRowLocate(0);
                }
                std::cout <<"New Ant location when West: ["<<getRowLocate()<<" , " <<getColLocate()<<"]"<<std::endl;
                std::cout<<"New Ant Direction when West: "<<getDirection()<<std::endl;
            }
            
         }

        std::cout<<"Below is the board to show the Ant steps: " <<std::endl;
        std::cout<<std::endl;
        for (int row =0; row <sizeOfBoardRow; row++) {
            for (int col=0; col <sizeOfBoardCol; col++) {
                std::cout<<arr[row][col]<<" ";
            }
            std::cout<<std::endl;
        }
    }
}
