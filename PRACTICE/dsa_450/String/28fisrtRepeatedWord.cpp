#include<iostream>
#include<set>
#include<sstream>
using namespace std;

string firstRepetition(string s)
{
    istringstream iss(s);
    string token;

    set<string> words;

    while(getline(iss,token,' '))
    {
        if(words.find(token)!=words.end())
        {
            return token;
        }

        words.insert(token);

    }

    return "NOT FOUND";

}

int main()
{
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);
    string ans=firstRepetition(s);
    cout<<ans<<endl;
}