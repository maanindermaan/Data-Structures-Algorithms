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

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *deletingNnodesAfterMnodes(Node *&head, int m, int n)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        // Skipping m nodes
        int count = m;
        while (count-- && (curr != NULL))
        {
            prev = curr; // earlier prev = prev->next; prev->next is NULL so segmentation fault
            curr = curr->next;
        }
        // deleting n nodes
        count = n;
        while (count-- && (curr != NULL))
        {
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;
            delete temp;
        }
        prev->next = curr;
    }
    return head;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);
    Node *eight = new Node(80);
    Node *ninth = new Node(90);
    Node *tenth = new Node(100);

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

    cout << "The Linked list is: " << endl;
    print(head);
    cout << endl;

    int m;
    cout << "Enter the value of m: ";
    cin >> m;
    cout << endl;

    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << endl;
    cout << endl;
    cout << endl;

    Node *ans = deletingNnodesAfterMnodes(head, m, n);

    cout << "The Linked list after deletion is: " << endl;
    print(ans);
    cout << endl;

    return 0;
}