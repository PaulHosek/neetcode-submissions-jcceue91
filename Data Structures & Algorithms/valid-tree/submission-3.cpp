class Solution {
public:

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<unordered_set<int>> adj(n);
        queue<int> q{};

    
        for (const auto& e : edges){
            adj[e[0]].insert(e[1]);
            adj[e[1]].insert(e[0]);
        }

        for (int i = 0; i < n; i++){
            if (adj[i].size() <= 1){
                q.push(i);
            }
        }


        int nremov{0};
        while(!q.empty()){
            int node = q.front();
            q.pop();
            nremov++;
            // nedges[n]--;
            // go to all neighbours and remove the edge we have with them
            for (const auto& e : adj[node]){
                adj[e].erase(node);
                // nedges[e]--;
                if(adj[e].size() == 1){
                    q.push(e);
                }
            }
            adj[node].clear();
        }
        return nremov == n;


    }
};
