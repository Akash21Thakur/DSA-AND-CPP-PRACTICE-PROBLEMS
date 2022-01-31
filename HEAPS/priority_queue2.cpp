#include<iostream>
#include<queue>

using namespace std;

class Person{
    public:
    string name;
    int age;

    Person(){

    }
    Person(string s,int a)
    {
        name=s;
        age=a;
    }
};

class PersonCompare{
    public:

    bool operator()(Person A,Person B){
        return A.age<B.age;
    }
};

int main()
{
    priority_queue<Person,vector<Person>,PersonCompare> pq;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string name;
        int age;
        cin>>name>>age;
        Person p(name,age);
        pq.push(p);
    }

    while (!pq.empty())
    {
        cout<<pq.top().name<<" "<<pq.top().age<<endl;
        pq.pop();
    }
    
}