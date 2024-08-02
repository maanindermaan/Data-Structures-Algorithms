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


// Approach 1:
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }   

        ListNode* temp1 = head;
        ListNode* temp2 = head->next;
        ListNode* head2 = temp2;

        // Kyunki temp1 temp2pe dependent hai or agar temp2 ka next ul hogya which means ki temp1 -> next->next is NULL and we can't access that into temp1->next, we can't reference to NULL ptr
        while(temp1 != NULL && temp2 != NULL && temp2->next != NULL){
            temp1->next = temp1->next->next;
            temp2->next = temp2->next->next;

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        temp1->next = head2;
        return head;
    }
};
