#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include "parser.h"

using namespace std;

InputData parseInput(string filename)
{
    InputData data;

    ifstream inputFile(filename);

    int K;

    inputFile >> K;

    for(int i = 0; i < K; ++i)
    {
        char c;
        int value;
        inputFile >> c >> value;
        data.character_map[c] = value;
    }

    inputFile >> data.str1;

    inputFile >> data.str2;


    return data;

}
