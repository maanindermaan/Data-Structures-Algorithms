
// Approach 1 working fine but TLE coming out

#include<iostream>
using namespace std;
int main(){

return 0;
}

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

class Solution
{
public:

    Node * removeDuplicates(struct Node *head)
    {
        if(head == NULL || head->next == NULL){
            return head;
        }
        Node* prevNode = NULL;
        Node* currNode = head;
        Node* nextNode = head->next;
        
        while(currNode->data == nextNode->data){
            Node* temp = currNode;
            currNode = nextNode;
            nextNode = nextNode->next;
            delete temp;
        }
        
        head = currNode;
        
        while(nextNode != NULL){
            // initial remove 
            prevNode = currNode->prev;
            if(currNode->data == nextNode->data){
                if(prevNode != NULL){
                    prevNode->next = nextNode;
                }
                if(nextNode != NULL){
                    nextNode->prev = prevNode;
                }
                free(currNode);
                currNode = nextNode;
                if(nextNode != NULL){
                    nextNode = nextNode->next;
                }
            }
            else{
                prevNode = currNode;
                currNode = nextNode;
                if(nextNode != NULL){
                    nextNode = nextNode->next;
                }
            }
        }
        return head;
    }
};






// Approach 2
Node * removeDuplicates(Node *head)
{
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* temp = head;

    while(temp != NULL && temp->next != NULL){
        Node* nextNode = temp->next;
        while(nextNode != NULL && temp->data == nextNode->data){
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        temp->next = nextNode;
        if(nextNode != NULL) nextNode->prev = temp;

        temp = temp->next;
    }
    return head;
}