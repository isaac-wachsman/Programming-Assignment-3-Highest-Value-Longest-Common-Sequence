#ifndef PARSER_H
#define PARSER_H


#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct InputData
{
    unordered_map<char, int> character_map;
    string str1;
    string str2;
};

InputData parseInput(string filename);


#endif