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
        int sumTwoTiles = 0;
        int endPosition = i-1; //top row are the ending vector positions
        int whileCount = 4;
        
        //Comparing vertical tiles 1st and 2nd
        if(newGrid[endPosition] == newGrid[endPosition+4]){
            
            //If they equal sumTwoTiles
            sumTwoTiles = newGrid[endPosition] + newGrid[endPosition+4];
            
            //Set sum value to tile
            newGrid[endPosition] = sumTwoTiles;
            
            //Shift below tiles up
            newGrid[endPosition+4] = newGrid[endPosition+8];
            newGrid[endPosition+8] = newGrid[endPosition+12];
            
            //Add zero to new last tile
            newGrid[endPosition+12] = 0;
        }
        //Comparing vertical tiles 2nd and 3rd
       if(newGrid[endPosition+4] == newGrid[endPosition+8]){
           
            //If they equal sumTwoTiles
            sumTwoTiles = newGrid[endPosition+4] + newGrid[endPosition+8];
           
            //Set sum value to tile
            newGrid[endPosition+4] = sumTwoTiles;
           
            //Shift below tile up
            newGrid[endPosition+8] = newGrid[endPosition+12];
           
            //Add zero to new last tile
            newGrid[endPosition+12] = 0;
        }
       //Comparing vertical tiles 3rd and last
       if(newGrid[endPosition+8] == newGrid[endPosition+12]){
           
           //If they equal sumTwoTiles
            sumTwoTiles = newGrid[endPosition+8] + newGrid[endPosition+12];
           
           //Set sum value to tile
            newGrid[endPosition+8] = sumTwoTiles;
           
            //Add zero to new last tile
            newGrid[endPosition+12] = 0;
           
        }
        
        //Moving positions up if a zero above them
        while(whileCount!=0){
            
            //Checking if current position zero if yes move below up
            if(newGrid[endPosition] == 0){
                newGrid[endPosition] = newGrid[endPosition+4];
                newGrid[endPosition+4] = newGrid[endPosition+8];
                newGrid[endPosition+8] = newGrid[endPosition+12];
                newGrid[endPosition+12] = 0;

                //Rechecking same position just in case a zero replaced the zero
                whileCount -=1;
            }
            else if(newGrid[endPosition+4] == 0){
                newGrid[endPosition+4] = newGrid[endPosition+8];
                newGrid[endPosition+8] = newGrid[endPosition+12];
                newGrid[endPosition+12] = 0;
                whileCount -=1;
            }
            else if(newGrid[endPosition+8] == 0){
                newGrid[endPosition+8] = newGrid[endPosition+12];
                newGrid[endPosition+12] = 0;
                whileCount -=1;
            }

            else{
                //Checking next position
                whileCount -=1;}
        }
    }
    return newGrid;
}

vector<int> rightLogic(vector<int> grid){
    vector<int> newGrid = grid;
    
    //Looping through each row to apply logic
    for(int i = 1; i <= 4; i ++){
        int rowNumber = i;
        int sumTwoTiles = 0;
        int endPosition = i*3+(i-1);
        int whileCount = 4;
        
        //Comparing horizontal tiles (right to left) 4th and 3rd
        if(newGrid[endPosition] == newGrid[endPosition-1]){
            
            //If they equal sumTwoTiles
            sumTwoTiles = newGrid[endPosition] + newGrid[endPosition-1];
            
            //Set sum value to tile
            newGrid[endPosition] = sumTwoTiles;
            
            //Shift left tiles to the right
            newGrid[endPosition-1] = newGrid[endPosition-2];
            newGrid[endPosition-2] = newGrid[endPosition-3];
            
            //Add zero to new last tile
            newGrid[endPosition-3] = 0;
        }
        
        //Comparing horizontal tiles(right to left) 3rd and 2nd
       if(newGrid[endPosition-1] == newGrid[endPosition-2]){
           
            //If they equal sumTwoTiles
            sumTwoTiles = newGrid[endPosition-1] + newGrid[endPosition-2];
           
            //Set sum value to tile
            newGrid[endPosition-1] = sumTwoTiles;
           
            //Shift left tile right
            newGrid[endPosition-2] = newGrid[endPosition-3];
           
            //Add zero to new last tile
            newGrid[endPosition-3] = 0;
        }
        
        //Comparing horizontal tiles (right to left) 2nd and 1st
       if(newGrid[endPosition-2] == newGrid[endPosition-3]){
           
           //If they equal sumTwoTiles
            sumTwoTiles = newGrid[endPosition-2] + newGrid[endPosition-3];
           
           //Set sum value to tile
            newGrid[endPosition-2] = sumTwoTiles;
           
            //Add zero to new last tile
            newGrid[endPosition-3] = 0;
           
        }
        
        //Moving positions to the right if a position to the right of them
        while(whileCount!=0){

            //Checking if current position zero if yes move to right
            if(newGrid[endPosition] == 0){
                newGrid[endPosition] = newGrid[endPosition-1];
                newGrid[endPosition-1] = newGrid[endPosition-2];
                newGrid[endPosition-2] = newGrid[endPosition-3];
                newGrid[endPosition-3] = 0;

                //Rechecking same position just in case a zero replaced the zero
                whileCount -=1;
            }
            else if(newGrid[endPosition-1] == 0){
                newGrid[endPosition-1] = newGrid[endPosition-2];
                newGrid[endPosition-2] = newGrid[endPosition-3];
                newGrid[endPosition-3] = 0;
                whileCount -=1;
            }
            else if(newGrid[endPosition-2] == 0){
                newGrid[endPosition-2] = newGrid[endPosition-3];
                newGrid[endPosition-3] = 0;
                whileCount -=1;
            }

            else{
                //Checking next position
                whileCount -=1;}
            
        }
    }
    return newGrid;
}
