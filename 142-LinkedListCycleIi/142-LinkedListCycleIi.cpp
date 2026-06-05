// Last updated: 5/6/2026, 5:10:12 pm
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
        ListNode* temp=head;
        ListNode* fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            temp=temp->next;
            if(temp==fast){
                fast=head;
                while(fast!=temp){
                    fast=fast->next;
                    temp=temp->next;
                }
                return temp;
            }
        }
        if(fast) return fast->next;
        return fast;
    }
};