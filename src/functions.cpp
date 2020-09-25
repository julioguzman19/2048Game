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
    //just some numbers for testing, in the final product we will have full of zeros, and then have a random tile = 2
    numbers = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    // vector to use in randomTileGenerator method
    randomTileValue = {2, 2, 2, 4};
    
    addRandomTile();
    addRandomTile();
    
    score = 0;
    
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
        lines.push_back(line);
    }
    
    //tiles
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            sf::RectangleShape tile(sf::Vector2f(180.f, 180.f));
            tile.setPosition((10.f + j*200.f), (110.f + i*200.f));
            tiles.push_back(tile);
        }
    }
    
    //set colors for different numbers
    color0 = sf::Color(255, 255, 255);
    color2 = sf::Color(238, 232, 170);
    color4 =sf::Color(255,255,0);
    color8 =sf::Color(0,255,0);
    color16 =sf::Color(34,139,34);
    color32 =sf::Color(0,255,255);
    color64 =sf::Color(0,191,255);
    color128 =sf::Color(65,105,225);
    color256 =sf::Color(0,0,255);
    color512 =sf::Color(125,125,125);
    color1024 =sf::Color(74,74,74);
    color2048 =sf::Color(0,0,0);
    
    font.loadFromFile("../ArialBlack.ttf");
    font2.loadFromFile("../Helvetica.ttc");
}

//Use numbers and tiles and draw color in window
void Grid::drawGrid(sf::RenderWindow& window){
    
    window.clear(sf::Color::Black);
    
    sf::Text instructions;
    instructions.setFont(font2);
    instructions.setString("Add the numbers to get to 2048!\nUse arrow keys to shift tiles.\nRestart: press SPACE.    Exit: press ESC.");
    instructions.setCharacterSize(25.f);
    instructions.setFillColor(sf::Color(245, 245, 245));
    instructions.setStyle(sf::Text::Regular);
    instructions.setPosition(10.f, 10.f);
    
    window.draw(instructions);
    
    
    sf::Text scoreText;
    scoreText.setFont(font2);
    scoreText.setString("SCORE: " + to_string(score));
    scoreText.setCharacterSize(30.f);
    scoreText.setFillColor(sf::Color(255, 105, 180));
    scoreText.setPosition(575.f, 25.f);
    
    window.draw(scoreText);
    
    //draw lines
    for(int i = 0; i < 7; i++){
        window.draw(lines[i]);
    }
    //draw tiles
    for(int i = 0; i < 16; i++){
        switch (numbers[i]){
                
            case 0:
                tiles[i].setFillColor(color0);
                break;
                
            case 2:
                tiles[i].setFillColor(color2);
                break;

            case 4:
                tiles[i].setFillColor(color4);
                break;

            case 8:
                tiles[i].setFillColor(color8);
                break;

            case 16:
                tiles[i].setFillColor(color16);
                break;

            case 32:
                tiles[i].setFillColor(color32);
                break;

            case 64:
                tiles[i].setFillColor(color64);
                break;

            case 128:
                tiles[i].setFillColor(color128);
                break;

            case 256:
                tiles[i].setFillColor(color256);
                break;

            case 512:
                tiles[i].setFillColor(color512);
                break;

            case 1024:
                tiles[i].setFillColor(color1024);
                break;

            case 2048:
                tiles[i].setFillColor(color2048);
                break;

        }
        window.draw(tiles[i]);
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            
            sf::Text text;
            text.setFont(font);
            text.setString(to_string(numbers[(i*4) + j]));
            text.setCharacterSize(50.f);
            text.setFillColor(sf::Color::Black);
            text.setStyle(sf::Text::Bold);
           
            text.setPosition((20.f + j*200.f), (110.f + i*200.f));
            
            if(numbers[(i*4) + j] != 0){
                window.draw(text);
            }
        }
    }
}

