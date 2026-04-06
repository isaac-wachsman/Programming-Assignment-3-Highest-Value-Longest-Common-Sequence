# Programming Assignment 3 - Highest Value Longest Common Sequence

**Isaac Wachsman (UFID: 28099694)**



## Project Structure Overview

- **src/main.cpp**: main driver
- **src/parser.cpp**: parses the input file to obtain the mapping from characters to values and the input strings
- **src/parser.h**: header file for parser
- **src/driver.cpp**: computes the highest value common subsequence of the two strings given
- **src/driver.h**: header file for driver
  
- **tests/inputN.txt**: the Nth input file
- **tests/outputN.txt**: the Nth output file

- **data/scatter_plot.png**: scatter plot of algorithm run time vs input string length

## Compilation and Execution Instructions
(Please note that the commands given are for Windows Powershell. Similar commands can be run for other terminals.)

1. Navigate to a folder of your choice on your terminal and run `git clone https://github.com/isaac-wachsman/Programming-Assignment-3-Highest-Value-Longest-Common-Sequence.git` to clone the repository to the folder.

2. Run `cd Programming-Assignment-3-Highest-Value-Longest-Common-Sequence` , then `cd src` to navigate to the src directory.

3. Run `g++ -o main main.cpp parser.cpp driver.cpp` to compile the matching program.

4. Run `./main ../tests/inputN.txt` where N = 1, 2, or 3 to run the algorithm on the provided input files. `../tests/inputN.txt` may be replaced with the path (relative to src) to any valid input text file.



## Input / Output

The input is expected to be in the form:

```
K
x1 v1
x2 v2
...
xK vK
A
B
```
The first line contains a single positive integer, K. The next K lines contains a character xi and a nonnegative integer value vi. The xi are expected to be distinct though two different characters may have the same value. The next line contains A, a string of arbitrary length, which uses only characters from the set {x1, ..., xK}. The last line contains B, a string of arbitary length, which uses only characters from the set {x1, ..., xK}.

**NOTE:** Input files that do not match this specified format will result in undefined behavior.


The output is printed in the terminal in the form:
```
max
C
```
The first line contains the maximum value of a common subsequence of the input strings A and B. The next line contains C, a string representing a common subsequence achieving the value max. Note that there may exist multiple common subsequences achieving a value of max.

## Question 1
![Running Time vs Input String Length](data/scatter_plot.png)

The time complexity appears to be quadratic in n, which is expected as the time complexity of my algorithm is $O(nm)$, which is $O(n^2)$ when $n=m$.

## Question 2

Assume the input strings are $A = a_1 a_2 ... a_n$ and $B = b_1 b_2 ... b_m$. Define $dp[i,j]$ to be the maximum value of a common subsequence between $a_1 a_2 ... a_i$ and $b_1 b_2 ... b_j$. 

The recurrence used that is the basis of the algorithm is $dp[i,j] = dp[i-1, j-1] + value(a_i)$ if $a_i = b_j$ and $dp[i,j] = max(dp[i-1, j], dp[i, j-1])$ if $a_i \neq b_j$. The base cases are $dp[i,j] = 0$ if $i=0$ or $j=0$.

First off, note that the base cases are correct because if one of the strings is empty ($i=0$ or $j=0$), then the longest common subsequence is 0. If $a_i = b_j$, then the highest value common subsequence includes this character at the end, so we should add the value of this character to the highest value found between the strings without the last character which is $dp[i-1, j-1]$ by definition. If $a_i \neq b_j$, then the highest value common subsequence cannot end in both $a_i$ and $b_j$, so either $dp[i,j] = dp[i-1,j]$ or $dp[i,j] = dp[i, j-1]$. We take the maximum of these two because $dp[i,j]$ is defined to be the maximum value of common subsequences.

## Question 3
The assignment defines highest value common subsequences (HVCS), but never defines HVLCS (highest value <b>longest</b> common subsequence), so there is some ambiguity in the question. If we interpret HVCS and HVLCS to mean exactly the same thing, then the question is ill-posed because the length of the HVCS of A and B is not uniquely determined. For example, if A = 'aab' and B = 'baa' with a = 1 and b = 2, then 'aa' and 'b' are both highest value common subsequences but have different lengths. Therefore, I am interpreting a HVLCS of A and B to be a maximum valued subsequence over all maximum-length common subsequences of A and B. Hence, the length of all HVLCS's of A and B are the same - in fact they are all equal to the length of a longest common subsequence of A and B. Below is pseudocode for computing the length of the longest common subsequence of A and B: 

```
ALGORITHM LCSLength(A, B):
    n = length(A)
    m = length(B)
    
    CREATE TABLE DP[0...n][0...m]
    
    FOR i FROM 1 TO n:
        FOR j FROM 1 TO m:
            IF A[i] == B[j]:
                DP[i][j] = DP[i-1][j-1] + 1
            ELSE:
                DP[i][j] = max(DP[i-1][j], DP[i][j-1])  
    RETURN DP[n][m]
```

It is clear from the loops in the pseudocode that the time complexity of this algorithm is $O(nm)$.
