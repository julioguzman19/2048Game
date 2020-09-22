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
vector<int> upLogic(vector<int> grid, int columnNumber){
  int tempC = 0;
  vector<int> newGrid = grid;
  if(newGrid[columnNumber-1] == newGrid[columnNumber+3]){
    tempC = newGrid[columnNumber-1] + newGrid[columnNumber+3];
    newGrid[columnNumber-1] = tempC;
    newGrid[columnNumber+3] = newGrid[columnNumber+7];
    newGrid[columnNumber+7] = newGrid[columnNumber+9];
    newGrid[columnNumber+11] = 0;
    return newGrid;
  }
  else if(newGrid[columnNumber+3] == newGrid[columnNumber+7]){
    tempC = newGrid[columnNumber+3] + newGrid[columnNumber+7];
    newGrid[columnNumber+3] = tempC;
    newGrid[columnNumber+7] = newGrid[columnNumber+11];
    newGrid[columnNumber+11] = 0;
    return newGrid;
  }
  else if(newGrid[columnNumber+7] == newGrid[columnNumber+11]){
    tempC = newGrid[columnNumber+7] + newGrid[columnNumber+11];
    newGrid[columnNumber+7] = tempC;
    newGrid[columnNumber+11] = 0;
    return newGrid;
  }
  else{
    return newGrid;
  }
}
