#include <iostream>
using namespace std;
int getMax(int *a)
{
    int maxi = 0;
    for (int i = 1; i < 3; i++)
        if (a[i] > a[maxi])
            maxi = i;

    return maxi;
}

int getMin(int *a)
{
    int mini = 0;
    for (int i = 1; i < 3; i++)
        if (a[i] < a[mini])
            mini = i;

    return mini;
}

int minOfTwo(int a, int b)
{
    return (a < b) ? a : b;
}

void minCashFlowRec(int *a)
{
    // mxCredit: person will get amount
    // mxDebit: person has to pay

    int mxCredit = getMax(a), mxDebit = getMin(a);

    // if both 0 means...balanced
    if (a[mxCredit] == 0 and a[mxDebit] == 0)
        return;

    // find the minimum of amount to be credited or debitted
    int mini = minOfTwo(-a[mxDebit], a[mxCredit]);

    // increase the amount from who paid  ... reducing the negative
    a[mxDebit] += mini; // reduce the amount from person who got money

    a[mxCredit] -= mini; // increase the amount from who paid  ... reducing the negative

    cout << "Person " << mxDebit << " paid " << mini << " to Person" << mxCredit << endl;

    // call recursive
    minCashFlowRec(a);
}

void minCashFlow(int g[][3], int n)
{
    // amount[n]: net amount to be paid or taken from ith person...
    int amount[n] = {0};

    for (int p = 0; p < n; p++)
    {
        for (int i = 0; i < n; i++)
            amount[p] += (g[i][p] - g[p][i]); // get-give
    }

    minCashFlowRec(amount);
}

int main()
{
    // graph[N][N]: ith person pays to jth person
    int graph[][3] = {{0, 100, 200},
                      {0, 0, 500},
                      {0, 0, 0}};
    minCashFlow(graph, 3);
}