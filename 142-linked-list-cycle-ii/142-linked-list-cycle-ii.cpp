/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        int pos = 0 ;
        map<ListNode*, int> map ;
        
        while(head ){
            if(map.find(head) != map.end()){
                return head;
            }
            map[head] = pos;
            head = head->next;
            pos++;
        }
        
        return NULL;
    }
};