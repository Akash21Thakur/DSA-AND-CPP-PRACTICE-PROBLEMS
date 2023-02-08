#include <iostream>
#include <math.h>
using namespace std;

// ABSTRACTION
// Hiding the background details and showing the neccesaary info.
// reduces complexity and provides security

// can be achieved by both class and header files

class Base
{
    int x, y;

public:
    void set(int x1, int y1)
    {
        this->x = x1;
        this->y = y1;
    }

    void display()
    {
        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
    }
};

int main()
{
    // by class
    Base obj;
    obj.set(1, 2);
    obj.display();

    // header files
    cout << pow(2, 3) << endl;
}