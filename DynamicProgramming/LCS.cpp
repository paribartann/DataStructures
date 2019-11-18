#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

template<typename dataType>
int LCSRecursion(dataType X, dataType Y, int m, int n);


template<typename dataType>
int LCSMemoization(dataType X, dataType Y, int m, int n);


int main() {

    string X = "ABXBDAB", Y = "BDCABA";

    cout<<"The length of the longest common subsequence of strings using Recursion = "<<LCSRecursion<string>(X, Y, X.length(), Y.length())<<endl;
    cout<<"The length of the longest common subsequence of strings using Memoization = "<<LCSMemoization<string>(X, Y, X.length(), Y.length())<<endl;
    return 0;
}



template<typename dataType>
int LCSRecursion(dataType X, dataType Y, int m, int n) {

    if(m == 0 || n == 0) 
        return 0;

    if (X[m-1] == Y[n-1]) 
        return LCSRecursion(X, Y, m-1, n-1) + 1;

    //if the last character of X and Y don't match

    return max(LCSRecursion(X, Y, m, n-1), LCSRecursion(X, Y, m-1, n));     
}



template<typename dataType>
int LCSMemoization(dataType X, dataType Y, int m, int n) {

    int c[m+1][n+1];

    //lookUp table stores solutions to already solved sub problems

    //first column and row of lookUp table is 0
    for (int i = 0; i < m+1; i++) {
        c[i][0] = 0;
    }

    for (int j = 0; j < n+1; j++) {
        c[0][j] = 0;
    }

    for (int i = 1; i < m+1; i++) {
        for(int j = 1; j < n+1; j++) {
            if(X[i-1] == Y[j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
            }
            else {
                c[i][j] = max(c[i-1][j], c[i][j-1]);
            }
        }
    }

    //LCS will be the last entry in the lookUp table
    return c[m][n];
}