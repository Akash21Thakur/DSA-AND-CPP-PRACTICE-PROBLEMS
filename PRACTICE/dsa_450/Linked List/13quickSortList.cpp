// { Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;

// REF: GFG ARTICLE

/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node **head_ref, int new_data)
{
    /* allocate node */
    struct node *new_node = new node(new_data);

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
    int t, n, x;
    cin >> t;
    while (t--)
    {

        cin >> n;
        n = n - 1;
        cin >> x;
        node *temp, *head = new node(x);
        temp = head;
        while (n--)
        {
            cin >> x;
            temp->next = new node(x);
            temp = temp->next;
        }

        quickSort(&head);

        printList(head);
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            free(temp);
        }
    }
    return 0;
} // } Driver Code Ends

/* a node of the singly linked list
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */

// finding tail
node *findTail(node *head)
{
    while (head and head->next)
        head = head->next;
    return head;
}

node *partition(node *head, node *end, node **newHead, node **newEnd)
{
    node *pivot = end;
    node *prev = NULL, *cur = head, *tail = pivot;

    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            if (*newHead == NULL)
            {
                *newHead = cur;
            }

            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev)
                prev->next = cur->next;
            node *temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }
    if (*newHead == NULL)
        *newHead = pivot;

    *newEnd = tail;

    return pivot;
}

node *quickSortRecurr(node *head, node *end)
{
    if (!head or head == end)
        return head;

    node *newHead = NULL, *newEnd = NULL;

    // Partition about pivot...with newHead and newEnd updation along
    node *pivot = partition(head, end, &newHead, &newEnd);

    // pivot is the smallest --> no left node present no need to recurr the left side
    if (newHead != pivot)
    {
        // make the first half independent...(prev of pivot)->next=NULL
        node *temp = newHead;
        while (temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;

        // recurr the left side
        newHead = quickSortRecurr(newHead, temp);

        // place pivot just after the left end
        temp = findTail(newHead);
        temp->next = pivot;
    }

    pivot->next = quickSortRecurr(pivot->next, newEnd);

    return newHead;
}

// you have to complete this function
void quickSort(struct node **headRef)
{
    *headRef = quickSortRecurr(*headRef, findTail(*headRef));
    return;
}