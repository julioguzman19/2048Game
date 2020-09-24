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

 public:

    Grid();
    
    void drawGrid(sf::RenderWindow& window); //Use numbers and tiles and draw color in window
    
    void addRandomTile();
    
//logic
    void printGrid();

    void upLogic();

    void rightLogic();

    void downLogic();

    void leftLogic();
    
    
};


#endif /* functions_hpp */
