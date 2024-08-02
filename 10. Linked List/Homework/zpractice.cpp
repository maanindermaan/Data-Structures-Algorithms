#include <iostream>
#include <vector>
#include <algorithm>
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

int miniHelper(vector<int>indexArray){
    int mini = INT_MAX;
    for(int i=1 ; i<indexArray.size() ; i++){
        mini = min(mini , indexArray[i] - indexArray[i-1]);
    }
    return mini;
}

vector<int> minimumAndMaximumNodesBetweenCriticalPoints(Node *&head)
{
    vector<int>indexArray;
    Node* prev = NULL;
    Node* curr = head;

    int index = 0;
    while(curr->next != NULL){
        if(prev != NULL){
            if((prev->data < curr->data && curr->data > curr->next->data) || (prev->data > curr->data && curr->data < curr->next->data)){
                indexArray.push_back(index);
            }
        }
        prev = curr;
        curr = curr->next;
        index++;
    }

    int mini = miniHelper(indexArray);
    int maxi = indexArray[indexArray.size()-1] - indexArray[0];

    vector<int>ans;
    ans.push_back(mini);
    ans.push_back(maxi);

    return ans;
}

int main()
{
    Node *head = new Node(5);
    Node *second = new Node(3);
    Node *third = new Node(1);
    Node *fourth = new Node(2);
    Node *fifth = new Node(5);
    Node *sixth = new Node(1);
    Node *seventh = new Node(2);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = NULL;

    vector<int> ans = minimumAndMaximumNodesBetweenCriticalPoints(head);

    for(int i=0 ; i < ans.size() ; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
