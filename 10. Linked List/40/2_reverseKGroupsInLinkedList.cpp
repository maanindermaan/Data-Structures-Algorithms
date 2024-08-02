#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int findLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

Node *reverseKNodes(Node *&head, int k)
{
    if (head == NULL)
    {
        cout << "empty";
        return head;
    }

    int len = findLength(head);
    if (k > len)
    {
        // cout << "Enter the valid value of k";
        return head;
    }

    // It means number of nodes in L.L. >=k
    // Step A : Reverse first k nodes of LL;

    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    int count = 0;
    while (count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }

    // Step B : recursive call
    if (forward != NULL)
    {
        // There are nodes left that are not pulled into k groups
        head->next = reverseKNodes(forward, k);
    }

    // Step C : return head of modified LL;
    return prev;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    cout << endl;
    cout << endl;
    print(head);

    int k = 4;
    head = reverseKNodes(head, k);

    cout << endl;
    print(head);
    cout << endl;
    cout << endl;

    return 0;
}
