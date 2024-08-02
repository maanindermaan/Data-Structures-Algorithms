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

    ~Node()
    {
        // Write a destructor to delete a node
        cout << "Node with value " << this->data << " is deleted.";
    }
};

void insertAtHead(Node *&head, Node *&tail, int data)
{
    // Check for empty Linked List
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return; // if dont want to use return you can use if else
    }

    else
    {
        // Step 1 -> create a new node
        Node *newNode = new Node(data);

        // Step 2 -> connect with head node
        newNode->next = head;

        // Step 3 -> update head
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    // Check for empty Linked List
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        // return;
    }

    else
    {
        // Step 1 -> create a new node
        Node *newNode = new Node(data);

        // Step 2 -> connect with tail node
        tail->next = newNode;

        // step 3 -> update tail
        tail = newNode;
    }
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

void insertAtPosition(int data, int position, Node *&head, Node *&tail)
{
    // Checking if LL is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    // Inserting at position 0 or head
    if (position == 0)
    {
        insertAtHead(head, tail, data);
        return; // this is important
    }

    // Inserting at position last or tail
    int len = findLength(head);
    if (position >= len)
    {
        insertAtTail(head, tail, data);
        return; // this is important
    }

    // Step 1 -> Find the position of prev and curr pointer
    int i = 1;
    Node *prev = head;
    while (i < position)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;

    // Step 2 -> Create a new node
    Node *newNode = new Node(data);

    // Step 3 -> Point newNode's pointer to curr
    newNode->next = curr;

    // Step 4 -> Point prev's pointer to newNode
    prev->next = newNode;
}

void deleteNode(int position, Node *&head, Node *&tail)
{
    // LL is empty
    if (head == NULL)
    {
        cout << "Linked List is empty" << endl;
    }

    // 1) Checking for start Position
    if (position == 1)
    {
        // step 1 -> making a temp pointer to starting node
        Node *temp = head;

        // step 2 -> updating head
        head = head->next;

        // step 3 -> Poiting temp to NULL
        temp->next = NULL;

        // step 4 -> Deleting temp
        delete temp;
        return;
    }

    // 2) Checking for last position
    int len = findLength(head);
    if (position == len)
    {
        // step 1 -> Finding Previous
        int i = 1;
        Node *prev = head;
        while (i < position - 1)
        {
            prev = prev->next;
            i++;
        }

        // step 2 ->
        Node *temp = tail;

        // step 3 ->
        prev->next = NULL;

        // step 4 ->
        tail = prev;

        // step 5 ->
        delete temp;
        return;
    }

    // 3) Deleting Middle Nodes
    // step 1 -> find prev and curr Nodes
    int i = 1;
    Node *prev = head;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;

    // step 2 ->
    prev->next = curr->next;

    // step 3 ->
    curr->next = NULL;

    // step 4 ->
    delete curr;
}

void print(Node *&head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next; // pointer aage badadia
    }
}







Node* reverse(Node* &prevNode , Node* &currNode){
    // Base Case
    if(currNode == NULL){
        // LL has been reversed 
        return prevNode;
    }

    // 1 case solve krlo baaki recursion dekh lega
    Node* nextNode = currNode->next;
    currNode->next = prevNode;

    // return reverse(prevNode->next , currNode->next);
    return reverse(currNode , nextNode); // -> Correct
}


Node* reverseUsingLoop1(Node* &prevNode , Node* &currNode){
    while(currNode != NULL){
        Node* nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode; 
        currNode = nextNode;
    }
    return prevNode;
}

//  if you dont want to make prevnode and curr node Null and head everytime in main you should do this code
Node* reverseUsingLoop2(Node* &head){
    Node *prevNode = NULL;
    Node *currNode = head;
    
    while(currNode != NULL){
        Node* nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode; 
        currNode = nextNode;
    }
    return prevNode;
}




int main()
{
    // Node* head = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    insertAtTail(head, tail, 60);
    cout << endl;
    print(head);
    cout << endl;
    cout << endl;

    cout << "Linked List after reversing : " << endl;
    cout << endl;

    Node *prevNode = NULL;
    Node *currNode = head;

    head = reverse(prevNode, currNode);
    print(head);


    cout << endl;

    
    cout << "Linked List after reversing using loop 1 : " << endl;
    cout << endl;
    prevNode = NULL;
    currNode = head;

    head = reverseUsingLoop1(prevNode, currNode);
    print(head);
    cout << endl;


    cout << "Linked List after reversing using loop 2 : " << endl;
    cout << endl;
    head = reverseUsingLoop2(head);
    print(head);
    cout << endl;
    
    return 0;
}