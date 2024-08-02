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



// // Approach 1
// Node *mergedNodesInBetweenZeroes(Node *&head)
// {
//    Node* temp = head;

//    Node* newNode = new Node(0);
//    Node* result = newNode;

//    while(temp != NULL){
//     int sum = 0;
//     if(temp->data == 0){
//         temp = temp->next;
//     }
//     else{
//         while(temp->data != 0 && temp != NULL){
//             sum += temp->data;
//             temp = temp->next;
//         }
//         newNode->next = new Node(sum);
//         newNode = newNode->next;
//     }
//    }
//    return result->next;
// }



// Approach 2
// Node *mergedNodesInBetweenZeroes(Node *&head)
// {
//     if (head == NULL)
//     {
//         return 0;
//     }

//     Node *slow = head;
//     Node *fast = head->next;
//     Node *lastNode = NULL;
//     int sum = 0;
//     while (fast != NULL)
//     {
//         // check karo ki kya fast zero to ni hai
//         if (fast->data != 0)
//         {
//             sum = sum + fast->data;
//         }
//         else
//         {
//             // fast ki value 0 hogai
//             // iss case mein mujhe 2 consequtive zero or unke bech ka sum mil chuka hai ab inhe dalna hai bas slow wali jagah pe
//             slow->data = sum;
//             lastNode = slow;
//             slow = slow->next;
//             sum = 0; // for further calculations, agli nodes ke liye
//         }
//         fast = fast->next;
//     }

//     // Ab end mein last Node ko todlo
//     Node *temp = lastNode->next;
//     lastNode->next = NULL;

//     // Ab bachi hui saari ko delte kardo  deleting old list
//     while (temp != NULL)
//     {
//         Node *curr = temp->next;
//         delete temp;
//         temp = curr;
//     }

//     return head;
// }



// Approach 3
Node *mergedNodesInBetweenZeroes(Node *&head)
{
   Node* slow = head;
   Node* fast = head->next;

   Node* lastNode = NULL;
   int sum = 0;
   while(fast != NULL){
    if(fast->data == 0){
        slow->data = sum;
        fast = fast->next;
        lastNode = slow;
        slow = slow->next;
        sum = 0;
    }else{
        sum += fast->data;
        fast = fast->next;
    }
   }
   lastNode->next = NULL;

   return head;
}

int main()
{
    Node *head = new Node(0);
    Node *second = new Node(3);
    Node *third = new Node(1);
    Node *fourth = new Node(0);
    Node *fifth = new Node(4);
    Node *sixth = new Node(5);
    Node *seventh = new Node(5);
    Node *eight = new Node(2);
    Node *ninth = new Node(0);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;
    eight->next = ninth;
    ninth->next = NULL;

    Node *ans = mergedNodesInBetweenZeroes(head);

    print(ans);

    return 0;
}
