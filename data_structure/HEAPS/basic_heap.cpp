#include <iostream>
#include <vector>

using namespace std;

class Heap
{
    vector<int> h;
    bool minHeap;

    bool compare(int a, int b)
    {
        if (minHeap)
            return a < b;
        else
            return b < a;
    }

    void heapify(int idx)
    {
        int left = 2 * idx;
        int right = left + 1;

        int min_idx = idx;
        int last = h.size() - 1;

        if (left <= last and compare(h[left], h[idx]))
        {
            min_idx = left;
        }
        if (right <= last and compare(h[right], h[min_idx]))
        {
            min_idx = right;
        }

        if (min_idx != idx)
        {
            swap(h[idx], h[min_idx]);
            heapify(min_idx);
        }
    }

public:
    Heap(int hsize = 10, bool minh = true)
    {
        h.reserve(hsize);
        h.push_back(-1);
        minHeap = minh;
    }

    void push(int d)
    {
        h.push_back(d);
        int idx = h.size() - 1;
        int parent = idx / 2;
        while (idx > 1 and compare(h[idx], h[parent]))
        {
            swap(h[parent], h[idx]);
            idx = parent;
            parent = parent / 2;
        }
    }

    int top()
    {
        return h[1];
    }

    void pop()
    {
        int last = h.size() - 1;
        swap(h[last], h[1]);
        h.pop_back();
        heapify(1);
    }

    bool empty()
    {
        return h.size() == 1;
    }
};

int main()
{
    //    cout<<"TALK IS SLOW, SHOW ME THE CODE !"<<endl;
    Heap h(10, false);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int no;
        cin >> no;
        h.push(no);
    }

    // remove all the element
    while (!h.empty())
    {
        cout << h.top() << " ";
        h.pop();
    }
}