#include <deque>
#include <iostream>

using namespace std;

int main()
{
    deque<int> dq; // extend.contract from both side
    dq.push_back(1);
    dq.push_back(10);
    dq.push_back(100); // push

    int x = dq.back(); // top
    cout << x << endl;
    dq.pop_back(); // pop
}