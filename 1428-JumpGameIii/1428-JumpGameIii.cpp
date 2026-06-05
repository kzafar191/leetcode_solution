// Last updated: 5/6/2026, 5:09:03 pm
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> vis(n,false);

        queue<int> que;
        que.push(start);
        while(!que.empty()){
            int node = que.front();
            que.pop();
            vis[node] = true;
            if(arr[node]==0) return true;
            if(node+arr[node]<n && vis[node+arr[node]]==false) que.push(node+arr[node]);
            if(node-arr[node]>=0 && vis[node-arr[node]]==false) que.push(node-arr[node]);
        }
        return false;
    }
};