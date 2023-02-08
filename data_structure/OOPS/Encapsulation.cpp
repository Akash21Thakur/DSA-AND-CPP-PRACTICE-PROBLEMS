#include <iostream>
using namespace std;

// Encapsulation
// Binding of data members and member function together in a unit
// Provides with data hiding property
// using access modifier

class Value
{
    int x;

public:
    void set(int d)
    {
        this->x = d;
    }

    int get()
    {
        return x;
    }
};

int main()
{
    Value obj;
    obj.set(2);
    cout << "Value is : " << obj.get() << endl;
}