//after an action is taken (key is pressed and tiles shifted accordingly) replace one of the 0 tiles with a 2 (or possibly 4)
void Grid::addRandomTile(){
    vector<int> zeroLocation;
    for(int i = 0; i < 16; i++){
        if(numbers[i] == 0){
            zeroLocation.push_back(i);
        }
    }
    int randomIndex = zeroLocation[rand() % zeroLocation.size()];
    numbers[randomIndex] = randomTileValue[rand() % 4];
}

void Grid::upLogic(){
    
    bool hasChanged = false;
    //Looping through each column to apply logic
    for(int i = 1; i <= 4; i ++){
        int sumTwoTiles = 0;
        int endPosition = i-1; //top row are the ending vector positions
        int whileCount = 4;

  
        //Moving positions up if a zero above them
            while(whileCount!=0){
                
                //Checking if current position zero if yes move below up
                if(numbers[endPosition] == 0){
                    if(numbers[endPosition+4] != 0 || numbers[endPosition+8] != 0 ||numbers[endPosition+12] != 0){
                        hasChanged = true;
                        numbers[endPosition] = numbers[endPosition+4];
                        numbers[endPosition+4] = numbers[endPosition+8];
                        numbers[endPosition+8] = numbers[endPosition+12];
                        numbers[endPosition+12] = 0;
                    }
                    
                    //Rechecking same position just in case a zero replaced the zero
                    whileCount -=1;
                }
                else if(numbers[endPosition+4] == 0){
                    if(numbers[endPosition+8] != 0 ||numbers[endPosition+12] != 0){
                        hasChanged = true;
                        numbers[endPosition+4] = numbers[endPosition+8];
                        numbers[endPosition+8] = numbers[endPosition+12];
                        numbers[endPosition+12] = 0;
                    }
                    whileCount -=1;
                }
                else if(numbers[endPosition+8] == 0){
                    if(numbers[endPosition+12] != 0){
                        hasChanged = true;
                        numbers[endPosition+8] = numbers[endPosition+12];
                        numbers[endPosition+12] = 0;
                    }
                    whileCount -=1;
                }

                else{
                    //Checking next position
                    whileCount -=1;}
            }
    
    
        
        //Comparing vertical tiles 1st and 2nd
        if(numbers[endPosition] == numbers[endPosition+4] &&numbers[endPosition]!=0 ){
            hasChanged = true;
            //If they equal sumTwoTiles
            sumTwoTiles = numbers[endPosition] + numbers[endPosition+4];
            
            //Set sum value to tile
            numbers[endPosition] = sumTwoTiles;
            
            //Shift below tiles up
            numbers[endPosition+4] = numbers[endPosition+8];
            numbers[endPosition+8] = numbers[endPosition+12];
            
            //Add zero to new last tile
            numbers[endPosition+12] = 0;
            //track score
            score += sumTwoTiles;
        }
        //Comparing vertical tiles 2nd and 3rd
       if(numbers[endPosition+4] == numbers[endPosition+8] && numbers[endPosition+4]!=0 ){
            hasChanged = true;
            //If they equal sumTwoTiles
            sumTwoTiles = numbers[endPosition+4] + numbers[endPosition+8];
           
            //Set sum value to tile
            numbers[endPosition+4] = sumTwoTiles;
           
            //Shift below tile up
            numbers[endPosition+8] = numbers[endPosition+12];
           
            //Add zero to new last tile
            numbers[endPosition+12] = 0;
           //track score
           score += sumTwoTiles;
        }
       //Comparing vertical tiles 3rd and last
       if(numbers[endPosition+8] == numbers[endPosition+12] && numbers[endPosition+8]!=0 ){
            hasChanged = true;

           //If they equal sumTwoTiles
            sumTwoTiles = numbers[endPosition+8] + numbers[endPosition+12];
           
           //Set sum value to tile
            numbers[endPosition+8] = sumTwoTiles;
           
            //Add zero to new last tile
            numbers[endPosition+12] = 0;
           //track score
           score += sumTwoTiles;
        }
        
    //Moving positions up if a zero above them
        while(whileCount!=0){
            
            //Checking if current position zero if yes move below up
            if(numbers[endPosition] == 0){
                if(numbers[endPosition+4] != 0 || numbers[endPosition+8] != 0 ||numbers[endPosition+12] != 0){
                    hasChanged = true;
                    numbers[endPosition] = numbers[endPosition+4];
                    numbers[endPosition+4] = numbers[endPosition+8];
                    numbers[endPosition+8] = numbers[endPosition+12];
                    numbers[endPosition+12] = 0;
                }
                
                //Rechecking same position just in case a zero replaced the zero
                whileCount -=1;
            }
            else if(numbers[endPosition+4] == 0){
                if(numbers[endPosition+8] != 0 ||numbers[endPosition+12] != 0){
                    hasChanged = true;
                    numbers[endPosition+4] = numbers[endPosition+8];
                    numbers[endPosition+8] = numbers[endPosition+12];
                    numbers[endPosition+12] = 0;
                }
                whileCount -=1;
            }
            else if(numbers[endPosition+8] == 0){
                if(numbers[endPosition+12] != 0){
                    hasChanged = true;
                    numbers[endPosition+8] = numbers[endPosition+12];
                    numbers[endPosition+12] = 0;
                }
                whileCount -=1;
            }

            else{
                //Checking next position
                whileCount -=1;}
        }
    }
    if(hasChanged){
        addRandomTile();
    }
}

