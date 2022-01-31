#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<unordered_set>

using namespace std;

int longestContiStreak(vector<int> v,int n)
{
    unordered_map<int,int> m; //num,length
    for(int i=0;i<n;i++)
    {
        int num=v[i];
        if(m.count(num))   continue;
        if(m.count(num-1)==0 and m.count(num+1)==0)
          m[num]=1;
        else if(m.count(num-1) and m.count(num+1))
        {
            int len1=m[num-1];
            int len2=m[num+1];
            int len=len1+len2+1;   
            m[num]=0;
            m[num-len1]=len;
            m[num+len2]=len;
        }
        else if(m.count(num-1))
        {
            int len=m[num-1];
            m[num-len]=len+1;
            m[num]=len+1;
        }
        else
        {
            int len=m[num+1];
            m[num+len]=len+1;
            m[num]=len+1;
        }

    }

    int largest=0;
    for(auto x:m)
      largest=max(largest,x.second);

    return largest;  

}

//using unordered set
int streakUsingSet(vector<int> &v,int n)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
      s.insert(v[i]);

    int maxi=0;

    for(int i=0;i<n;i++)
    {
        if(s.find(v[i]-1)==s.end())  //possible for starting streak
        {
            int len=1;
            int next_ele=v[i]+1;
            while(s.find(next_ele)!=s.end()){
                next_ele++;
                len++;

            }
              
            maxi=max(len,maxi);  
        }
    } 
    return maxi; 
}

int main()
{
    int n,temp;
    cin>>n;
    vector<int> v;
    v.reserve(n);
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);

    }

    // cout<<"Longest Streak : "<<longestContiStreak(v,n)<<endl;
    cout<<"Using Set : "<<streakUsingSet(v,n)<<endl;

}