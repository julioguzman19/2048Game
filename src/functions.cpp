//
//  functions.cpp
//  testSFML
//
//  Created by Julio Guzman & Colin Mitchell on 9/22/20.
//

#include "functions.hpp"
#include <iostream>
#include <vector>
using namespace std;

Grid::Grid(){
    numbers = {0,0,6,6,0,0,3,3,3,3,0,0,3,14,15,16};
      //vertical lines
    for(int i = 1; i < 4; i++){
        sf::RectangleShape line(sf::Vector2f(1.f, 800.f));
        line.setPosition(200.f * i, 100.f);
        lines.push_back(line);
    }
    
    //horizontal lines
    for(int i = 0; i < 4; i++){
        sf::RectangleShape line(sf::Vector2f(800.f, 1.f));
        line.setPosition(0.f, (i*200.f + 100.f));
    }
    
    //tiles row 1
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            sf::RectangleShape tile(sf::Vector2f(180.f, 180.f));
            tile.setPosition((10.f + j*200.f), (110.f + i*200.f));
            tiles.push_back(tile);
        }
    }
    
    color0 = sf::Color(255, 255, 255);
    color2 = sf::Color(238, 232, 170);
    color4 =sf::Color(255,255,0);
    color8 =sf::Color(0,255,0);
    color16 =sf::Color(34,139,34);
    color32 =sf::Color(0,100,0);
    color64 =sf::Color(0,191,255);
    color128 =sf::Color(65,105,225);
    color256 =sf::Color(0,0,255);
    color512 =sf::Color(125,125,125);
    color1024 =sf::Color(74,74,74);
    color2048 =sf::Color(0,0,0);
}


void Grid::drawGrid(sf::RenderWindow window){
    
} //Use numbers and tiles and draw color in window

void Grid::addRandomTile(){
    
}


void Grid::printGrid(vector<int> grid){
  for(int i = 0; i < 16; i++){
    cout << grid[i] << " ";
    if(i == 3 || i == 7 || i == 11 || i == 15){
      cout << endl;
    }
  }
}

