    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

// 1.
#include<iostream>
using namespace std;
int main(){

return 0;
}

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            delete head; 
            return NULL;
        }

        ListNode* slow = head; 
        ListNode* fast = head; 

        fast = fast->next->next;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};




// 2.
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            delete head; // Delete the single node if it exists
            return NULL;
        }

        ListNode* temp = NULL; // This will keep track of the node before the middle node
        ListNode* slow = head; // Slow pointer starts at the head
        ListNode* fast = head; // Fast pointer starts at the second node

        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                temp = slow;
                fast = fast->next; 
                slow = slow->next;
            }
        }

        temp->next = slow->next; // Skipping the middle node
        slow->next = NULL;
        delete slow; // Deleting the middle node

        return head;
    }
};
