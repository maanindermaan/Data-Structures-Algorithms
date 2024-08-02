#include<iostream>
using namespace std;
int main(){

return 0;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Appraoch 1
class Solution {
public:
    int findLength(ListNode *&head) {
        int len = 0;
        ListNode *temp = head;
        while (temp != NULL) {
            len++;
            temp = temp->next;
        }
        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        if (n == 0) {
            return head;
        }

        int len = findLength(head) - n - 1;

        if (findLength(head) == 1) {
            return NULL;
        }

        if (len < 0) {
            temp = temp->next;
            return temp;
        }

        while (len--) {
            temp = temp->next;
        }

        ListNode* deleteNode = temp->next;
        temp->next = deleteNode->next;
        deleteNode->next = NULL;
        delete deleteNode;

        return head;
    }
};




// Approach 2
class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;
        if (n == 0) {
            return head;
        }
       for(int i=0 ; i<n ; i++){
        fast = fast->next;
       }

       if(fast == NULL){
        return head->next;
       }

        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* deleteNode = slow->next;
        slow->next = deleteNode->next;   
        deleteNode->next = NULL;
        delete deleteNode;

        return head;
    }
};