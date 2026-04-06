class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1); // ignore first idx
        std::iota(parent.begin(), parent.end(), 0);
        std::vector<int> compsize(n+1, 1);

        for (const auto& e : edges){
            if (uunion(parent, compsize, e[0], e[1])){ // check if they are in the same component otherwise join the two components
                return {e[0], e[1]};
            }
        }

    }

    int ufind(vector<int>& parent, int node){
        int croot = parent[node];
        while (parent[croot] != croot){
            croot = parent[croot];
        }
        // cur is root now, could return but we can do path compression first
        // i.e., linking all to root directly
        int tmp{};
        while (parent[node] != croot){
            tmp = parent[node];
            parent[node] = croot;
            node = tmp;
        }
        return croot;
    }


    bool uunion(vector<int>& parent, vector<int>& compsize, int v1, int v2){
        int l = ufind(parent, v1);
        int r = ufind(parent, v2);

        if (l == r){
            return true;
        }

        // join components
        if (compsize[l] < compsize[r]){
            std::swap(l, r);
        }
        parent[l] = r;
        compsize[l] += compsize[r];
        return false;

    }
};
