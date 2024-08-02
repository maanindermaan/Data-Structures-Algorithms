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

void removeDuplicates(Node *&head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        Node *temp = curr;
        while (temp->next != NULL)
        {
            if (curr->data == temp->next->data)
            {
                Node *duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;
            }
            else
            {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
}

int main()
{
    Node *head = new Node(4);
    Node *second = new Node(2);
    Node *third = new Node(1);
    Node *fourth = new Node(4);
    Node *fifth = new Node(2);
    Node *sixth = new Node(7);
    Node *seventh = new Node(2);
    Node *eight = new Node(1);
    Node *ninth = new Node(4);
    Node *tenth = new Node(7);

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

    print(head);

    removeDuplicates(head);
    cout << endl;
    cout << endl;

    print(head);

    cout << endl;
    cout << endl;

    return 0;
}