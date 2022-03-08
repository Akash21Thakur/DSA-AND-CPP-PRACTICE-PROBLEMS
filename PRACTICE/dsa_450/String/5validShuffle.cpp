#include<iostream>
#include<algorithm>
using namespace std;

bool isValid(string s1,string s2,string result)
{
    // string result;
    if((s1.length()+s2.length())!=result.length())
       return false;
   //sort all the strings
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    sort(result.begin(),result.end());

    int i=0,j=0,k=0;  //s1,s2,result
    while(k<result.length())
    {
        if(s1[i]==result[k])
          i++;
        else if(s2[j]==result[k])
          j++;
        else
           return false;
        k++;       
    }

    return true;

}

int main()
{
    string s1,s2,result;
    cout<<"Enter string - 1 : ";
    cin>>s1;
    cout<<"Enter string - 2 : ";
    cin>>s2;
    cout<<"Enter the Shuffled string : ";
    cin>>result;
    if(isValid(s1,s2,result))
    cout<<"VALID SHUFFLE"<<endl;
    else
     cout<<"INVALID SHUFFLE"<<endl;

}