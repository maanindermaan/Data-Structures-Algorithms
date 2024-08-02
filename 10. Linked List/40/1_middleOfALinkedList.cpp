// ************** MIDDLE OF A LINKED LIST *****************
// ************** USING MIDDLE METHOD *****************
// #include <iostream>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* next;

//     Node() {
//         this->data = 0;
//         this->next = NULL;
//     }

//     Node(int data) {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// int findLength(Node* head) {
//     int len = 0;
//     Node* temp = head;
//     while (temp != NULL) {
//         len++;
//         temp = temp->next;
//     }
//     return len;
// }

// void findMiddle(Node* head) {
//     if (head == NULL) {
//         cout << "Linked list is empty." << endl;
//         return;
//     }

//     int len = findLength(head);
//     Node* temp = head;

//     if(len%2 == 0){
//         // even node
//         int count = 1;
//         while(count < len/2){
//             temp = temp->next;
//             count++;
//         }
//     }
//     else{
//         // odd node
//         int count = 1;
//         while(count<(len/2 + 1)){
//             temp = temp->next;
//             count++;
//         }
//     }

//     cout << "The middle node is: " << temp->data << endl;
// }


// // void findMiddle(Node* head) {
// //     // base case
// //     if(head == NULL){
// //         cout<<"BHAKK BKL"<<endl;
// //         return;
// //     }

// //     int len = findLength(head);

// //     int traversal = (len%2 == 0) ? len/2 : len/2+1;

// //     int i = 1;

// //     Node* temp = head;

// //     while(i < traversal){
// //         temp = temp->next;
// //         i++;
// //     }

// //     cout<<"The middle node is : "<<endl;
// //     cout<<temp->data<<endl;
// // }


// int main() {
//     Node* head = new Node(10);
//     Node* first = new Node(20);
//     Node* second = new Node(30);
//     Node* third = new Node(40);
//     Node* fourth = new Node(50);
//     Node* fifth = new Node(60);

//     head->next = first;
//     first->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;
//     fifth->next = NULL;


//     findMiddle(head);
//     return 0;
// }




















// ************** MIDDLE OF A LINKED LIST *****************
// ************** SLOW AND FAST POINTER APPOROACH *********
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

void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl; 
}


Node* getMiddle(Node* &head){
    if(head == NULL){
        cout<<"Empty";
        return head;
    }

    if(head->next == NULL){
        // Only one node in LL
        return head;
    }

    // LL have more than 1 node
    Node* slow = head;
    Node* fast = head->next;
    
    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    
    head->next = second;
    second->next = third;
    third->next  = fourth; 
    fourth->next = fifth;
    fifth->next = sixth;

    print(head);  

    cout<<"Middle node is "<< getMiddle(head) -> data<<endl;
    return 0;
}