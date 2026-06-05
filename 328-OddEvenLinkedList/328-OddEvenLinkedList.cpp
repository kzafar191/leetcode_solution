// Last updated: 5/6/2026, 5:09:40 pm
class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if(!head) return head;
		ListNode* odd=head;
		ListNode* even=head->next;
		ListNode* evenHead=even;
		while(even && even->next){
			odd->next=even->next;
			odd=odd->next;
			even->next=odd->next;
			even=even->next;
		}
		odd->next=evenHead;
		return head;
	}
};
