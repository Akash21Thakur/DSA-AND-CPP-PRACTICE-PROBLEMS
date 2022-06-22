#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

#define R 3
#define C 10

struct Pair
{
    bool found;
    int value;
};

Pair helper(int mat[R][C], int i, int j, int x, int y, bool visited[R][C])
{
    // if dest. reached
    if (i == x and j == y)
        return {true, 0};
    // if out of bound or path not possible or already visited
    if (i < 0 or i >= R or j < 0 or j >= C or mat[i][j] == 0 or visited[i][j] == true)
        return {false, INT_MAX};

    visited[i][j] = true;
    int res = INT_MIN; // at first

    // move left
    Pair sol = helper(mat, i, j - 1, x, y, visited);
    if (sol.found)
        res = max(res, sol.value);

    // right
    sol = helper(mat, i, j + 1, x, y, visited);
    if (sol.found)
        res = max(res, sol.value);

    // up
    sol = helper(mat, i - 1, j, x, y, visited);
    if (sol.found)
        res = max(res, sol.value);

    // down
    sol = helper(mat, i + 1, j, x, y, visited);
    if (sol.found)
        res = max(res, sol.value);
    // backtracking
    visited[i][j] = false;

    // if res updated
    if (res != INT_MIN)
        return {true, 1 + res};

    else
        return {false, INT_MAX};
}

void findLongestPath(int mat[R][C], int i, int j, int x, int y)
{
    bool visited[R][C];

    memset(visited, false, sizeof(visited));
    Pair p = helper(mat, i, j, x, y, visited);

    if (p.found)
        cout << "Max. Distance is : " << p.value << endl;
    else
        cout << "Dest. cannot be reached" << endl;
}

int main()
{
    int mat[R][C] = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                     {1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
                     {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    findLongestPath(mat, 0, 0, 1, 7);
}