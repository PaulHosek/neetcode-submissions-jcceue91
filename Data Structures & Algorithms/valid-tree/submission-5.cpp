class Solution {
public:

    // Super cool omg: INVERSE topo sort -> push all with degree 1 (leafs)
        // then remove that node from all its parents and push them if they become leafs
        // keep track of how many we pushed to queue in total
    
    bool validTree(int n, vector<vector<int>>& edges) {
        // Valid Tree:
            // needs to have exactly 1 root
            // no cycles
        if (edges.size() != n-1){
            return false;
        }

        if (n == 1){
            return true;
        }

        
        // given n edges there can be at most n+1 nodes
        vector<vector<int>> adj(n); 
        vector<int> degree(n, 0);

        for (const auto& e : edges){
            int v1 = e[0];
            int v2 = e[1];
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);

            degree[v1]++;
            degree[v2]++;
        }

        // fill queue with leaves for inverse topo sort (degree 1)
        std::queue<int> q;
        for (int i = 0; i < n; i++){
            if (degree[i] == 1){
                q.push(i);
            }
        }

        int finished{0};

        while (!q.empty()){
            int cur = q.front();
            q.pop();
            finished++;

            // remove leaf from parents, if parent leaf, push it
            for (int nei : adj[cur]){
                degree[nei]--;
                if (degree[nei] == 1){
                    q.push(nei);
                }
            }
        }

        return finished == n;

    }
};






































