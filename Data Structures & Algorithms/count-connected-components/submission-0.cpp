class Solution {
public:

    int countComponents(int n, vector<vector<int>>& edges) {
        if (n == 0){
            return 0;
        }
        queue<int> q;
        vector<bool> vis(n, false);
        vector<vector<int>> adj(n);

        for (const auto& v : edges){
            adj[v[1]].push_back(v[0]);
            adj[v[0]].push_back(v[1]);
        }


        int comp{0};
        for (int i =0; i< n; i++){
            if (vis[i]){
                continue;
            }

            vis[i] = true;
            q.push(i);
            comp++;

            // do bfs, add all nodes in component to visited array
            while (!q.empty()){
                int cur = q.front();
                q.pop();
                for (const auto& nei: adj[cur]){
                    if (!vis[nei]){
                        q.push(nei);
                        vis[nei] = true;
                    }
                }

            }
        }
        return comp;
    




        
    }
};
