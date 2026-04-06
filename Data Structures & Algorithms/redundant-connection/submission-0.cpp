class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // not marked const so I will be changing the edges vector

        int n = edges.size();
        queue<int> q;
        vector<unordered_set<int>> adj(n+1);

        for (const auto& e : edges){
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }

        auto clearDownstream = [&](){
            while (!q.empty()){
                int cur = q.front();
                q.pop();
                for (const auto& nei : adj[cur]){
                    adj[nei].erase(cur);
                    if (adj[nei].size() == 1){
                        q.push(nei);
                    }
                }
                adj[cur].clear();
            }
        };

        for (int i = 1; i < adj.size(); i++){
            if (adj[i].size() == 1){
                q.push(i);
            }
        }
        clearDownstream();

        // now only have cycle edges in adj
        for (int i = n-1; i >=0; i--){
            int u = edges[i][0];
            int v = edges[i][1];
            if (adj[u].count(v)){
                return edges[i];
            }
        }
        return {};


        
    }
};

