//
//  functions.hpp
//  testSFML
//
//  Created by Julio Guzman & Colin Mitchell on 9/22/20.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class Grid{
    
    vector<int> numbers;
    vector<sf::RectangleShape> lines;
    vector<sf::RectangleShape> tiles;
    sf::Color color0, color2, color4, color8, color16, color32, color64, color128, color256, color512, color1024, color2048;
    
    Grid();
    
    void drawGrid(sf::RenderWindow window); //Use numbers and tiles and draw color in window
    
    void addRandomTile();
    
//logic
    void printGrid(vector<int> grid);

    vector<int> upLogic(vector<int> grid);

    vector<int> rightLogic(vector<int> grid);

    vector<int> downLogic(vector<int> grid);

    vector<int> leftLogic(vector<int> grid);
    
    
};


#endif /* functions_hpp */
