class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);
        vector<int> rank(n+1, 1);

        for(int i =0;i <= n; i++){
            parent[i] = i;
        }

        for (const auto& e : edges){
            if (!myunion(parent, rank, e[0], e[1])){
                return {e[0], e[1]};
            }
        }
        return {};
    }

    int myfind(vector<int>& parent, int n){
        int p = parent[n];
        // go up the chain until self link = root node
        // if not self-link, link cur to parent's parent and move on to parent
        while (p != parent[p]){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }
        return p;
    }

    bool myunion(vector<int>& parent, vector<int>& rank, int n1, int n2){
        int p1 = myfind(parent, n1);
        int p2 = myfind(parent, n2);

        if (p1 == p2){
            return false;
        }
        if (rank[p1] > rank[p2]){
            parent[p2] = p1;
            rank[p1] += rank[p2];
        } else {
            parent[p1] = p2;
            rank[p2] += rank[p1];
        }
        return true;
        
    }
};
