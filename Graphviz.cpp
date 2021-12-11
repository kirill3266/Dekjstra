//
// Created by kakir on 11.12.2021.
//
#include <process.h>
#include "Graphviz.h"
#define FILE "..\\Graphviz.gv"

Graphviz::Graphviz() {
    cout << "Dir is: ";
    system("echo %cd%");
    cout << endl;
    string tmp;
    tmp = "copy NUL ";
    tmp += FILE;
    cout << "Tmp is: " << tmp << endl;
    system(tmp.c_str());
    file.open(FILE, fstream::out | fstream::trunc);
    if (!file.is_open()) cerr << "File is not opened!" << endl;
    file << "graph G {\n";
}

void Graphviz::operator()(string &str) { file << str; }

//void Graphviz::show(int s) { file<< "}";
//string out(    "dot -Tps -Gstart=");//dot params
//out += to_string(s) + " " + FILE + " -o ..\\out.ps" ;//name of output file
//cout << "Output string is: " << out << endl;
//cout.flush();
//    system(out.c_str());
//};

Graphviz::~Graphviz() {
    file << "}";
    file.close();
}