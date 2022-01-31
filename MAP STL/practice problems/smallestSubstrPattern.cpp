#include<iostream>
#include<unordered_map>
#include<cstring>
#include<climits>

using namespace std;

string LongestSbstrPattn(string s,string p)
{
    int PL=p.length();
    int SL=s.length();

    if(PL>SL)   return "NONE1";

    int FP[256]={0};
    int FS[256]={0};
    cout<<"akash thakur"<<endl;

    for(int i=0;i<PL;i++)
      {
          char ch=p[i];
          FP[ch]++;
      }

    int count=0;
    int min_len=INT_MAX;
    int start=0,start_idx=-1;

    for(int i=0;i<SL;i++)
    {
        char ch=s[i];
        FS[ch]++;

        if(FP[ch]!=0 and FS[ch]<=FP[ch])
          count++;

        if(count==PL)
        {
            char temp=s[start];
            // cout<<"here"<<endl;

            while(FP[temp]==0 or FS[temp]>FP[temp])
            {
                // cout<<"here2"<<endl;
                FS[temp]--;
                start++;
                temp=s[start];
            }
            int len=i-start+1;
           
            if(min_len>len)
            {
                 cout<<len<<" "<<start<<endl;
                start_idx=start;
                min_len=len;
            }
        }  
    }  
    if(start_idx==-1)   return "NONE2";
    string ans= s.substr(start_idx,min_len);
    return ans;

}



int main()
{
    string s,pat;
    cout<<"Enter string : ";
    getline(cin,s);
    cout<<"Enter Pattern : ";
    getline(cin,pat);
    cout<<LongestSbstrPattn(s,pat);

}