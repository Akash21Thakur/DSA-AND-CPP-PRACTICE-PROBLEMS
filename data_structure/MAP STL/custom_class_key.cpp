#include<iostream>
#include<unordered_map>

using namespace std;

class Student{
    
    public:
    string lname,fname;
    int roll;
    Student(string f,string l,int roll)
    {
        this->fname=f;
        this->lname=l;
        this->roll=roll;
    }

    bool operator==(const Student &s)  const{
        return roll==s.roll;
    }

};

class HashFunc{
    public:
    size_t operator()(const Student &s) const {
        return s.fname.length()+s.lname.length();
    }
    

};

int main()
{
    unordered_map<Student,int,HashFunc> um;
    Student s1("akash","thakur",102);
    Student s2("animesh","anand",103);
    Student s3("deepak","maama",31);
    Student s4("rahul","raj",117);
    Student s5("aditya","gupta",67);

    um[s1]=88;
    um[s2]=82;
    um[s3]=90;
    um[s4]=82;
    um[s5]=95;

    for(auto x:um)
      cout<<x.first.fname<<" "<<x.second<<endl;

}