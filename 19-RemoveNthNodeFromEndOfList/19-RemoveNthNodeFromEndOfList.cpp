// Last updated: 5/6/2026, 5:11:03 pm
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        
        for(int i=0;i<n;++i) temp=temp->next;
        if(!temp) return head->next;
        if(!head->next) return nullptr;
        ListNode* point=head;
        while(temp->next){
            temp=temp->next;
            point=point->next;
        }
        point->next=point->next->next;
        return head;
    }
};