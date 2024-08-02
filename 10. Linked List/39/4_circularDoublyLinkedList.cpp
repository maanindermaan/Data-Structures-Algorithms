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

void print(Node *&tail)
{
    Node *temp = tail;

    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != tail);

}

void insertAtValue(int element , int data , Node* &tail){
    // empty list
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    // Non empty list
    else{
        Node* curr = tail;

        while(curr->data != element){
            curr = curr->next;
        }

        // Now current is at element position 
        Node* forward = curr->next;
        Node* temp = new Node(data);

        curr->next = temp; 
        temp->prev = curr; 

        temp->next = forward;
        forward->prev = temp;
    }
}


void deleteNode(Node* &tail , int element){
    // empty list
    if(tail == NULL){
        cout<<"ERROR 404"<<endl;
    }
    // Non empty list
    else{
        Node* backward = tail;
        Node* curr = backward -> next;

        while(curr->data != element){
            backward = curr;
            curr = curr->next;
        }

        Node* forward = curr->next;

        backward->next = forward; 
        forward->prev = backward;

        if(curr == tail){
            tail = forward;
        }

        curr->prev = NULL;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    Node* tail = NULL;

    insertAtValue(10 , 1 , tail);
    insertAtValue(1 , 4 , tail);
    insertAtValue(4 , 6 , tail);
    insertAtValue(1 , 2 , tail);
    insertAtValue(2 , 3 , tail);
    insertAtValue(4 , 5 , tail);
    insertAtValue(6 , 10 , tail);
    insertAtValue(6 , 7 , tail);
    insertAtValue(7 , 8 , tail);
    insertAtValue(8 , 9 , tail);
    print(tail);


    cout<<endl;
    cout<<endl;
    cout<<endl;

    deleteNode(tail , 1);
    print(tail);
    return 0;
}