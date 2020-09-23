//
//  functions.cpp
//  testSFML
//
//  Created by Julio guzman on 9/22/20.
//

#include "functions.hpp"
#include <iostream>
#include <vector>
using namespace std;

void printGrid(vector<int> grid){
  for(int i = 0; i < 16; i++){
    cout << grid[i] << " ";
    if(i == 3 || i == 7 || i == 11 || i == 15){
      cout << endl;
    }
  }
}
vector<int> upLogic(vector<int> grid){
    vector<int> newGrid = grid;
    
    //Looping through each column to apply logic
    for(int i = 1; i <= 4; i ++){
        int columnNumber = i;
        int sumTwoTiles = 0;
        int endPosition = columnNumber +8;
        
        //Comparing vertical tiles 1 & 2
        //If the same assign sumTwoTiles value to tile 1 & shift others up
        if(newGrid[columnNumber-1] == newGrid[columnNumber+3]){
            sumTwoTiles = newGrid[columnNumber-1] + newGrid[columnNumber+3];
            newGrid[columnNumber-1] = sumTwoTiles;
            newGrid[columnNumber+3] = newGrid[columnNumber+7];
            newGrid[columnNumber+7] = newGrid[columnNumber+9];
            newGrid[columnNumber+11] = 0;
        }
       //Comparing vertical tiles 2 & 3
       //If the same assign sumTwoTiles value to tile 2 & shift others up
       if(newGrid[columnNumber+3] == newGrid[columnNumber+7]){
            sumTwoTiles = newGrid[columnNumber+3] + newGrid[columnNumber+7];
            newGrid[columnNumber+3] = sumTwoTiles;
            newGrid[columnNumber+7] = newGrid[columnNumber+11];
            newGrid[columnNumber+11] = 0;
        }
       //Comparing vertical tiles 3 & 4
       //If the same assign sumTwoTiles value to tile 3 & shift others up
       if(newGrid[columnNumber+7] == newGrid[columnNumber+11]){
            sumTwoTiles = newGrid[columnNumber+7] + newGrid[columnNumber+11];
            newGrid[columnNumber+7] = sumTwoTiles;
            newGrid[columnNumber+11] = 0;
           
        }
        //Moving positions up if a zero
        while(columnNumber!=endPosition){
            //Checking if current position zero if yes move the below up
            if(newGrid[columnNumber -1] == 0){
                newGrid[columnNumber-1] = newGrid[columnNumber+3];
                newGrid[columnNumber+3] = newGrid[columnNumber+7];
                newGrid[columnNumber+7] = newGrid[columnNumber+11];
                columnNumber -=4;
            }
            columnNumber +=4;
        }
    }
    return newGrid;
}
