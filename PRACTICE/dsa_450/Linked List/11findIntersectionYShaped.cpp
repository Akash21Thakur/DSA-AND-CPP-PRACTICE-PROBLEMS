// { Driver Code Starts
#include <iostream>

#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

int intersectPoint(struct Node *head1, struct Node *head2);

Node *inputList(int size)
{
    if (size == 0)
        return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node *head1 = inputList(n1);
        Node *head2 = inputList(n2);
        Node *common = inputList(n3);

        Node *temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

// Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node *head1, Node *head2)
{
    // method-1  for every value of list1...check in l2
    //  --> TC: O(m*n)  SC: 1

    // method-2  hash l1 value...check l2 value in hashmap
    //  -->TC: O(max(m,n))  SC: O(n)

    // method-3
    //  1.find length of both list...m=l1-l2
    //  2. move the bigger list by m steps from start
    //  3. now traverse resp. nodes...the clash is the answer.
    //  -->TC: O(2m)  SC: 1

    // method-4
    //  move h1 and h2...the one reaching the null...place in another list head
    //  in the 2nd traversal...clash will be detected...
    //  as the diff. in size is maintained when the smaller list reach the head of another list
    //  -->TC: O(2m)  SC: 1

    // CODE FOR METH-4
    Node *temp1 = head1, *temp2 = head2;
    while (temp1 != temp2)
    {
        if (temp1 == NULL)
            temp1 = head2;
        else
            temp1 = temp1->next;

        if (temp2 == NULL)
            temp2 = head1;
        else

            temp2 = temp2->next;
    }
    if (temp1 == NULL)
        return -1;
    return temp1->data;
}
