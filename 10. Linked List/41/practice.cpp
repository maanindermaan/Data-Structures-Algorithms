// // 1. Check palindrome
// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node()
//     {
//         this->data = 0;
//         this->next = NULL;
//     }

//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// Node *reverseLL(Node *&head)
// {
//     Node* prev = NULL;
//     Node* curr = head;
//     Node* forward = NULL;

//     while(curr != NULL){
//         forward = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = forward;
//     }
//     return prev;
// }

// bool isPalindrome(Node *&head)
// {
//     // find middle and then reverse it after the middle and then compare data one by one
//     if (head == NULL)
//     {
//         cout << "List is empty sorry";
//     }

//     if (head->next == NULL)
//     {
//         // Only one node
//         return true;
//     }
//     // using slow fast pointer approach
//     Node* slow = head;
//     Node* fast = head->next;

//     while(fast != NULL){
//         fast = fast->next;
//         if(fast != NULL){
//             fast = fast->next;
//             slow = slow->next;
//         }
//     }
//     // slow is at middle node now
//     Node* temp1 = head;
//     Node* temp2 = slow->next;

//     temp2 = reverseLL(temp2);

//     // now compare
//     while(temp2 != NULL){
//         if(temp1->data != temp2->data){
//             return false;
//         }
//         temp1 = temp1->next;
//         temp2 = temp2->next;
//     }
//     return true;
// }

// int main()
// {
//     Node *head = new Node(10);
//     Node *second = new Node(20);
//     Node *third = new Node(30);
//     Node *fourth = new Node(40);
//     Node *fifth = new Node(50);
//     Node *sixth = new Node(50);
//     Node *seventh = new Node(40);
//     Node *eight = new Node(30);
//     Node *ninth = new Node(20);
//     Node *tenth = new Node(10);

//     head->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;
//     fifth->next = sixth;
//     sixth->next = seventh;
//     seventh->next = eight;
//     eight->next = ninth;
//     ninth->next = tenth;
//     tenth->next = NULL;

//     cout << endl;
//     cout << endl;

//     if (isPalindrome(head))
//     {
//         cout << "Yes it is a palindrome";
//     }
//     else
//     {
//         cout << "Oops not a palindrome";
//     }

//     cout << endl;
//     cout << endl;

//     return 0;
// }

































































// 3. Remove Duplicates
// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node()
//     {
//         this->data = 0;
//         this->next = NULL;
//     }

//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void removeDuplicates(Node *&head)
// {
//     Node* curr = head;

//     while(curr != NULL){
//         Node* temp = curr;

//         while(temp->next != NULL){
//             if(temp->next->data == curr->data){
//                 Node* duplicate = temp->next;
//                 temp->next = temp->next->next;
//                 duplicate->next = NULL;
//                 delete duplicate;
//             }
//             else{
//                 temp = temp->next;
//             }
//         }
//         curr = curr->next;
//     }
// }

// int main()
// {
//     Node *head = new Node(4);
//     Node *second = new Node(2);
//     Node *third = new Node(1);
//     Node *fourth = new Node(4);
//     Node *fifth = new Node(2);
//     Node *sixth = new Node(7);
//     Node *seventh = new Node(2);
//     Node *eight = new Node(1);
//     Node *ninth = new Node(4);
//     Node *tenth = new Node(7);

//     head->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;
//     fifth->next = sixth;
//     sixth->next = seventh;
//     seventh->next = eight;
//     eight->next = ninth;
//     ninth->next = tenth;
//     tenth->next = NULL;

//     cout << endl;
//     cout << endl;

//     print(head);

//     removeDuplicates(head);
//     cout << endl;
//     cout << endl;

//     print(head);

//     cout << endl;
//     cout << endl;

//     return 0;
// }








// 4. Sort 0s 1s and 2s
// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node()
//     {
//         this->data = 0;
//         this->next = NULL;
//     }

//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void sortZeroOneTwo(Node* &head){
//     int zeroCount = 0;
//     int oneCount = 0;
//     int twoCount = 0;

//     // 1. Count 0s 1s 2s
//     Node* temp = head;
//     while(temp != NULL){
//         if(temp->data == 0){
//             zeroCount++;
//         }
//         else if(temp->data == 1){
//             oneCount++;
//         }
//         else{
//             twoCount++;
//         }
//         temp = temp->next;
//     }

//     // 2. Now traverse and Add
//     temp = head;
//     while(temp != NULL){
//         while(zeroCount--){
//             temp->data = 0;
//             temp = temp->next;
//         }
//         while(oneCount--){
//             temp->data = 1;
//             temp = temp->next;
//         }
//         while(twoCount--){
//             temp->data = 2;
//             temp = temp->next;
//         }
//     }
// }

// int main()
// {
//     Node *head = new Node(1);
//     Node *second = new Node(2);
//     Node *third = new Node(2);
//     Node *fourth = new Node(0);
//     Node *fifth = new Node(0);
//     Node *sixth = new Node(0);

//     head->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;
//     fifth->next = sixth;
//     sixth->next = NULL;

//     cout << endl;
//     cout << endl;

//     print(head);

//     cout << endl;
//     cout << endl;

//     sortZeroOneTwo(head);

//     print(head);

//     cout << endl;
//     cout << endl;

//     return 0;
// }



// 4.2
// ********************* APPROACH 1 ************************
// **************** Using Couting Approach *****************
// ******************* Data Replacement ********************
// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node()
//     {
//         this->data = 0;
//         this->next = NULL;
//     }

