#include <unordered_map>
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

// slow and fast pointner method
bool checkForLoop(Node *&head)
{
    if (head == NULL)
    {
        cout << "No loop";
        return false;
    }

    Node *slow = head;
    Node *fast = head;

    // while(slow != NULL && fast !=NULL){
    //     fast = fast->next;
    //     if(fast != NULL){
    //         fast = fast->next;
    //         slow = slow->next;
    //         if(fast->data == slow->data){
    //             return true;
    //         }
    //     }
    // }

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        if (fast->data == slow->data)
        {
            return true;
        }
    }
    // fast Null hogya
    return false;
}

// 2. Using map method
bool checkForLoop(Node *&head , unordered_map<Node* , bool>& map)
{
    Node* temp = head;
    // mark true first
    while(temp != NULL){
        if(map.find(temp) != map.end()){
            return true;
        }
        else{
            map[temp] = true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);
    Node *seventh = new Node(70);
    Node *eight = new Node(80);
    Node *ninth = new Node(90);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;
    eight->next = ninth;
    ninth->next = fifth;

    bool ans = checkForLoop(head);

    cout << endl;
    cout << endl;

    cout << ans;
    // print(head);

    cout << endl;
    cout << endl;
    return 0;
}
