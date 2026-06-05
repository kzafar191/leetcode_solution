// Last updated: 5/6/2026, 5:08:28 pm
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp=head;
        ListNode* slow=head;
        if(!head) return nullptr;
        else if(!head->next) return nullptr;
        while(temp->next->next && temp->next->next->next){
            temp=temp->next->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return head;

    }
};