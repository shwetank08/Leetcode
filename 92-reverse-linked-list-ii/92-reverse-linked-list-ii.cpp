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
        ListNode dummy(-1,head);
        ListNode*prev = &dummy;
    
        for(int i=0;i<left-1;i++){
            prev = prev->next;
        }
        
        ListNode*cur = prev->next;
        while(left<right){
            ListNode*N = cur->next;
            cur->next = N->next;
            N->next = prev->next;
            prev->next = N;
            left++;
        }
        return dummy.next;
    }
};