#include <iostream>
#include <climits>
#include <vector>
#include <cstring>
using namespace std;

#define R 12
#define C 10

int x[4] = {-1, 0, 1, 0};
int y[4] = {0, 1, 0, -1}; // up right down left

bool isValid(int i, int j)
{
    if (i >= 0 and i < R and j >= 0 and j < C)
        return true;
    return false;
}

void markAdjacent(vector<vector<int>> &v)
{

    // first mark neighbours as -1 ...than replace -1 with 0
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (v[i][j] == 0)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (isValid(i + x[k], j + y[k]))
                        v[i + x[k]][j + y[k]] = -1;
                }
            }
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (v[i][j] == -1)
            {
                v[i][j] = 0;
            }
        }
    }
}

bool isSafe(vector<vector<int>> &v, int i, int j, int visited[R][C])
{
    if (v[i][j] == 0 or visited[i][j] == 1)
        return false;
    return true;
}

void helperRecur(vector<vector<int>> &v, int i, int j, int &min_dist, int visited[R][C], int dist)
{
    // if destination found
    if (j == C - 1)
    {
        min_dist = min(dist, min_dist);
        return;
    }

    // can't make optimum answer
    if (dist > min_dist)
        return;

    // let path exist
    visited[i][j] = 1;

    // check for all its adjacent cells
    for (int k = 0; k < 4; k++)
    {
        if (isValid(i + x[k], j + y[k]) and isSafe(v, i + x[k], j + y[k], visited))
        {
            helperRecur(v, i + x[k], j + y[k], min_dist, visited, dist + 1);
        }
    }

    // backtraking
    visited[i][j] = 0;
}

void findShortestPath(vector<vector<int>> &v)
{
    // mark the adjacent ones as 0...
    markAdjacent(v);

    // mark visited as false for all the rows in column_0
    int visited[R][C];
    int min_dist = INT_MAX;
    for (int i = 0; i < R; i++)
    {

        if (v[i][0] == 1)
        {
            memset(visited, 0, sizeof(visited));
            helperRecur(v, i, 0, min_dist, visited, 0);

            // if minimum dist found
            if (min_dist == C - 1)
                break;
        }
    }
    cout << "Minimum Dist : " << min_dist << endl;
}

int main()
{
    vector<vector<int>> v = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1, 1, 1, 1, 1, 1}};

    findShortestPath(v);
}