// 1. 

#include<iostream>
using namespace std;
int main(){

return 0;
}
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; 

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* prevNode = NULL;
        Node* currNode = *head_ref;
        Node* nextNode = NULL;
        
        // Correct the condition order in the first while loop
        while(currNode != NULL && currNode->data == x) {
            Node* temp = currNode;
            currNode = currNode->next;
            free(temp);
        }
        
        // Update head_ref to the new head
        *head_ref = currNode;

        // If all nodes were the target value, the new head will be NULL
        if (currNode == NULL) return;

        nextNode = currNode->next;

        // Traverse the list and delete nodes with value x
        while(currNode != NULL) {
            if(currNode->data == x) {
                // Unlink the node to be deleted
                prevNode->next = nextNode;
                if (nextNode != NULL) {
                    nextNode->prev = prevNode;
                }

                // Free the memory occupied by the node to be deleted
                Node* temp = currNode;
                currNode = nextNode;
                if (nextNode != NULL) nextNode = nextNode->next;
                free(temp);
            } else {
                // Move to the next node if no deletion occurs
                prevNode = currNode;
                currNode = nextNode;
                if (nextNode != NULL) nextNode = nextNode->next;
            }
        }
    }
};




// 2.
class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) {
        Node* temp = *head_ref;
        while(temp != NULL){
            if(temp->data == x){
                if(temp == *head_ref){
                    *head_ref = temp->next;
                }
                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;
                
                if(nextNode != NULL) nextNode->prev = prevNode;
                if(prevNode != NULL) prevNode->next = nextNode;
                
                free(temp);
                temp = nextNode;
            }
            else{
                temp = temp->next;
            }
        }
    }
};