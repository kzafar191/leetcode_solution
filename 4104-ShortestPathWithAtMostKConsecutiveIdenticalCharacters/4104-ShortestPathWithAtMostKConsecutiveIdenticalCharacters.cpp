// Last updated: 30/6/2026, 11:59:59 am
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(int i=0;i<edges.size();++i){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back({v,edges[i][2]});
        }

        vector<vector<int>> dis(n,vector<int>(k+1,INT_MAX));

        priority_queue<pair<int,pair<int,int>>> pq;

        dis[0][1] = 0;
        pq.push({0,{0,1}});

        while(!pq.empty()){
            pair<int,pair<int,int>> cur = pq.top(); pq.pop();

            int w = cur.first*-1;
            int u = cur.second.first;
            int cons = cur.second.second;

            if(u==n-1) return w;

            if(w>dis[u][cons]) continue;

            for(int i=0;i<adj[u].size();++i){
                int v = adj[u][i].first;
                int ww = adj[u][i].second;

                int ncons;
                if(labels[u] == labels[v]) ncons = cons+1;
                else ncons = 1;

                if(ncons<=k){
                    int neww = w+ww;

                    if(neww<dis[v][ncons]){
                        dis[v][ncons] = neww;
                        pq.push({-neww,{v,ncons}});
                    }
                }
            }
        }
        return -1;
    }
};