void Grid::downLogic(){
    bool hasChanged = false;

    //Looping through each column to apply logic
    for(int i = 1; i <= 4; i ++){
        int sumTwoTiles = 0;
        int endPosition = i+11; //top row are the ending vector positions
        int whileCount = 4;
        
        
        //Moving positions up if a zero above them
        while(whileCount!=0){
            //Checking if current position zero if yes move down
            if(numbers[endPosition] == 0){
                if(numbers[endPosition-4] != 0 || numbers[endPosition-8] != 0 ||numbers[endPosition-12] != 0 ){
                    hasChanged = true;
                    numbers[endPosition] = numbers[endPosition-4];
                    numbers[endPosition-4] = numbers[endPosition-8];
                    numbers[endPosition-8] = numbers[endPosition-12];
                    numbers[endPosition-12] = 0;
                }
            
                //Rechecking same position just in case a zero replaced the zero
                whileCount -=1;
            }
            else if(numbers[endPosition-4] == 0){
                if(numbers[endPosition-8] != 0 ||numbers[endPosition-12] != 0 ){
                    hasChanged = true;
                    numbers[endPosition-4] = numbers[endPosition-8];
                    numbers[endPosition-8] = numbers[endPosition-12];
                    numbers[endPosition-12] = 0;
                }
                whileCount -=1;
            }
            else if(numbers[endPosition-8] == 0){
                if(numbers[endPosition-12] != 0 ){
                hasChanged = true;
                numbers[endPosition-8] = numbers[endPosition-12];
                numbers[endPosition-12] = 0;
                }
                whileCount -=1;
            }

            else{
                //Checking next position
                whileCount -=1;}
        }
        
        
        //Comparing vertical tiles starting from bottom
        if(numbers[endPosition] == numbers[endPosition-4] &&numbers[endPosition]!=0){
            hasChanged = true;
            //If they equal sumTwoTiles
            sumTwoTiles = numbers[endPosition] + numbers[endPosition-4];
            
            //Set sum value to tile
            numbers[endPosition] = sumTwoTiles;
            
            //Shift above tiles down
            numbers[endPosition-4] = numbers[endPosition-8];
            numbers[endPosition-8] = numbers[endPosition-12];
            
            //Add zero to new tile
            numbers[endPosition-12] = 0;
            //track score
            score += sumTwoTiles;
        }
        //Comparing vertical tiles 2nd and 3rd
       if(numbers[endPosition-4] == numbers[endPosition-8] &&numbers[endPosition-4]!=0){
           hasChanged = true;
            //If they equal sumTwoTiles
            sumTwoTiles = numbers[endPosition-4] + numbers[endPosition-8];
           
            //Set sum value to tile
            numbers[endPosition-4] = sumTwoTiles;
           
            //Shift below tile up
            numbers[endPosition-8] = numbers[endPosition-12];
           
            //Add zero to new tile
            numbers[endPosition-12] = 0;
           //track score
           score += sumTwoTiles;
        }
       //Comparing vertical tiles 3rd and last
       if(numbers[endPosition-8] == numbers[endPosition-12] &&numbers[endPosition-8]!=0){
           hasChanged = true;
           //If they equal sumTwoTiles
            sumTwoTiles = numbers[endPosition-8] + numbers[endPosition-12];
           
           //Set sum value to tile
            numbers[endPosition-8] = sumTwoTiles;
           
            //Add zero to new tile
            numbers[endPosition-12] = 0;
           //track score
           score += sumTwoTiles;
        }
        
        //Moving positions up if a zero above them
        while(whileCount!=0){
            //Checking if current position zero if yes move down
            if(numbers[endPosition] == 0){
                if(numbers[endPosition-4] != 0 || numbers[endPosition-8] != 0 ||numbers[endPosition-12] != 0 ){
                    hasChanged = true;
                    numbers[endPosition] = numbers[endPosition-4];
                    numbers[endPosition-4] = numbers[endPosition-8];
                    numbers[endPosition-8] = numbers[endPosition-12];
                    numbers[endPosition-12] = 0;
                }
            
                //Rechecking same position just in case a zero replaced the zero
                whileCount -=1;
            }
            else if(numbers[endPosition-4] == 0){
                if(numbers[endPosition-8] != 0 ||numbers[endPosition-12] != 0 ){
                    hasChanged = true;
                    numbers[endPosition-4] = numbers[endPosition-8];
                    numbers[endPosition-8] = numbers[endPosition-12];
                    numbers[endPosition-12] = 0;
                }
                whileCount -=1;
            }
            else if(numbers[endPosition-8] == 0){
                if(numbers[endPosition-12] != 0 ){
                hasChanged = true;
                numbers[endPosition-8] = numbers[endPosition-12];
                numbers[endPosition-12] = 0;
                }
                whileCount -=1;
            }

            else{
                //Checking next position
                whileCount -=1;}
        }
    }
    if(hasChanged){
        addRandomTile();
    }
}

