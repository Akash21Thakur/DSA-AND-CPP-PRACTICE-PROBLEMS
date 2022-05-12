#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    Node(int d)
    {
        this->data=d;
        next=NULL;
    }
};

int main()
{
    
}