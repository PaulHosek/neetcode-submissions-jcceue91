class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,int>>, std::greater<>> min_heap; //  pair(next cost, nodeid)
        std::vector<std::vector<std::pair<int, int>>> adj(n); // map[nodeid] -> [neighbour, weight]
        std::unordered_map<int,int> best_distance;

        for (const auto& e : edges){
            adj[e[0]].emplace_back(e[2], e[1]);
        }

        min_heap.push({0, src});
        
        while (!min_heap.empty()){
            auto [w1, n1] = min_heap.top();
            min_heap.pop();

            if (best_distance.contains(n1)){
                continue;
            }

            best_distance[n1] = w1;
            // if dist n1 to neighbour better then update neighbour
            // always add neighbour, heap takes care of rest
            for (auto [w2,n2] : adj[n1]){
                if (!best_distance.contains(n2)){
                    min_heap.push({w1 + w2, n2});
                }
            }
        }

        // mark distance to non-reachable nodes -1
        for (int i = 0; i< n; i++){
            if (!best_distance.contains(i)){
                best_distance[i] = -1;
            }
        }
        return best_distance;

    }
};
