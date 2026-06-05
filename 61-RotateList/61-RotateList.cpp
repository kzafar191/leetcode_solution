// Last updated: 5/6/2026, 5:10:40 pm
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return nullptr;
        ListNode* temp=head;
        ListNode* tail;
        int num=0;
        while(temp){
            tail=temp;
            temp=temp->next;
            num++;
        }
        k=k%num;
        tail->next=head;
        temp=head;
        for(int i=0;i<(num-k-1);++i){
            temp=temp->next;
        }
        tail=temp->next;
        temp->next=nullptr;
        return tail;
    }
};