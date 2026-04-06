#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "parser.h"

using namespace std;


string get_optimal_subsequence(InputData data)
{
    unordered_map<char, int> characterMap = data.character_map;
    string str1 = data.str1;
    string str2 = data.str2;

    int n = str1.length();
    int m = str2.length();

    vector<vector<long long>> dp(n+1, vector<long long>(m+1,0));


    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            if (str1[i-1] == str2[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + characterMap[str1[i-1]];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }


    string optimal = "";
    int i = n;
    int j = m;

    while(i > 0 && j > 0)
    {
        if(str1[i-1] == str2[j-1])
        {
            optimal += str1[i-1];
            i--;
            j--;
        }
        else if (dp[i-1][j] >= dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    reverse(optimal.begin(), optimal.end());

    return optimal;
}
