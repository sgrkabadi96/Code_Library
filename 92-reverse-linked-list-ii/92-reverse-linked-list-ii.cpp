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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left == right ) return head ;
        
        ListNode* curr = head ;
        ListNode* tail = NULL;
        int l = left;
        while(left > 1){
            tail= curr;
            curr = curr->next; left--;
        }
       
        int num = right - l ;
        ListNode* prev = NULL , *next = NULL ;
        ListNode* reveredListTail = NULL;
        
        while(num >= 0){
            if(reveredListTail == NULL) reveredListTail = curr;
            next = curr->next ;
            curr->next = prev ;
            prev = curr;
            curr = next;
            num--;
        }
        
        if(tail) tail->next = prev ;
        else if(tail == NULL) head = prev ;
        reveredListTail->next = curr;
        
        return head;
    }
};