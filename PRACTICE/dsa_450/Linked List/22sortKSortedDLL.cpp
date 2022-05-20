#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;

    Node(int d)
    {
        this->data = d;
        next = NULL;
        prev = NULL;
    }
};

void insert(Node *&head, int d)
{
    if (!head)
    {
        head = new Node(d);
        return;
    }
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new Node(d);
    temp->next->prev = temp;
}

void print(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// sort the k sorted array...elements may lie k position frwd or back of its original position in sorted one
// meth-1 n*k,1
void sortDLL(Node **head, int k)
{
    if (*head == NULL or !((*head)->next))
        return;

    for (Node *i = (*head)->next; i != NULL; i = i->next)
    {
        Node *j = i;

        while (j->prev != NULL and j->data < j->prev->data)
        {
            Node *t1 = j->prev->prev;
            Node *t2 = j->prev;
            Node *t3 = j->next;

            j->prev->next = t3;
            j->prev->prev = j;
            // j->next->prev=t2;
            j->next = t2;
            j->prev = t1;

            if (t1 != NULL)
                t1->next = j;
            if (t3 != NULL)
                t3->prev = t2;
        }

        if (j->prev == NULL)
            *head = j;
    }
}

struct compare
{
    bool operator()(Node *p1, Node *p2)
    {
        return p1->data > p2->data;
    }
};
// method-2   nlogk,k+1
// min_head k+1 values...pop top and push next
Node *sortAKSortedDLLHeap(Node *head, int k)
{
    if (!head)
        return NULL;

    priority_queue<Node *, vector<Node *>, compare> pq;

    // insert first k+1 element ...
    for (int i = 0; i <= k and head; i++)
    {
        pq.push(head);
        head = head->next;
    }
    Node *newHead = NULL, *last;
    while (!pq.empty())
    {
        // first node
        if (newHead == NULL)
        {
            newHead = pq.top();
            newHead->prev = NULL;
            last = newHead;
        }
        else
        {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }
        pq.pop();

        // push in heap the next element if present
        if (head != NULL)
        {
            pq.push(head);
            head = head->next;
        }
    }
    // last node shoult point NULL
    last->next = NULL;
    return newHead;
}

int main()
{
    Node *head = NULL;
    insert(head, 3);
    insert(head, 6);
    insert(head, 2);
    insert(head, 12);
    insert(head, 56);
    insert(head, 8);

    print(head);
    // sortDLL(&head, 2);
    head = sortAKSortedDLLHeap(head, 2);
    print(head);
}