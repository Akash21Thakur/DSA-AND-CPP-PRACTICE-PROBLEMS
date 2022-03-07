#include<iostream>
using namespace std;


//algo
// ...concatenate temp=s1+s1 and check is s2 is present in temp
bool isRotation(string s1,string s2)
{
    if(s1.length()!=s2.length())
       return false;
    string temp=s1+s1;

    return( temp.find(s2) !=string::npos);

}

int main()
{
    string s1,s2;
    cin>>s1>>s2;

   
    if(isRotation(s1,s2))   cout<<"yes "<<endl;
    else cout<<"No"<<endl;
}