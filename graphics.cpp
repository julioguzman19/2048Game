//
//  graphics.cpp
//  testSFML
//
//  Created by Rex Colin Mitchell on 9/23/20.
//

#include "graphics.hpp"

// THIS SHOULD GO IN A MAIN FUNCTION, BUT I'M STORING IT HERE FOR NOW, UNTIL WE FIGURE OUT HOW TO LINK TO OUR LOGIC

// create the window

/*
int main()
 {
 

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
    }

    // clear the window with black color
    window.clear(sf::Color::Black);

sf::CircleShape shape(50.f);

//vertical lines
sf::RectangleShape line1(sf::Vector2f(1.f, 800.f));
    line1.setPosition(200.f, 100.f);
sf::RectangleShape line2(sf::Vector2f(1.f, 800.f));
    line2.setPosition(400.f, 100.f);
sf::RectangleShape line3(sf::Vector2f(1.f, 800.f));
    line3.setPosition(600.f, 100.f);
   
//horizontal lines
sf::RectangleShape hline1(sf::Vector2f(800.f, 1.f));
    hline1.setPosition(0.f, 100.f);
sf::RectangleShape hline2(sf::Vector2f(800.f, 1.f));
    hline2.setPosition(0.f, 300.f);
sf::RectangleShape hline3(sf::Vector2f(800.f, 1.f));
    hline3.setPosition(0.f, 500.f);
sf::RectangleShape hline4(sf::Vector2f(800.f, 1.f));
    hline4.setPosition(0.f, 700.f);
    
//tiles row 1
sf::RectangleShape tile0(sf::Vector2f(180.f, 180.f));
    tile0.setPosition(10.f, 110.f);
sf::RectangleShape tile1(sf::Vector2f(180.f, 180.f));
    tile1.setPosition(210.f, 110.f);
sf::RectangleShape tile2(sf::Vector2f(180.f, 180.f));
    tile2.setPosition(410.f, 110.f);
sf::RectangleShape tile3(sf::Vector2f(180.f, 180.f));
    tile3.setPosition(610.f, 110.f);

//tiles row 2
sf::RectangleShape tile4(sf::Vector2f(180.f, 180.f));
    tile4.setPosition(10.f, 310.f);
sf::RectangleShape tile5(sf::Vector2f(180.f, 180.f));
    tile5.setPosition(210.f, 310.f);
sf::RectangleShape tile6(sf::Vector2f(180.f, 180.f));
    tile6.setPosition(410.f, 310.f);
sf::RectangleShape tile7(sf::Vector2f(180.f, 180.f));
    tile7.setPosition(610.f, 310.f);

//tiles row 3
sf::RectangleShape tile8(sf::Vector2f(180.f, 180.f));
    tile8.setPosition(10.f, 510.f);
sf::RectangleShape tile9(sf::Vector2f(180.f, 180.f));
    tile9.setPosition(210.f, 510.f);
sf::RectangleShape tile10(sf::Vector2f(180.f, 180.f));
    tile10.setPosition(410.f, 510.f);
sf::RectangleShape tile11(sf::Vector2f(180.f, 180.f));
    tile11.setPosition(610.f, 510.f);
    
//tiles row 4
sf::RectangleShape tile12(sf::Vector2f(180.f, 180.f));
    tile12.setPosition(10.f, 710.f);
sf::RectangleShape tile13(sf::Vector2f(180.f, 180.f));
    tile13.setPosition(210.f, 710.f);
sf::RectangleShape tile14(sf::Vector2f(180.f, 180.f));
    tile14.setPosition(410.f, 710.f);
sf::RectangleShape tile15(sf::Vector2f(180.f, 180.f));
        tile15.setPosition(610.f, 710.f);
    
    // set the shape color to green
shape.setFillColor(sf::Color(100, 250, 50));
    //grid lines color
    line1.setFillColor(sf::Color(200, 250, 50));
    line2.setFillColor(sf::Color(200, 250, 50));
    line3.setFillColor(sf::Color(200, 250, 50));
    hline1.setFillColor(sf::Color(200, 250, 50));
    hline2.setFillColor(sf::Color(200, 250, 50));
    hline3.setFillColor(sf::Color(200, 250, 50));
    hline4.setFillColor(sf::Color(200, 250, 50));
    
    //row 1 tile color
    tile0.setFillColor(sf::Color(800, 240, 10));
    tile1.setFillColor(sf::Color(800, 240, 10));
    tile2.setFillColor(sf::Color(800, 240, 10));
    tile3.setFillColor(sf::Color(800, 240, 10));
    //row 2 tile color
    tile4.setFillColor(sf::Color(800, 240, 10));
    tile5.setFillColor(sf::Color(800, 240, 10));
    tile6.setFillColor(sf::Color(800, 240, 10));
    tile7.setFillColor(sf::Color(800, 240, 10));
    
    //row 3 tile color
    tile8.setFillColor(sf::Color(800, 240, 10));
    tile9.setFillColor(sf::Color(800, 240, 10));
    tile10.setFillColor(sf::Color(800, 240, 10));
    tile11.setFillColor(sf::Color(800, 240, 10));
    
    //row 4 tile color
    tile12.setFillColor(sf::Color(800, 240, 10));
    tile13.setFillColor(sf::Color(800, 240, 10));
    tile14.setFillColor(sf::Color(800, 240, 10));
    tile15.setFillColor(sf::Color(800, 240, 10));
    
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
return 0;
 }
 
 */
