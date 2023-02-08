#include <bits/stdc++.h>
using namespace std;

// OPERATOR OVERLOADING
// compile-time polymorphism
// --> ability to provode operator with special meaning for the user defined data type

class add_diff
{
    int x, y;

public:
    add_diff(int a, int b)
    {
        this->x = a;
        this->y = b;
    }

    int add()
    {
        return x + y;
    }

    int operator+()
    {
        return x - y;
    }
};


int main()
{
    add_diff obj(10, 5);
    cout << "Before Overloading : " << obj.add() << endl;
    cout << "After Overloading : " << +obj;
}