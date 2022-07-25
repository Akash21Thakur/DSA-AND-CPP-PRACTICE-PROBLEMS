#include <iostream>
#include <vector>
using namespace std;

class Heap
{
    vector<int> h;
    bool isMinheap;

    bool compare(int a, int b)
    {
        if (isMinheap)
            return a < b;
        else
            a > b;
    }

    void Heapify(int idx)
    {
        int left = 2 * idx;
        int right = 2 * idx + 1;

        int minIdx = idx;
        int end = h.size() - 1;
        if (left <= end and compare(h[left], h[idx]))
        {
            minIdx = left;
        }
        if (right <= end and compare(h[right], h[minIdx]))
            minIdx = right;

        if (minIdx != idx)
        {
            swap(h[minIdx], h[idx]);
            Heapify(minIdx);
        }
    }

public:
    Heap(int size = 10, bool minheap = true)
    {
        h.reserve(size);
        h.push_back(-1); // lets start from idx 1...child in 2x,2x+1
        isMinheap = minheap;
    }

    int top()
    {
        return h[1];
    }

    // push in the last and bring it to the suitable idx
    void push(int val)
    {
        h.push_back(val);
        
        int idx = h.size() - 1;
        int parent = idx / 2;
        while (idx > 1 and compare(h[idx], h[parent]))
        {
            swap(h[idx], h[parent]);
            idx = parent;
            parent /= 2;
        }
    }

    void pop()
    {
        swap(h[1], h[h.size() - 1]);
        h.pop_back();
        Heapify(1);
    }

    bool isEmpty()
    {
        return h.size() == 1;
    }

    // void print()
    // {
    //     for (int i = 0; i < h.size(); i++)
    //         cout << h[i] << " ";
    // }
};

int main()
{
    Heap hp(10, true);
    hp.push(5);
    hp.push(45);
    hp.push(20);
    hp.push(4);
    hp.push(10);
    hp.push(25);
    // hp.print();
    while (!hp.isEmpty())
    {
        cout << hp.top() << " ";
        hp.pop();
    }
}