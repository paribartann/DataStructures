//taken help from the internet but this is a DS pracitse

#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> series;

int fibMemoization(int, unordered_map<int, int>);       //Top Down Approach
int fibTabulation(int);                                 //Buttom-Up Approach    

int main() {
    unordered_map<int, int> lookUp;

    cout<<"Fibonacci Series with Memoization (Top Down Approach): \n";
    cout<< fibMemoization(8, lookUp)<<"\n";
    for (unsigned int i = 0; i < series.size(); i++) {
        cout<<series[i]<<" ";
    }
    cout<<"\n";
    cout<<"Fibonacci Series with (Buttom Up Approach): \n";
    cout<< fibTabulation(8)<<"\n";
    return 0;
}


//this requires O(n) space to store the map //0(n) memory
int fibMemoization(int n, unordered_map<int, int> lookUp) {
    
    if(find(series.begin(), series.end(), n) == series.end()) {
        series.push_back(n);
    }
    
    if (n <= 1) {
        return n;
    }
   
    //if the subproblem is seen for the first time
    //Iterator to an element with key equivalent to key. If no such element is found, past-the-end (see end()) iterator is returned.

    if (lookUp.find(n) == lookUp.end())
        lookUp[n] = fibMemoization(n-1, lookUp) + fibMemoization(n-2, lookUp);
    
    
    return lookUp[n];
    
}


//O(n) time since it contains a loop that repeats n-1 times, but it only takes constant O(1) space
int fibTabulation(int n) {

    if(n <= 1) {
        return n;
    }

    int previousFib = 0, currentFib = 1;
    for(int i = 0; i < n - 1; i++) {
        int newFib = previousFib + currentFib;
        previousFib = currentFib;
        currentFib = newFib;
    }
    return currentFib;
}