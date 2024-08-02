// 1.
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

Node *mergeTwoSortedLinkedList(Node *&head1, Node *&head2)
{

    while (head1 == NULL)
    {
        return head2;
    }

    while (head2 == NULL)
    {
        return head1;
    }

    Node *ansHead = NULL;
    Node *ansTail = NULL;

    Node *temp1 = head1;
    Node *temp2 = head2;

    while ((temp1 != NULL) && (temp2 != NULL))
    {
        // Inserting temp1 data into ans Node
        Node *newNode = NULL;
        if (temp1->data < temp2->data)
        {
            newNode = new Node(temp1->data);
            if (ansHead == NULL)
            {
                // anshead at NULL
                ansHead = newNode;
                ansTail = newNode;
            }
            else
            {
                // anshead not at NULL
                ansTail->next = newNode;
                ansTail = newNode;
            }
            temp1 = temp1->next;
        }
        else
        {
            // Inserting temp2 data into ans Node
            newNode = new Node(temp2->data);
            if (ansHead == NULL)
            {
                // anshead at NULL
                ansHead = newNode;
                ansTail = newNode;
            }
            else
            {
                // anshead not at NULL
                ansTail->next = newNode;
                ansTail = newNode;
            }
            temp2 = temp2->next;
        }
    }

    // Ho sakta hai ki temp1 na null hoya ho
    while (temp1 != NULL)
    {
        Node *newNode = new Node(temp1->data);
        ansTail->next = newNode;
        ansTail = newNode;
        temp1 = temp1->next;
    }

    // Ho sakta hai ki temp2 na null hoya ho
    while (temp2 != NULL)
    {
        Node *newNode = new Node(temp2->data);
        ansTail->next = newNode;
        ansTail = newNode;
        temp2 = temp2->next;
    }

    return ansHead;
}

int main()
{
    Node *head1 = new Node(1);
    Node *second1 = new Node(3);
    Node *third1 = new Node(5);
    Node *fourth1 = new Node(7);
    Node *fifth1 = new Node(9);
    head1->next = second1;
    second1->next = third1;
    third1->next = fourth1;
    fourth1->next = fifth1;
    fifth1->next = NULL;

    Node *head2 = new Node(2);
    Node *second2 = new Node(4);
    Node *third2 = new Node(6);
    Node *fourth2 = new Node(8);
    Node *fifth2 = new Node(10);
    head2->next = second2;
    second2->next = third2;
    third2->next = fourth2;
    fourth2->next = fifth2;
    fifth2->next = NULL;

    print(head1);
    print(head2);

    Node *ans = mergeTwoSortedLinkedList(head1, head2);

    print(ans);

    return 0;
}

// // 2. Recursive Merge Code
// Node*  merge(Node* a , Node* b){
//     Node* ans = NULL;
//     if(a == NULL){
//         return b;
//     }

//     if(b == NULL){
//         return a;
//     }

//     if(a->data < b->data){
//         ans = a;
//         a->next = merge(a->next , b);
//     }
//     else{
//         ans = b;
//         b->next = merge(a , b->next);
//     }
//     return ans;
// }


// // 3.  ITERATAIVE MERGE CODE
// Node *merge(Node *left, Node *right)
// {
//     Node *ans = new Node(-1);
//     Node *mptr = ans;
//     if (left == NULL)
//     {
//         return right;
//     }

//     if (right == NULL)
//     {
//         return left;
//     }

//     while (left != NULL && right != NULL)
//     {

//         if (left->data <= right->data)
//         {
//             mptr->next = left;
//             mptr = left;
//             left = left->next;
//         }
//         else
//         {
//             mptr->next = right;
//             mptr = right;
//             right = right->next;
//         }
//     }

//     while(left!=NULL){
//         mptr->next = left;
//         mptr = left;
//         left = left->next;
//     }

//     // while(left!=NULL){
//     //     mptr->next = left;  // agar right kahtam hogi hai to isko daldo ek hi dalenge toh hum sabko access kar payenge
//     // }

//     while(right!=NULL){
//         mptr->next = right;
//         mptr = right;
//         right = right->next;
//     }
//     // while(right!=NULL){
//     //     mptr->next = right;  // agar left kahtam hogi hai to isko daldo ek hi dalenge toh hum sabko access kar payenge
//     // }

//     return ans;
// }