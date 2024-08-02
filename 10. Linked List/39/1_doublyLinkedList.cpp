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

int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    // If Linked List is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    else
    {
        // step 1 -> Create a new Node
        Node *newNode = new Node(data);

        // step 2 ->
        newNode->next = head;

        // step 3 ->
        head->prev = newNode;

        // step 4 ->
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    // If Linked List is empty
    if (tail == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    else
    {
        // step 1 -> Create a new Node
        Node *newNode = new Node(data);

        // step 2 ->
        tail->next = newNode;

        // step 3 ->
        newNode->prev = tail;

        // step 4 ->
        tail = newNode;
    }
}

void insertAtPosition(int data, int position, Node *&head, Node *&tail)
{
    // 1) If Linked list is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    else
    {
        // 2) Inserting at head position
        if (position == 1)
        {
            insertAtHead(head, tail, data);
            return;
        }

        // 3) Inserting at tail position
        int len = getLength(head);
        if (position > len) // because length intially 5 hi thi lekin jab insert at position call kiya toh length obviosly badgyi
        {
            insertAtTail(head, tail, data);
            return;
        }

        // 4) Inserting at middle left positions
        // step 1 -> Find prev and curr pointers
        int i = 1;
        Node *prevNode = head;
        while (i < position - 1)
        {
            prevNode = prevNode->next;
            i++;
        }
        Node *curr = prevNode->next;

        // step 2 -> Create a new node
        Node *newNode = new Node(data);

        // step 3 ->
        prevNode->next = newNode;
        newNode->prev = prevNode;

        // step 4 ->
        curr->prev = newNode;
        newNode->next = curr;
    }
}


void deleteFromPosition(Node* &head , Node* &tail , int position){
    // 1)Empty List
    if(head == NULL){
        cout<<"Linked list is empty"<<endl;
        return;
    }

    // 2) Single Node
    if(head->next == NULL){
        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;
    }

    // 3) Deleting from 1st or Head Position
    if(position == 1){
        // step 1 -> 
        Node* temp = head;

        // step 2 ->
        head = head->next;

        // step 3 ->
        head->prev = NULL;

        // step 4 ->
        temp->next = NULL;

        // step 5 ->
        delete temp;
        return;
    }

    // 4) Deleting from Last or Tail Position
    int len = getLength(head);

    if(position>len){
        cout<<"Enter a valid position ";
        return;
    }

    if(position == len){
        // step 1 ->
        Node* temp = tail;

        // step 2 ->
        tail = tail->prev;

        // step 3 ->
        tail->next = NULL; // order doesnot matter here

        // step 4 ->
        temp->prev = NULL;

        // step 5 ->
        delete temp;
        return;    
    }

    // 5) Deleting from Middle Position
    // step 1 -> Find left , curr and right pointers
    int i = 1;
    Node* left = head;
    while(i<position-1){
        left = left->next;
        i++;
    }
    Node* curr = left->next;
    Node* right = curr->next;

    // step 2 ->
    left->next = right;

    // step 3 ->
    right->prev = left;

    // step 3 ->
    curr->next = NULL;

    // step 4 ->
    curr->prev = NULL;

    // step 5 ->
    delete curr;
}



int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    Node *head = first;
    Node *tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    // print(first);
    cout << endl;
    // cout << "Head : " << head->data << endl;
    // cout << "Tail : " << tail->data << endl;
    cout << endl;

    insertAtHead(head, tail, 101);
    // print(head);
    // cout << endl;
    // cout << "Head : " << head->data << endl;
    // cout << "Tail : " << tail->data << endl;
    // cout << endl;

    insertAtTail(head, tail, 202);
    // print(head);
    // cout << endl;
    // cout << "Head : " << head->data << endl;
    // cout << "Tail : " << tail->data << endl;
    // cout << endl;

    insertAtPosition(99, 6, head, tail);
    print(head);
    cout << endl;
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    cout << endl;
    cout << endl;

    cout<<"Applyling deleting : "<<endl;
    deleteFromPosition(head , tail , 6);
    print(head);
    cout << endl;
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    cout << endl;
    cout << endl;
    return 0;
}