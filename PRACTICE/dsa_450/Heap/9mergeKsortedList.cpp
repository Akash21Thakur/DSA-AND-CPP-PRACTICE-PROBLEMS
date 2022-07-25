#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct comp
{
public:
    bool operator()(const ListNode *a, const ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {

        // minheap
        priority_queue<ListNode *, vector<ListNode *>, comp> pq;

        // push the head of all the list
        int n = lists.size();

        for (int i = 0; i < n; i++)
        {
            if (lists[i])
                pq.push(lists[i]);
        }

        if (!pq.size())
            return NULL;

        ListNode *result = pq.top();
        pq.pop();

        ListNode *temp = result;
        if (temp->next)
            pq.push(temp->next);

        while (!pq.empty())
        {
            temp->next = pq.top();
            pq.pop();
            temp = temp->next;

            if (temp->next)
                pq.push(temp->next);
        }

        return result;
    }
};