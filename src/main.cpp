#include <SFML/Graphics.hpp>
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

int main()
{
    
    vector<int> grid(16);
    vector<int> newGrid(16);
    grid = {2,4,6,8,2,3,3,3,3,3,3,3,3,14,15,16};
  //  for(int i = 0; i < 16; i++){
  //    grid[i] = i;
  //  }
    printGrid(grid);
    cout << endl;
    newGrid = upLogic(grid,1);
    printGrid(newGrid);
    cout << endl;
    return 0;
    
    /*
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

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

// set the shape color to green
shape.setFillColor(sf::Color(100, 250, 50));

 window.draw(shape);
    // end the current frame
        window.display();
    }

    return 0;
 
 }
*/

}
