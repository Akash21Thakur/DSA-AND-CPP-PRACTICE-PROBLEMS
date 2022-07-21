#include <iostream>
#include <vector>

using namespace std;
class stack
{
    vector<int> v;

public:
    void push(int n)
    {
        v.push_back(n);
    }

    bool isEmpty()
    {
        return v.empty();
    }

    void pop()
    {
        if (!isEmpty())
            v.pop_back();
    }

    int top()
    {
        if (!isEmpty())
            return v.back();
    }
};

int main()
{
    stack st;
    st.push(2);
    st.push(5);
    st.push(23);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.isEmpty() << endl;
}