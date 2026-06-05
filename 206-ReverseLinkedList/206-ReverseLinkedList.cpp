// Last updated: 5/6/2026, 5:09:53 pm
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
    ListNode* reverseList(ListNode* head) {
        ListNode* temp=head;
        ListNode* prev=nullptr;
        ListNode* nx=nullptr;
        while(temp){
            nx=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nx;
        }
        return prev;
    }
};