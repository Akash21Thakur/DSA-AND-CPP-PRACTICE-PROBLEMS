#include<iostream>
using namespace std;

//method-1  include/not 1st character
void printSubSeq(string input,string output)
{
    //as input becomes empty...print the output
    if(input.empty())
    {
        cout<<output<<endl;
        return;
    }

    //includes Ist character of input string
    printSubSeq(input.substr(1),output+input[0]);
    
    //without the first character of input string
    printSubSeq(input.substr(1),output);

}

int main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;

    printSubSeq(s,"");

}