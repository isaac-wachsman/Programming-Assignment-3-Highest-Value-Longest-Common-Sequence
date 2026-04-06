#include <iostream>
#include <vector>
#include "parser.h"
#include "driver.h"


using namespace std;


int main(int argc, char* argv[])
{
    string filepath = argv[1];

    InputData inputData = parseInput(filepath);

    string optimal = get_optimal_subsequence(inputData);

    int sum = 0;

    for(int i = 0; i < optimal.length(); i++)
    {
        sum += inputData.character_map[optimal[i]];
    }

    cout << sum << endl;

    cout << "One optimal subsequence is: " << optimal << endl;

    return 0;

}