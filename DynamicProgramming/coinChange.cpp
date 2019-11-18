#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Complete the 'getWays' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. LONG_INTEGER_ARRAY c
 */

long getWays(int n, vector<long> c);
long minWays(int n, vector<long> c);


int main() {


    vector<long> coins;

    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);
    coins.push_back(6);

    int amount = 100;

    cout<<"The number of ways we can change "<< amount << " using coins = [";
    for(int i = 0; i < coins.size(); i++) {
        cout<<coins[i];
        if( i != coins.size()-1)
            cout<<", ";
    }
    cout<<" ]"<<" is = "<<getWays(amount, coins)<<endl;

    cout<<"The min number coins we need to change "<< amount << " using coins = [";
    for(int i = 0; i < coins.size(); i++) {
        cout<<coins[i];
        if( i != coins.size()-1)
            cout<<", ";
    }
    cout<<" ]"<<" is = "<<minWays(amount, coins)<<endl;



    return 0;
}



long getWays(int n, vector<long> c) {

    long lookUp[c.size()+1][n+1];

    for(int i = 0; i < c.size()+1; i++) {
        lookUp[i][0] = 1;
    }

    for(int j = 0; j < n+1; j++) {
        if(j != 0) {
            lookUp[0][j] = 0;
        }   
    } 



    //if change <= 0 OR the number of coins is 0
    for(int coins = 1; coins < c.size()+1; coins++) {
        for(int amount = 1; amount < n+1; amount++) {

            
            if(c[coins-1] > amount) {
                lookUp[coins][amount] = lookUp[coins-1][amount];
            } 
            else {
                lookUp[coins][amount] = lookUp[coins-1][amount] + lookUp[coins][amount-c[coins-1]];
            }

        }
    }
   
   return lookUp[c.size()][n];


}


long minWays(int n, vector<long> c) {

    long lookUp[c.size()+1][n+1];

    for(int i = 0; i < c.size()+1; i++) {
        lookUp[i][0] = 1;
    }

    for(int j = 0; j < n+1; j++) {
        if(j != 0) {
            lookUp[0][j] = 0;
        }   
    } 



    //if change <= 0 OR the number of coins is 0
    for(int coins = 1; coins < c.size()+1; coins++) {
        for(int amount = 1; amount < n+1; amount++) {

            if(c[coins-1] == 1) {
                lookUp[coins][amount] = amount;
            }
            else if (c[coins-1] == amount) {
                lookUp[coins][amount] = 1;
            }
            else if(c[coins-1] > amount) {
                lookUp[coins][amount] = lookUp[coins-1][amount];
            } 
            else {
                lookUp[coins][amount] = min(lookUp[coins-1][amount], lookUp[coins][amount-c[coins-1]] + 1);
            }

        }
    }
   
   return lookUp[c.size()][n];


}