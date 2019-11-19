/*
    You are given a string representing an attendance record for a student. The record only 
    contains the following three characters:

    \'A\' : Absent.
    \'L\' : Late.
    \'P\' : Present.
    A student could be rewarded if his attendance record doesn\'t contain more than one \'A\' (absent) or more than two continuous \'L\' (late).

    You need to return whether the student could be rewarded according to his attendance record.

    Example 1:

    Input: "PPALLP"
    Output: True

    Example 2:

    Input: "PPALLL"
    Output: False

*/

#include <iostream>
#include <string>
#include <regex>


using namespace std;

bool checkRecordExample1(string s);

bool checkRecordExample2(string s);

bool checkRecordRegex(string s);

void printString(string s);

int main() {
    string s = "PAALPALLL";
    string t = "PPALLP";


    bool checkA_s = checkRecordExample1(s);
    bool checkA_t = checkRecordExample1(t);

    bool checkB_s = checkRecordExample2(s);
    bool checkB_t = checkRecordExample2(t);

    bool checkC_s = checkRecordRegex(s);
    bool checkC_t = checkRecordRegex(t);


    cout<<"Can we reward student s = ";
    printString(s);
    cout<<" ? = "<< checkA_s<<endl;

    cout<<"Can we reward student t = ";
    printString(t);
    cout<< " ? = "<< checkA_t<<endl;
    cout<<endl;

     cout<<"Can we reward student s = ";
    printString(s);
    cout<<" ? = "<< checkB_s<<endl;

    cout<<"Can we reward student t = ";
    printString(t);
    cout<< " ? = "<< checkB_t<<endl;
    cout<<endl;

      cout<<"(using regex)Can we reward student s = ";
    printString(s);
    cout<<" ? = "<< checkC_s<<endl;

    cout<<"(using regex) Can we reward student t = ";
    printString(t);
    cout<< " ? = "<< checkC_t<<endl;
    cout<<endl;

    return 0;
}
 

bool checkRecordExample1(string s) {

    int countA = 0, countL = 0;
    bool flag = true;

    for(char c : s) {
      
        if ( c == 'A' ) {
            ++countA;
            countL = 0;
            if (countA > 1) return false;
        }
        else if ( c == 'L') {
            countL++;
            if(countL > 2) return false;
        } else {
            countL = 0;
        }
    }
    return true;
}

bool checkRecordExample2(string s) {

    return (s.find("A") == string::npos || s.find("A") == s.rfind("A")) && s.find("LLL") == string::npos;
}

bool checkRecordRegex(string s) {
    return !regex_search(s, regex("A.*A|LLL"));
}

void printString(string s) {

    for (char c : s) {
        cout<<c;
        if(c != '\0')
            cout<<" ";

    }
}