// Last updated: 5/6/2026, 5:06:29 pm
#include<bits/stdc++.h>
class Solution {
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<long long>> dist(n);
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        //X
        vector<int> visited(n,false);
        queue <pair<int,int>> que;
        que.push({x,0});
        visited[x] = true;
        int d=0;
        while(!(que.empty())){
            pair<int,int> node = que.front();
            que.pop();
            dist[node.first].push_back(node.second);
            for(int i:adj[node.first]){
                if(visited[i]) continue;
                que.push({i,node.second+1});
                visited[i] = true;
            }
        }

        //Y
        visited.assign(n,false);
        que.push({y,0});
        visited[y] = true;
        while(!(que.empty())){
            pair<int,int> node = que.front();
            que.pop();
            dist[node.first].push_back(node.second);
            for(int i:adj[node.first]){
                if(visited[i]) continue;
                que.push({i,node.second+1});
                visited[i] = true;
            }
        }

        //Z
        visited.assign(n,false);
        que.push({z,0});
        visited[z] = true;
        while(!(que.empty())){
            pair<int,int> node = que.front();
            que.pop();
            dist[node.first].push_back(node.second);
            for(int i:adj[node.first]){
                if(visited[i]) continue;
                que.push({i,node.second+1});
                visited[i] = true;
            }
        }

        int ans=0;
        for(int i=0;i<n;++i){
            vector<long long> temp(3);
            temp = dist[i];
            sort(temp.begin(),temp.end());
            if(temp[0]*temp[0] + temp[1]*temp[1] == temp[2]*temp[2]) ans++;
        }
        return ans;
    }
};