void Grid::rightLogic(){
    bool hasChanged = false;
    //Looping through each row to apply logic
    for(int i = 1; i <= 4; i ++){
        int rowNumber = i;
        int sumTwoTiles = 0;
        int endPosition = i*3+(i-1);
        int whileCount = 4;
        
        //Moving positions to the right if a position to the right of them
        while(whileCount!=0){

            //Checking if current position zero if yes move to right
            if(numbers[endPosition] == 0){
                if(numbers[endPosition-1] != 0 || numbers[endPosition-2] != 0 ||numbers[endPosition-3] != 0){
                    hasChanged = true;
                    numbers[endPosition] = numbers[endPosition-1];
                    numbers[endPosition-1] = numbers[endPosition-2];
                    numbers[endPosition-2] = numbers[endPosition-3];
                    numbers[endPosition-3] = 0;
                }
                //Rechecking same position just in case a zero replaced the zero
                whileCount -=1;
            }
            else if(numbers[endPosition-1] == 0){
                if(numbers[endPosition-2] != 0 ||numbers[endPosition-3] != 0){
                    hasChanged = true;
                    numbers[endPosition-1] = numbers[endPosition-2];
                    numbers[endPosition-2] = numbers[endPosition-3];
                    numbers[endPosition-3] = 0;
                }
                whileCount -=1;
            }
            else if(numbers[endPosition-2] == 0){
                if(numbers[endPosition-3] != 0){
                    hasChanged = true;
                    numbers[endPosition-2] = numbers[endPosition-3];
                    numbers[endPosition-3] = 0;
                }
                whileCount -=1;
            }

            else{
                //Checking next position
                whileCount -=1;}
            
        }
        
        
        //Comparing horizontal tiles (right to left) 4th and 3rd
        if(numbers[endPosition] == numbers[endPosition-1] &&numbers[endPosition]!=0){
            hasChanged = true;
            //If they equal sumTwoTiles
            sumTwoTiles = numbers[endPosition] + numbers[endPosition-1];
            
            //Set sum value to tile
            numbers[endPosition] = sumTwoTiles;
            
            //Shift left tiles to the right
            numbers[endPosition-1] = numbers[endPosition-2];
            numbers[endPosition-2] = numbers[endPosition-3];
            
            //Add zero to new last tile
            numbers[endPosition-3] = 0;
            //track score
            score += sumTwoTiles;
        }
        
        //Comparing horizontal tiles(right to left) 3rd and 2nd
       if(numbers[endPosition-1] == numbers[endPosition-2] &&numbers[endPosition-1]!=0){
           hasChanged = true;
            //If they equal sumTwoTiles
            sumTwoTiles = numbers[endPosition-1] + numbers[endPosition-2];
           
            //Set sum value to tile
            numbers[endPosition-1] = sumTwoTiles;
           
            //Shift left tile right
            numbers[endPosition-2] = numbers[endPosition-3];
           
            //Add zero to new last tile
            numbers[endPosition-3] = 0;
           //track score
           score += sumTwoTiles;
        }
        
        //Comparing horizontal tiles (right to left) 2nd and 1st
       if(numbers[endPosition-2] == numbers[endPosition-3] &&numbers[endPosition-2]!=0){
           hasChanged = true;
           //If they equal sumTwoTiles
            sumTwoTiles = numbers[endPosition-2] + numbers[endPosition-3];
           
           //Set sum value to tile
            numbers[endPosition-2] = sumTwoTiles;
           
            //Add zero to new last tile
            numbers[endPosition-3] = 0;
           //track score
           score += sumTwoTiles;
        }
        
        //Moving positions to the right if a position to the right of them
        while(whileCount!=0){

            //Checking if current position zero if yes move to right
            if(numbers[endPosition] == 0){
                if(numbers[endPosition-1] != 0 || numbers[endPosition-2] != 0 ||numbers[endPosition-3] != 0){
                    hasChanged = true;
                    numbers[endPosition] = numbers[endPosition-1];
                    numbers[endPosition-1] = numbers[endPosition-2];
                    numbers[endPosition-2] = numbers[endPosition-3];
                    numbers[endPosition-3] = 0;
                }
                //Rechecking same position just in case a zero replaced the zero
                whileCount -=1;
            }
            else if(numbers[endPosition-1] == 0){
                if(numbers[endPosition-2] != 0 ||numbers[endPosition-3] != 0){
                    hasChanged = true;
                    numbers[endPosition-1] = numbers[endPosition-2];
                    numbers[endPosition-2] = numbers[endPosition-3];
                    numbers[endPosition-3] = 0;
                }
                whileCount -=1;
            }
            else if(numbers[endPosition-2] == 0){
                if(numbers[endPosition-3] != 0){
                    hasChanged = true;
                    numbers[endPosition-2] = numbers[endPosition-3];
                    numbers[endPosition-3] = 0;
                }
                whileCount -=1;
            }

            else{
                //Checking next position
                whileCount -=1;}
            
        }
    }
    if(hasChanged){
        addRandomTile();
    }
}

