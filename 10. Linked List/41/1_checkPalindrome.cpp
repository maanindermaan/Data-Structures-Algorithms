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

Node *reverseLL(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev; // This is L.L. ka head
}

bool isPalindrome(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty sorry";
    }

    if (head->next == NULL)
    {
        // Only one node
        return true;
    }

    // >= 1 node

    // Step A -> Find middle node
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        // Slow is pointing to middle node now
    }
    // Step B -> reverse LL after middle node
    Node *reverseLLkaHead = reverseLL(slow->next);
    // Join the reversed LL into the left side part
    slow->next = reverseLLkaHead;

    // Step C -> Start Comparison
    Node *temp1 = head;
    Node *temp2 = reverseLLkaHead;

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            // Not a palindrome
            return false;
        }
        else
        {
            // equal wala case ==
            // Aage bad jao
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(50);
    Node *seventh = new Node(40);
    Node *eight = new Node(30);
    Node *ninth = new Node(20);
    Node *tenth = new Node(10);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;
    eight->next = ninth;
    ninth->next = tenth;
    tenth->next = NULL;

    cout << endl;
    cout << endl;

    if (isPalindrome(head))
    {
        cout << "Yes it is a palindrome";
    }
    else
    {
        cout << "Oops not a palindrome";
    }

    cout << endl;
    cout << endl;

    return 0;
}
















