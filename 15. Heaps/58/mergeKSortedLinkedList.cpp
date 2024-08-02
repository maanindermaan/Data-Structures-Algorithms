// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

// class compare {
//     public:
//     bool operator()(ListNode* a, ListNode* b) {
//         return a->val > b->val;
//     }
// };
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {

//        1. PQ banalo

//         priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

//        2. Ek baari check krlo ki kya k empty to ni hai agar hai to NULL return krke vaapis aajao

//         int k = lists.size();
//         if(k == 0)
//             return NULL;

//        3. first element of every linked list ko insert krdo heap me

//         for(int i=0; i<k; i++) {
//             if(lists[i] != NULL ) {
//                 minHeap.push(lists[i]);
//             }
//         }

//        4. List ke head(start) or tail(end) banalo 

//         ListNode* head = NULL;
//         ListNode* tail = NULL;

//         while(!minHeap.empty()) {

//        5. Top element nikal lo

//             ListNode* temp = minHeap.top();
//             minHeap.pop();

//         6. temp may or may not be the first element of answer linked list
//            Agar head NULL hai matlab temp pehla element hai Linked List ka

//             if(head == NULL) {
//                 //temp -> first element of ans LL
//                 head = temp;
//                 tail = temp;

//         7. Agar temp ka next NULL nahi hai toh usse Daldo like minhead mein jo hum karte hai 
//                 if(tail->next != NULL) {
//                     minHeap.push(tail->next);
//                 }
//             }

//         8. Temp jo tha vo first element nahi tha ab kya karen

//             else {
//                 //temp isnnot the first element of LL
//                 tail->next = temp;
//                 tail = temp;

//         9. Agar temp ka next NULL nahi hai toh usse Daldo like minhead mein jo hum karte hai 

//                 if(tail->next != NULL) {
//                     minHeap.push(tail->next);
//                 }
//             }
//         }

//         10. Linked List ka head return krdo

//     return head;
//     }
// };




// MYSELF
#include<iostream>
#include<queue>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;

    ListNode(int val , ListNode* next){
        this->val = val;
        this->next = NULL;
    }
};

class compare {
    public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , compare > minHeap;

        int k = lists.size();
        if(k==0){
            return NULL;
        }

        for(int i=0 ; i<k ; i++){
            if(lists[i] != NULL){
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!minHeap.empty()){

            ListNode* temp = minHeap.top();
            minHeap.pop();

            if(head == NULL){
                // temp is the first element
                head = temp;
                tail = temp;
                if(temp->next!=NULL){
                    minHeap.push(temp->next);
                }
            }
            else{
                // temp is not the first element
                tail->next = temp;
                tail = temp;
                if(temp->next!=NULL){
                    minHeap.push(temp->next);
                }
            }
        }
        return head;
    }
};



int main(){

return 0;
}