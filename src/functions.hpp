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
using namespace std;

void printGrid(vector<int> grid);

vector<int> upLogic(vector<int> grid);

vector<int> rightLogic(vector<int> grid);

vector<int> downLogic(vector<int> grid);

vector<int> leftLogic(vector<int> grid);
#endif /* functions_hpp */
