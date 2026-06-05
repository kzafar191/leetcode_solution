// Last updated: 5/6/2026, 5:10:07 pm
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

    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr) return head2;
        if (head2 == nullptr) return head1;

        ListNode* add = nullptr;

        if (head1->val > head2->val) {
            add = head2;
            add->next = merge(head1, head2->next);
        } else {
            add = head1;
            add->next = merge(head1->next, head2);
        }
        return add;
    }

    ListNode* mergesort(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* mid = midd(head);
        ListNode* midnext = mid->next;
        mid->next = nullptr;

        ListNode* left = mergesort(head);
        ListNode* right = mergesort(midnext);

        return merge(left, right);
    }

    ListNode* midd(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};