void Grid::leftLogic(){
    bool hasChanged = false;
    //Looping through each row to apply logic
    for(int i = 1; i <= 4; i ++){
        int rowNumber = i;
        int sumTwoTiles = 0;
        int endPosition = i*4 - 4;
        int whileCount = 4;
        
        
        //Moving positions to the right if a position to the right of them
        while(whileCount!=0){

            //Checking if current position zero if yes move to right
            if(numbers[endPosition] == 0){
                if(numbers[endPosition+1] != 0 ||numbers[endPosition+2] != 0 ||numbers[endPosition+3] != 0  ){
                    hasChanged = true;
                    numbers[endPosition] = numbers[endPosition+1];
                    numbers[endPosition+1] = numbers[endPosition+2];
                    numbers[endPosition+2] = numbers[endPosition+3];
                    numbers[endPosition+3] = 0;
                    
                }

                //Rechecking same position just in case a zero replaced the zero
                whileCount -=1;
            }
            else if(numbers[endPosition+1] == 0){
                if(numbers[endPosition+2] != 0 ||numbers[endPosition+3] != 0 ){
                    hasChanged = true;
                    numbers[endPosition+1] = numbers[endPosition+2];
                    numbers[endPosition+2] = numbers[endPosition+3];
                    numbers[endPosition+3] = 0;
                    
                }
                whileCount -=1;
            }
            else if(numbers[endPosition+2] == 0){
                if(numbers[endPosition+3] != 0 ){
                    hasChanged = true;
                    numbers[endPosition+2] = numbers[endPosition+3];
                    numbers[endPosition+3] = 0;
                }
                whileCount -=1;
            }

            else{
                //Checking next position
                whileCount -=1;}
            
        }
        
        //Comparing horizontal tiles (right to left) 4th and 3rd
        if(numbers[endPosition] == numbers[endPosition+1] &&numbers[endPosition]!=0){
            hasChanged = true;
            //If they equal sumTwoTiles
            sumTwoTiles = numbers[endPosition] + numbers[endPosition+1];
            
            //Set sum value to tile
            numbers[endPosition] = sumTwoTiles;
            
            //Shift left tiles to the right
            numbers[endPosition+1] = numbers[endPosition+2];
            numbers[endPosition+2] = numbers[endPosition+3];
            
            //Add zero to new last tile
            numbers[endPosition+3] = 0;
            //track score
            score += sumTwoTiles;
        }
        
        //Comparing horizontal tiles(right to left) 3rd and 2nd
       if(numbers[endPosition+1] == numbers[endPosition+2] &&numbers[endPosition+1]!=0){
            hasChanged = true;
            //If they equal sumTwoTiles
            sumTwoTiles = numbers[endPosition+1] + numbers[endPosition+2];
           
            //Set sum value to tile
            numbers[endPosition+1] = sumTwoTiles;
           
            //Shift left tile right
            numbers[endPosition+2] = numbers[endPosition+3];
           
            //Add zero to new last tile
            numbers[endPosition+3] = 0;
           //track score
           score += sumTwoTiles;
        }
        
        //Comparing horizontal tiles (right to left) 2nd and 1st
       if(numbers[endPosition+2] == numbers[endPosition+3] &&numbers[endPosition+2]!=0){
           hasChanged = true;
           //If they equal sumTwoTiles
            sumTwoTiles = numbers[endPosition+2] + numbers[endPosition+3];
           
           //Set sum value to tile
            numbers[endPosition+2] = sumTwoTiles;
           
            //Add zero to new last tile
            numbers[endPosition+3] = 0;
           //track score
           score += sumTwoTiles;
        }
        
        //Moving positions to the right if a position to the right of them
        while(whileCount!=0){

            //Checking if current position zero if yes move to right
            if(numbers[endPosition] == 0){
                if(numbers[endPosition+1] != 0 ||numbers[endPosition+2] != 0 ||numbers[endPosition+3] != 0  ){
                    hasChanged = true;
                    numbers[endPosition] = numbers[endPosition+1];
                    numbers[endPosition+1] = numbers[endPosition+2];
                    numbers[endPosition+2] = numbers[endPosition+3];
                    numbers[endPosition+3] = 0;
                    
                }

                //Rechecking same position just in case a zero replaced the zero
                whileCount -=1;
            }
            else if(numbers[endPosition+1] == 0){
                if(numbers[endPosition+2] != 0 ||numbers[endPosition+3] != 0 ){
                    hasChanged = true;
                    numbers[endPosition+1] = numbers[endPosition+2];
                    numbers[endPosition+2] = numbers[endPosition+3];
                    numbers[endPosition+3] = 0;
                    
                }
                whileCount -=1;
            }
            else if(numbers[endPosition+2] == 0){
                if(numbers[endPosition+3] != 0 ){
                    hasChanged = true;
                    numbers[endPosition+2] = numbers[endPosition+3];
                    numbers[endPosition+3] = 0;
                }
                whileCount -=1;
            }

            else{
                //Checking next position
                whileCount -=1;}
            
        }
    }
    if(hasChanged){
        addRandomTile();
    }
}
