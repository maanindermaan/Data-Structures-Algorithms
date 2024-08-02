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

Node* intersectionOfTwoLinkedList(Node *&head1, Node *&head2)
{
    Node *a = head1;
    Node *b = head2;

    while (a->next != NULL && b->next != NULL)
    {
        // when length will be same
        if (a == b)
        {
            return a;
        }
        // when length will be different
        a = a->next;
        b = b->next;
    }

    if(a->next == NULL && b->next == NULL && a!=b){
        cout<<0;
    }

    // Suppose b is bigger then a or equal
    if (a->next == NULL)
    {
        // We need to find how much bigger it is
        int blen = 0;
        while (b->next != NULL)
        {
            blen++;
            b = b->next;
        }

        while (blen--)
        {
            head2 = head2->next; // agar b badi hai to difference of a and b times b ko aage badado
        }
    }

    // Suppose a is bigger then b or equal
    else   
    {
        // We need to find how much bigger it is
        int alen = 0;
        while (a->next != NULL)
        {
            alen++;
            a = a->next;
        }

        while (alen--)
        {
            head1 = head1->next; // agar a badi hai to difference of a and b times a ko aage badado
        }
    }

    while (head1 != head2)
    {
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
}



int main()
{
    Node *head1 = new Node(1);
    Node *second1 = new Node(2);
    Node *third1 = new Node(3);
    Node *fourth1 = new Node(4);
    Node *fifth1 = new Node(5);
    head1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = fifth1;
    fifth1->next = NULL;

    Node *head2 = new Node(5);
    Node *second2 = new Node(6);
    Node *third2 = new Node(7);
    Node *fourth2 = new Node(8);
    Node *fifth2 = new Node(9);
    Node *sixth2 = new Node(10);
    Node *seventh2 = new Node(11);
    Node *eight2 = new Node(12);

    head2->next = second2;
    second2->next = third2;
    third2->next = fourth2;
    fourth2->next = fifth2;
    fifth2->next = sixth2;
    sixth2->next = seventh2;
    seventh2->next = eight2;
    eight2->next = third1;
    third1->next = fourth1;
    fourth1->next = fifth1;
    fifth1->next = NULL;

    print(head1);
    print(head2);

    Node* ans = intersectionOfTwoLinkedList(head1, head2);

    cout<<ans->data;

    return 0;
}
