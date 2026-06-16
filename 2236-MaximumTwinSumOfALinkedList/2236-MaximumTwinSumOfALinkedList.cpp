// Last updated: 16/6/2026, 2:01:07 pm
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
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        stack<int> st;
        queue<int> q;

        while(temp!=nullptr){
            st.push(temp->val);
            q.push(temp->val);
            temp=temp->next;
        }

        int ans=INT_MIN;

        while(!q.empty()){
            int v = q.front()+st.top();
            ans = max(ans,v);
            q.pop();
            st.pop();
        }
        return ans;
    }
};