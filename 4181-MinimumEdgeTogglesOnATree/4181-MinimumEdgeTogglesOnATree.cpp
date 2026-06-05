// Last updated: 5/6/2026, 5:06:28 pm
class Solution {
public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        vector<vector<pair<int,int>>> adj(n);
        vector<int> deg(n);
        for(int i=0;i<edges.size();++i){
            adj[edges[i][0]].push_back({edges[i][1],i});
            adj[edges[i][1]].push_back({edges[i][0],i});
        }

        for(int i=0;i<n;++i) deg[i] = adj[i].size();
        
        vector<int> state(n);
        for(int i=0;i<n;++i){
            state[i] = (start[i]-'0')^(target[i]-'0');
        }
        
        queue <int> q;

        for(int i=0;i<n;++i){
            if(deg[i]==1) q.push(i);
            
        }
        vector<int> ans;
        vector<int> done(n,false);

        while(!q.empty()){
            int u = q.front();
            q.pop();

            done[u] = true;

            int par=-1,idx=-1;

            for(auto &p:adj[u]){
                int v = p.first;
                int ind = p.second;
                if(done[v]==false){
                    par = v;
                    idx = ind;
                    break;
                }
            }
            if(par == -1) continue;

            if(state[u]==1){
                ans.push_back(idx);
                state[u]^=1;
                state[par]^=1;
            }
            deg[par]--;

            if(deg[par]==1) q.push(par);
        }
        for(int i=0;i<n;++i){
            if(state[i]==1) return {-1};
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};