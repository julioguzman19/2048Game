#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
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

 
 Link Color of tile to Logic of Grid
 Generate random tile in empty tiles
 Add loop so process repeats
 
 Draw number on tiles
 */

using namespace std;


int main()
{
    
    vector<int> grid(16);
    vector<int> newGrid(16);
    grid = {0,0,6,6,0,0,3,3,3,3,0,0,3,14,15,16};
//    for(int i = 0; i < 16; i++){
//      grid[i] = i;
//    }
    printGrid(grid);
    cout << endl;
    //newGrid = leftLogic(grid);
    //printGrid(newGrid);
     //   cout << endl;

    
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
                       newGrid = leftLogic(grid);
                       printGrid(newGrid);
                       break;
                       
                   case sf::Keyboard::Right:
                       newGrid = rightLogic(grid);
                       printGrid(newGrid);
                       break;
                       
                   case sf::Keyboard::Up:
                       newGrid = upLogic(grid);
                       printGrid(newGrid);
                       break;
                    
                   case sf::Keyboard::Down:
                       newGrid = downLogic(grid);
                       printGrid(newGrid);
                       break;
               }
           }
       }

       // clear the window with black color
       window.clear(sf::Color::Black);

   sf::CircleShape shape(50.f);




       

       
  
       
       //grid lines color
       line1.setFillColor(sf::Color(200, 250, 50));
       line2.setFillColor(sf::Color(200, 250, 50));
       line3.setFillColor(sf::Color(200, 250, 50));
       hline1.setFillColor(sf::Color(200, 250, 50));
       hline2.setFillColor(sf::Color(200, 250, 50));
       hline3.setFillColor(sf::Color(200, 250, 50));
       hline4.setFillColor(sf::Color(200, 250, 50));
       
       
       
   //window.draw(shape);
       window.draw(line1);
       window.draw(line2);
       window.draw(line3);
       
       window.draw(hline1);
       window.draw(hline2);
       window.draw(hline3);
       window.draw(hline4);
       
       window.draw(tile0);
       window.draw(tile1);
       window.draw(tile2);
       window.draw(tile3);
       
       window.draw(tile4);
       window.draw(tile5);
       window.draw(tile6);
       window.draw(tile7);
       
       window.draw(tile8);
       window.draw(tile9);
       window.draw(tile10);
       window.draw(tile11);
       
       window.draw(tile12);
       window.draw(tile13);
       window.draw(tile14);
       window.draw(tile15);

   // end the current frame
       window.display();
   }
   return 0;

   

}
