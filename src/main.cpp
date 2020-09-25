#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>
#include "functions.hpp"
#include <vector>

/*
 Capture keyboard pressX
 Make a grid class:
    vector<int> numbers
    vector<sf::RectangleShape> tiles
    colors: color2 = qwefl;kjqwerfk
            color4 = qw;ekfj
 
    Methods:
    drawGrid(window) - Use numbers and tiles and draw color in window
    addRandomTile()
    _____Logic() -

 
 XXXXXXXXLink Color of tile to Logic of Grid
 XXXXXXXXGenerate random tile in empty tiles
 XXXXXXXXAdd loop so process repeats
 
 XXXXXXXXonly add tile if something moves
 
 XXXXXXXXDraw number on tiles
 XXXXXXXXstart game with random placement
 XXXXXXXXend program if esc is hit
 XXXXXXXXrestart button space
 XXXXXXXXadd instructions
 XXXXXXXXmove tracker/score
 
 
 */

using namespace std;


int main()
{
    
    Grid gridClass;

    //Graphics stuff starting
   sf::RenderWindow window(sf::VideoMode(800, 900), "My window");

   // run the program as long as the window is open
   while (window.isOpen())
   {
       // check all the window's events that were triggered since the last iteration of the loop
       sf::Event event;
       while (window.pollEvent(event))
       {
           // "close requested" event: we close the window
           if (event.type == sf::Event::Closed)
               window.close();
           else if(event.type == sf::Event::KeyPressed){
               
               switch(event.key.code){
                       
                   case sf::Keyboard::Left:
                       gridClass.leftLogic();
                       break;
                       
                   case sf::Keyboard::Right:
                       gridClass.rightLogic();
                       break;
                       
                   case sf::Keyboard::Up:
                       gridClass.upLogic();
                       break;
                    
                   case sf::Keyboard::Down:
                       gridClass.downLogic();
                       break;
                       
                   case sf::Keyboard::Escape:
                       window.close();
                       break;
                       
                   case sf::Keyboard::Space:
                       gridClass = Grid();
               }
           }
       }

       // clear the window with black color
       //window.clear(sf::Color::Black);

       gridClass.drawGrid(window);

 
   // end the current frame
       window.display();
   }
   return 0;

   

}
