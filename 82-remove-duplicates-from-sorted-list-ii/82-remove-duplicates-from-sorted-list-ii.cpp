/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head ; 
        ListNode* curr = head ;
        ListNode* anshead = NULL ;
        ListNode* tail = NULL ;
        while(curr){
            if(curr->next && curr->val != curr->next->val){
                ListNode* newnode = new ListNode(curr->val);
                if(anshead == NULL){
                    anshead = newnode;
                    tail = newnode;
                } else {
                    tail->next = newnode ;
                    tail = newnode;
                }
                curr = curr->next;
            }
            else if(curr->next){
                int ele = curr->val ;
                while(curr && curr->val == ele) curr = curr->next;
            } else {
                ListNode* newnode = new ListNode(curr->val);
                if(anshead == NULL){
                    anshead = newnode;
                    tail = newnode;
                } else {
                    tail->next = newnode ;
                    tail = newnode;
                }
                return anshead;
            }
        }
        return anshead;
    }
};