#include <iostream>
#include <vector>
#include "parser.h"
#include "driver.h"
#include <chrono>


using namespace std;


int main(int argc, char* argv[])
{
    auto start = chrono::high_resolution_clock::now();

    string filepath = argv[1];

    InputData inputData = parseInput(filepath);

    string optimal = get_optimal_subsequence(inputData);

    int sum = 0;

    for(int i = 0; i < optimal.length(); i++)
    {
        sum += inputData.character_map[optimal[i]];
    }

    cout << sum << endl;

    cout << optimal << endl;


    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double> elapsed = end - start;


    cout << "Elapsed time: " << elapsed.count() << "s" << endl;

    return 0;

}
