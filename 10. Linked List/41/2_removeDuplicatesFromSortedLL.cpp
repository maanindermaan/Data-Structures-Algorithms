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

void removingDuplicates(Node* &head){
    if(head == NULL){
        cout<<"Empty List";
    }

    if(head->next == NULL){
        cout<<"Single node no duplicate";
    }

    Node* curr = head;

    while(curr != NULL){
        if((curr->next != NULL) && (curr->data == curr->next->data)){
            // equal
            Node* temp = curr->next;
            curr->next = curr->next->next;
            // delete node
            temp->next = NULL;
            delete temp;
        }
        else{
            // not equal
            curr = curr->next;
        }
    }
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(50);
    Node *seventh = new Node(50);
    Node *eight = new Node(60);
    Node *ninth = new Node(60);
    Node *tenth = new Node(60);

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

    removingDuplicates(head);
    cout << endl;
    cout << endl;

    print(head);


    cout << endl;
    cout << endl;

    return 0;
}
