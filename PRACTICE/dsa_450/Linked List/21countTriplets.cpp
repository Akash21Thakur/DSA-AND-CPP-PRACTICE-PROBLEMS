#include <iostream>
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

// count triplets
// METH-1   n^3,1
//  naive...3 pointer

// METH-2  n^2 ,n
// hash all the value...check for all pair if the 3rd value == sum-(pair_sum)

// METH-3  n^2, 1
// two pointer approach

// meth-3 code

int countWithTwoPointer(Node *left, Node *right, int target)
{
    int count = 0;
    // Node *left = cur->next;
    while (left != right and right->next != left and left and right)
    {
        if ((left->data + right->data) < target)
            left = left->next;
        else if ((left->data + right->data) > target)
            right = right->prev;
        else
        {
            count++;
            left = left->next;
            right = right->prev;
        }
    }
    return count;
}

int countTriplet(Node *head, int sum)
{
    int count = 0;

    Node *left = head, *right = head, *cur = head;
    while (right->next)
    {
        right = right->next;
    }

    for (; cur != NULL; cur = cur->next)
    {
        count += countWithTwoPointer(cur->next, right, sum - (cur->data));
        // cur = cur->next;
        // cout << count << endl;
    }
    // cout << count << endl;
    return count;
}

int main()
{
    Node *head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 8);
    insert(head, 9);
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int temp;
    //     cin >> temp;
    //     insert(head, temp);
    // }
    // // print(head);

    cout << countTriplet(head, 15);
}