#include<iostream>
using namespace std;


//check till the middle element 
//two pointer approach
int isPalindrome(string S)
	{
	    int end=S.length()-1;
	    int start=0;
	    while(start<end)
	    {
	        if(S[start++]!=S[end--])
	           return 0;
	    }
	    return 1;
	}