vector<int> Grid::upLogic(vector<int> grid){
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

vector<int> downLogic(vector<int> grid){
    vector<int> newGrid = grid;
    
    //Looping through each column to apply logic
    for(int i = 1; i <= 4; i ++){
        int sumTwoTiles = 0;
        int endPosition = i+11; //top row are the ending vector positions
        int whileCount = 4;
        
        //Comparing vertical tiles starting from bottom
        if(newGrid[endPosition] == newGrid[endPosition-4]){
            
            //If they equal sumTwoTiles
            sumTwoTiles = newGrid[endPosition] + newGrid[endPosition-4];
            
            //Set sum value to tile
            newGrid[endPosition] = sumTwoTiles;
            
            //Shift above tiles down
            newGrid[endPosition-4] = newGrid[endPosition-8];
            newGrid[endPosition-8] = newGrid[endPosition-12];
            
            //Add zero to new tile
            newGrid[endPosition-12] = 0;
        }
        //Comparing vertical tiles 2nd and 3rd
       if(newGrid[endPosition-4] == newGrid[endPosition-8]){
           
            //If they equal sumTwoTiles
            sumTwoTiles = newGrid[endPosition-4] + newGrid[endPosition-8];
           
            //Set sum value to tile
            newGrid[endPosition-4] = sumTwoTiles;
           
            //Shift below tile up
            newGrid[endPosition-8] = newGrid[endPosition+12];
           
            //Add zero to new tile
            newGrid[endPosition-12] = 0;
        }
       //Comparing vertical tiles 3rd and last
       if(newGrid[endPosition-8] == newGrid[endPosition-12]){
           
           //If they equal sumTwoTiles
            sumTwoTiles = newGrid[endPosition-8] + newGrid[endPosition-12];
           
           //Set sum value to tile
            newGrid[endPosition-8] = sumTwoTiles;
           
            //Add zero to new tile
            newGrid[endPosition-12] = 0;
           
        }
        
        //Moving positions up if a zero above them
        while(whileCount!=0){
            
            //Checking if current position zero if yes move below up
            if(newGrid[endPosition] == 0){
                newGrid[endPosition] = newGrid[endPosition-4];
                newGrid[endPosition-4] = newGrid[endPosition-8];
                newGrid[endPosition-8] = newGrid[endPosition-12];
                newGrid[endPosition-12] = 0;

                //Rechecking same position just in case a zero replaced the zero
                whileCount -=1;
            }
            else if(newGrid[endPosition-4] == 0){
                newGrid[endPosition-4] = newGrid[endPosition-8];
                newGrid[endPosition-8] = newGrid[endPosition-12];
                newGrid[endPosition-12] = 0;
                whileCount -=1;
            }
            else if(newGrid[endPosition-8] == 0){
                newGrid[endPosition-8] = newGrid[endPosition-12];
                newGrid[endPosition-12] = 0;
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

vector<int> leftLogic(vector<int> grid){
    vector<int> newGrid = grid;
    
    //Looping through each row to apply logic
    for(int i = 1; i <= 4; i ++){
        int rowNumber = i;
        int sumTwoTiles = 0;
        int endPosition = i*4 - 4;
        int whileCount = 4;
        
        //Comparing horizontal tiles (right to left) 4th and 3rd
        if(newGrid[endPosition] == newGrid[endPosition+1]){
            
            //If they equal sumTwoTiles
            sumTwoTiles = newGrid[endPosition] + newGrid[endPosition+1];
            
            //Set sum value to tile
            newGrid[endPosition] = sumTwoTiles;
            
            //Shift left tiles to the right
            newGrid[endPosition+1] = newGrid[endPosition+2];
            newGrid[endPosition+2] = newGrid[endPosition+3];
            
            //Add zero to new last tile
            newGrid[endPosition+3] = 0;
        }
        
        //Comparing horizontal tiles(right to left) 3rd and 2nd
       if(newGrid[endPosition+1] == newGrid[endPosition+2]){
           
            //If they equal sumTwoTiles
            sumTwoTiles = newGrid[endPosition+1] + newGrid[endPosition+2];
           
            //Set sum value to tile
            newGrid[endPosition+1] = sumTwoTiles;
           
            //Shift left tile right
            newGrid[endPosition+2] = newGrid[endPosition+3];
           
            //Add zero to new last tile
            newGrid[endPosition+3] = 0;
        }
        
        //Comparing horizontal tiles (right to left) 2nd and 1st
       if(newGrid[endPosition+2] == newGrid[endPosition+3]){
           
           //If they equal sumTwoTiles
            sumTwoTiles = newGrid[endPosition+2] + newGrid[endPosition+3];
           
           //Set sum value to tile
            newGrid[endPosition+2] = sumTwoTiles;
           
            //Add zero to new last tile
            newGrid[endPosition+3] = 0;
           
        }
        
        //Moving positions to the right if a position to the right of them
        while(whileCount!=0){

            //Checking if current position zero if yes move to right
            if(newGrid[endPosition] == 0){
                newGrid[endPosition] = newGrid[endPosition+1];
                newGrid[endPosition+1] = newGrid[endPosition+2];
                newGrid[endPosition+2] = newGrid[endPosition+3];
                newGrid[endPosition+3] = 0;

                //Rechecking same position just in case a zero replaced the zero
                whileCount -=1;
            }
            else if(newGrid[endPosition+1] == 0){
                newGrid[endPosition+1] = newGrid[endPosition+2];
                newGrid[endPosition+2] = newGrid[endPosition+3];
                newGrid[endPosition+3] = 0;
                whileCount -=1;
            }
            else if(newGrid[endPosition+2] == 0){
                newGrid[endPosition+2] = newGrid[endPosition+3];
                newGrid[endPosition+3] = 0;
                whileCount -=1;
            }

            else{
                //Checking next position
                whileCount -=1;}
            
        }
    }
    return newGrid;
}
