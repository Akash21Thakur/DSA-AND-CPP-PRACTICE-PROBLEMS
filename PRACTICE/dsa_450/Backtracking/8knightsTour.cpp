#include <iostream>
#include <vector>
using namespace std;

int x[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isSafe(int i, int j, int v[8][8])
{
    // cout << "akash" << endl;
    if (i >= 0 and i < 8 and j >= 0 and j < 8 and v[i][j] == -1)
        return true;
    return false;
}

bool knightMove(int i, int j, int counter, int v[8][8])
{
    if (counter == 8 * 8)
        return true;

    for (int k = 0; k < 8; k++)
    {
        int x_next = i + x[k];
        int y_next = j + y[k];

        if (isSafe(x_next, y_next, v))
        {
            v[x_next][y_next] = counter;
            if (knightMove(x_next, y_next, counter + 1, v))
                return true;
            else
                // backtracking
                v[x_next][y_next] = -1;
        }
    }
    return false;
}

void printSoln(int v[8][8])
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << v[i][j] << "\t";
        cout << endl;
    }
}

int main()
{
    // vector<vector<int>> v(8 + 1, vector<int>(8 + 1, -1));
    int v[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            v[i][j] = -1;
    }
    // printSoln(v);
    int counter = 1;
    v[0][0] = 0; // start of knight
    if (knightMove(0, 0, counter, v))
    {
        cout << "akash" << endl;
        printSoln(v);
    }
    else
        cout << "Solution NOt found" << endl;
}