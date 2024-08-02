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

Node *sortZeroOneTwo(Node *&head)
{
    if (head == NULL)
    {
        cout << "Empty List";
        return NULL;
    }

    if (head->next == NULL)
    {
        cout << "Single element";
        return head;
    }

    // step 1 : Creating Dummy Nodes and their pointers
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    // step 2 : traverse orignal Linked List
    Node *curr = head;

    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            // Take out zero wali node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // Append zero wali node to zeroHead list
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (curr->data == 1)
        {
            // Take out one wali node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // Append one wali node to zeroHead list
            oneTail->next = temp;
            oneTail = temp;
        }
        else if (curr->data == 2)
        {
            // Take out two wali node
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            // Append two wali node to zeroHead list
            twoTail->next = temp;
            twoTail = temp;
        }
    }
    //  Ab yha par Zero one two teeno LL ready hai

    // Step 3 : Join them

    // step A : Modify 1 wali list
    Node *temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    // step B : Modify 2 wali list
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    // Step C : Join 0 , 1 and 2
    if (oneHead != NULL)
    {
        zeroTail->next = oneHead;
        if (twoHead != NULL)
        {
            oneTail->next = twoHead;
        }
    }
    else
    {
        // 1 is absent
        // checking for 2
        if (twoHead != NULL)
        {
            zeroTail->next = twoHead;
        }
    }

    // Step D : Deleting zeoHead
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    // step 4 : Return head
    return zeroHead;
}

int main()
{
    Node *head = new Node(2);
    Node *second = new Node(1);
    Node *third = new Node(1);
    Node *fourth = new Node(2);
    Node *fifth = new Node(0);
    Node *sixth = new Node(0);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    cout << endl;
    cout << endl;

    print(head);

    cout << endl;
    cout << endl;

    Node *ans = sortZeroOneTwo(head);

    print(ans);

    cout << endl;
    cout << endl;

    return 0;
}