//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void sortZeroOneTwo(Node* &head){
//     // step 1 : find count of zero ones and twos
//     int zeroCount  = 0;
//     int oneCount  = 0;
//     int twoCount  = 0;

//     Node* temp = head;
//     while(temp!=NULL){
//         if(temp->data == 0){
//             zeroCount++;
//         }
//         else if(temp->data == 1){
//             oneCount++;
//         }
//         else if(temp->data == 2){
//             twoCount++;
//         }
//         temp = temp->next;
//     }

//     // Step 2 : Fill 0s 1s and 2s into the orignal Linked list
//     temp = head;
//     while(temp!=NULL){
//         // Filling zeros
//         while(zeroCount--){
//             temp->data = 0;
//             temp = temp->next;
//         }
//         // Filling ones
//         while(oneCount--){
//             temp->data = 1;
//             temp = temp->next;
//         }
//         // Filling twos
//         while(twoCount--){
//             temp->data = 2;
//             temp = temp->next;
//         }
//     }
// }

// int main()
// {
//     Node *head = new Node(1);
//     Node *second = new Node(2);
//     Node *third = new Node(2);
//     Node *fourth = new Node(0);
//     Node *fifth = new Node(0);
//     Node *sixth = new Node(0);

//     head->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;
//     fifth->next = sixth;
//     sixth->next = NULL;

//     cout << endl;
//     cout << endl;

//     print(head);

//     cout << endl;
//     cout << endl;

//     sortZeroOneTwo(head);

//     print(head);

//     cout << endl;
//     cout << endl;

//     return 0;
// }






// ********************* APPROACH 2 ************************
// ******************* Pyari Approach **********************
// ***************** Pointer Replacement *******************
// #include <iostream>
// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;

//     Node()
//     {
//         this->data = 0;
//         this->next = NULL;
//     }

//     Node(int data)
//     {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void print(Node *&head)
// {
//     Node *temp = head;
//     while (temp != NULL)
//     {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// Node *sortZeroOneTwo(Node *&head)
// {
//     if (head == NULL)
//     {
//         cout << "Empty List";
//         return NULL;
//     }

//     if (head->next == NULL)
//     {
//         cout << "Single element";
//         return head;
//     }

//     // step 1 : Creating Dummy Nodes and their pointers
//     Node* zeroHead = new Node(-1);
//     Node* zeroTail = zeroHead;

//     Node* oneHead = new Node(-1);
//     Node* oneTail = oneHead;

//     Node* twoHead = new Node(-1);
//     Node* twoTail = twoHead;

//     // step 2;
//     Node* curr = head;
//     while(curr != NULL){
//         if(curr->data == 0){
//             Node* temp = curr;
//             curr = curr -> next;
//             temp->next = NULL;

//             zeroTail->next = temp;
//             zeroTail = temp;
//         }

//         else if(curr->data == 1){
//             Node* temp = curr;
//             curr = curr -> next;
//             temp->next = NULL;

//             oneTail->next = temp;
//             oneTail = temp;
//         }

//         else if(curr->data == 2){
//             Node* temp = curr;
//             curr = curr -> next;
//             temp->next = NULL;

//             twoTail->next = temp;
//             twoTail = temp;
//         }
//     }

//     // step 3 attach and detach
//     Node* temp = oneHead;
//     oneHead = oneHead->next;
//     temp->next = NULL;
//     delete temp;

//     temp = twoHead;
//     twoHead = twoHead->next;
//     temp->next = NULL;
//     delete temp;

//     if(oneHead != NULL){
//         zeroTail->next = oneHead;
//         if(twoHead != NULL){
//             oneTail->next = twoHead;
//         }
//     }
//     else{
//         if (twoHead != NULL)
//         {
//             zeroTail->next = twoHead;
//         }
//     }

//     temp = zeroHead;
//     zeroHead = zeroHead->next;
//     temp->next = NULL;
//     delete temp;

//     return zeroHead;
// }

// int main()
// {
//     Node *head = new Node(2);
//     Node *second = new Node(1);
//     Node *third = new Node(1);
//     Node *fourth = new Node(2);
//     Node *fifth = new Node(0);
//     Node *sixth = new Node(0);

//     head->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;
//     fifth->next = sixth;
//     sixth->next = NULL;

//     cout << endl;
//     cout << endl;

//     print(head);

//     cout << endl;
//     cout << endl;

//     Node *ans = sortZeroOneTwo(head);

//     print(ans);

//     cout << endl;
//     cout << endl;

//     return 0;
// }


















// 5. Add Two Numbers
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

    while(head1 != NULL && head2 != NULL){
        int sum = carry + head1->data + head2->data;

        int digit = sum%10;

        carry = sum/10;

        Node* newNode =  new Node(digit);

        if(ansHead == NULL){
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

    while(carry != 0){
        int sum = carry;
        int digit = sum%10;
        carry = sum/10;
        Node* newNode = new Node(digit); 
        ansTail -> next = newNode;
        ansTail = newNode; 
    }

    return reverseLL(ansHead);
}


int main()
{
    Node *head1 = new Node(9);
    Node *second1 = new Node(9);
    Node *third1 = new Node(9);
    head1->next = second1;
    second1->next = third1;
    third1->next = NULL;

    Node *head2 = new Node(1);
    head2->next = NULL;

    print(head1);
    print(head2);

    Node* ans = solve(head1 , head2);

    print(ans);

    return 0;
}
