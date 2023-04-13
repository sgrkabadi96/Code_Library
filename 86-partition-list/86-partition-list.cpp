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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lh = NULL , *lt=NULL;
        ListNode* gt = NULL, *gh = NULL ;
        
        while(head!=NULL){
            if(head->val < x){
                ListNode* n = new ListNode(head->val);
                if(lh == NULL) {
                    lh = n ;
                    lt = lh;
                } else {
                    lt ->next = n;
                    lt = n;
                }
            } else {
                ListNode* n = new ListNode(head->val);
                if(gh == NULL) {
                    gh = n ;
                    gt =gh;
                } else {
                    gt ->next = n;
                    gt = n;
                }
            }
            head = head->next;
        }
        
        if(lh){
            lt->next = gh;
            return lh;
        } else {
           return gh;
        }
        return NULL;
        
    }
};