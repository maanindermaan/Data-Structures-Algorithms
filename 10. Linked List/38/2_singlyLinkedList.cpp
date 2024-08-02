#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// i want to insert a node right at the head of linked list
// Passing head by reference (&) helps to make changes in orignal linked list
void insertAtHead(Node* &head , Node* &tail , int data){ 
    // Step 1 -> create a new node
    Node* newNode = new Node(data);

    // Step 2 -> 
    newNode->next = head;

    // Step 3 -> 
    // first node
    if(head == NULL){
        // -> empty list , first node ab add hogi
        tail = newNode;
    }
    head = newNode;
}




// i want to insert a node right at the end of linked list
void insertAtTail(Node* &head , Node* &tail , int data){ 
    // Step 1 -> create a new node
    Node* newNode = new Node(data);

    // Step 2 -> connect with tail node
    if(tail->next == NULL){
        // first node ab add hone wali hai
        tail = newNode;
        head = newNode;
    }
    else{
        // LL is non empty 
        tail->next = newNode;
    }

    // step 3 -> update tail
    tail = newNode; 
}









void print(Node* &head){
        Node* temp = head;

        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next; // pointer aage badadia
        }
    }



int main(){
    // Node* head = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head , tail , 20);
    insertAtHead(head , tail , 30);
    insertAtHead(head , tail , 40);
    insertAtHead(head , tail , 50);

    insertAtTail(head , tail , 60);

    print(head);
return 0;
}