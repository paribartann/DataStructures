#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template<typename dataType>
int LCSRecursion(dataType X, dataType Y, int m, int n);


template<typename dataType>
void LCSMemoizationAndPrint(dataType X, dataType Y, int m, int n);


int main() {

    string X = "ABXBDAB", Y = "BDCABA";

    cout<<"The length of the longest common subsequence of strings using Recursion = "<<LCSRecursion<string>(X, Y, X.length(), Y.length())<<endl;

    LCSMemoizationAndPrint<string>(X, Y, X.length(), Y.length());
    return 0;
}


//this has the worst case time complexity of O(n^2)
template<typename dataType>
int LCSRecursion(dataType X, dataType Y, int m, int n) {

    if(m == 0 || n == 0) 
        return 0;

    if (X[m-1] == Y[n-1]) 
        return LCSRecursion(X, Y, m-1, n-1) + 1;

    //if the last character of X and Y don't match

    return max(LCSRecursion(X, Y, m, n-1), LCSRecursion(X, Y, m-1, n));     
}


//this has the worst case time complexity of O(mn)
template<typename dataType>
void LCSMemoizationAndPrint(dataType X, dataType Y, int m, int n) {

    int lookupTable[m+1][n+1];

    //lookUp table stores solutions to already solved sub problems

    //first column and row of lookUp table is 0
    for (int i = 0; i < m+1; i++) {
        lookupTable[i][0] = 0;
    }

    for (int j = 0; j < n+1; j++) {
        lookupTable[0][j] = 0;
    }

    for (int i = 1; i < m+1; i++) {
        for(int j = 1; j < n+1; j++) {
            if(X[i-1] == Y[j-1]) {
                lookupTable[i][j] = lookupTable[i-1][j-1] + 1;
            }
            else {
                lookupTable[i][j] = max(lookupTable[i-1][j], lookupTable[i][j-1]);
            }
        }
    }

    //LCS will be the last entry in the lookUp table
    cout<<"The length of the longest common subsequence of strings using Memoization = "<<lookupTable[m][n]<<endl;
    int length = lookupTable[m][n];

    char lcs[length+1]; //character array to store the lcs string
    lcs[length] = '\0';

    int i = m, j = n;

    while (i > 0 && j > 0){

        if(X[i-1] == Y[j-1]) {
            lcs[length-1] = X[i-1];
            i--, j--, length--; 
        }
        else if (lookupTable[i-1][j] > lookupTable[i][j-1])
            i--;
        else
            j--;
    }

    cout << "One of the LCS of " << X << " and " << Y << " is " << lcs << endl; 


    
    
}

