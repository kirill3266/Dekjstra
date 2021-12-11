//
// Created by kakir on 11.12.2021.
//

#ifndef DEKJSTRA_GRAPHVIZ_H
#define DEKJSTRA_GRAPHVIZ_H
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class Graphviz {
fstream file;
public:
Graphviz();
void operator() (string& str);
~Graphviz();
};

#endif //DEKJSTRA_GRAPHVIZ_H
