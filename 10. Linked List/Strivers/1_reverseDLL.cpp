#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
        cout<<"Node with value "<<this->data<<" is deleted"<<endl;
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
}

Node* reverse(Node* &head){
    Node* prevNode = NULL;
    Node* currNode = head;
    Node* nextNode = NULL;

    while(currNode != NULL){
        nextNode = currNode->next;

        currNode->next = prevNode;
        currNode->prev = nextNode;

        prevNode = currNode;
        currNode = nextNode;
    }

    head = prevNode;

    return head;
}



int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    fourth->next = fifth;
    fifth->prev = fourth;
    
    cout<<endl;
    cout<<"BEFORE REVERSE : ";
    print(head);
    cout<<endl;


    reverse(head);
    cout<<endl;
    cout<<"AFTER REVERSE  : ";
    print(head);
    cout<<endl;
    cout<<endl;
    return 0;
}