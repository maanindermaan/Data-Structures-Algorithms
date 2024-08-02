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

Node *reverseLL(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = curr->next;

    while (curr != NULL)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev; // This is L.L. ka head
}

Node* solve(Node* &head1 , Node* &head2){

    while(head1 == NULL){
        return head2;
    }

    while(head2 == NULL){
        return head1;
    }
    // step 1 : Reverse both l inked list
    head1 = reverseLL(head1);
    head2 = reverseLL(head2);

    // step 2 : Add the linked list
    Node* ansHead = NULL;
    Node* ansTail = NULL;
    int carry = 0;

    while((head1 != NULL) && (head2!=NULL)){
        // calculate sum
        int sum = carry + head1->data + head2->data;
        // Find digit to create node
        int digit = sum%10;
        // calculate carry
        carry = sum/10;

        //  Create a new node for the digit;
        Node* newNode = new Node(digit); 
        // Attach this to ans wala Linked List
        if(ansHead == NULL){
            // First Node insert karo
            ansHead = newNode;
            ansTail = newNode;
        }
        else{
            ansTail->next = newNode;
            ansTail = newNode;
        }

        head1 = head1->next;
        head2 = head2->next;
    }
    // Suppose LL 1 LL 2 se zyada hai 
    while(head1 != NULL){
        int sum = carry + head1->data;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit); 
        ansTail -> next = newNode;
        ansTail = newNode; 
        head1 = head1->next;
    }

    // Suppose LL 2 LL 1 se zyada hai 
    while(head2 != NULL){
        int sum = carry + head2->data;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit); 
        ansTail -> next = newNode;
        ansTail = newNode; 
        head2 = head2->next;
    }

    // Carry abhi bbhi zero nahi hua toh eg 999+999 case
    while(carry != 0){
        int sum = carry;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit); 
        ansTail -> next = newNode;
        ansTail = newNode; 
    }

    // step 3 : Reverse ans wali Linked list
    Node* reversed = reverseLL(ansHead);
    return reversed;
}

int main()
{
    Node *head1 = new Node(9);
    Node *second1 = new Node(9);
    head1->next = second1;
    second1->next = NULL;

    Node *head2 = new Node(1);
    head2->next = NULL;

    Node* ans = solve(head1 , head2);

    print(ans);

    return 0;
}
