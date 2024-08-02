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

    ~Node(){
        // Write a destructor to delete a node
        cout<<"Node with value "<<this->data<<" is deleted.";
    }
};



void insertAtValue(int element , int data , Node* &tail){


    // if LL is empty
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;
        // tail->next = tail;
    }

    else{

        // Assuming element is represent in the list
        // Non empty list
        Node* curr = tail;

        while(curr->data != element){
            curr = curr->next;    
        }
        // element found now curr is representing element wala node
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;

    }

}



void print(Node* &tail){
    Node* temp = tail;
    // cout<<tail->data<<" ";
    // while(tail->next != temp){
    //     cout<<tail->data<<" ";
    //     tail = tail->next;
    // }

    do
    {
        cout<<tail->data<<" ";
        tail = tail->next;
    } while(tail != temp);
    
}


void deleteNode(Node* &tail , int element){
    // List is empty
    if(tail == NULL){
        cout<<"List is empty"<<endl;
    }

    // Non empty List
    else{
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != element){
            prev = curr;
            curr = curr->next;
        }

        prev -> next = curr -> next;
        if(tail == curr){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}






int main(){
    Node* tail = NULL;

    insertAtValue(6,10,tail);
    print(tail);

    cout<<endl;
    cout<<endl;

    insertAtValue(10,11,tail);
    print(tail);

    cout<<endl;
    cout<<endl;

    insertAtValue(11,12,tail);
    print(tail);

    cout<<endl;
    cout<<endl;

    insertAtValue(10,111,tail);
    print(tail);

    cout<<endl;
    cout<<endl;
    deleteNode(tail , 10);
    cout<<endl;
    deleteNode(tail , 11);
    cout<<endl;
    deleteNode(tail , 12);
    cout<<endl;
    cout<<endl;
    print(tail);
    cout<<endl;
    cout<<endl;

return 0;
}