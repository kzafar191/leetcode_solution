// Last updated: 5/6/2026, 5:10:59 pm
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        int n = 0;

        while(temp){
            n++;
            temp=temp->next;
        }
        ListNode *prev = nullptr;
        ListNode *curr = head;
        ListNode *nextnode = nullptr;
        ListNode *newhead=nullptr;
        ListNode *chead=nullptr;
        for(int i = n/k ; i>0;i--){
            chead=prev;
            prev=nullptr;
            for(int j = k ; j>0 ; j--){
                nextnode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextnode;
            }
            if(i == n/k) newhead = prev;
            if(chead)chead->next=prev;
            while(prev->next!=nullptr){
                prev = prev->next;
            }
            if(i==1) prev->next = curr;
        }
        return newhead;

    }
};