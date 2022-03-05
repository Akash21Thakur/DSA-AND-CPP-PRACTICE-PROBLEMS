#include<iostream>
#include<vector>
using namespace std;

//swap first to the last till the middle element
void reverseString(vector<char>& s) {
        int last=s.size()-1;
        int start=0;
        
        while(start<=last)
           swap(s[start++],s[last--]);
                
        
    }

