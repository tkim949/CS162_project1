/****************************************************************************************************
 * * Program name: CS162 Project1
 * * Author: Taekyoung Kim
 * * Date: 01/10/2019
 * * Description: This is AntStep.h head file of AntStep.cpp file for CS162 project1.
 ***************************************************************************************************/


#ifndef PROJECT1_1_ANTSTEP_H
#define PROJECT1_1_ANTSTEP_H

enum Direction {NORTH, SOUTH, EAST, WEST};

enum BColor {BLACK, WHITE, B_ANT, W_ANT};

class AntStep {

private:
    char **arr;
    int rowAnt;
    int colAnt;
    int numOfSteps;
    int sizeOfBoardRow;
    int sizeOfBoardCol;
    Direction direct;
    BColor color;

public:
    //antStep()=default;
    AntStep(char **arr, int row, int col, int numOfS, int sizeOfR, int sizeOfC, Direction di, BColor bCo);
    ~AntStep();
    Direction getDirection();
    void setDirection(Direction di);
    BColor getBColor();
    void setBColor(BColor bCo);
    int getRowLocate();
    void setRowLocate(int row);
    int getColLocate();
    void setColLocate(int col);
    void antLocate();
};

#endif
