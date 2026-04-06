class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> par(n);
        // link every node to self
        std::iota(par.begin(), par.end(), 0); // can't I do this in the constructor?
        vector<int> compsize(n);

        auto ufind = [&](int node) -> int{
            int root = node;
            // jump up to valid root
            while (root != par[root]){
                root = par[root];
            }

            // path compression
            int tmp{};
            while (root != par[node]){
                tmp = par[node];
                par[node]= root;
                node = tmp;
            }
            return root;
        };

        auto uunion = [&](int a, int b) -> bool{
            int pa = ufind(a);
            int pb = ufind(b);

            if (pa == pb){
                return true; // already in component
            }
            if (compsize[pa] < compsize[pb]){
                std::swap(pa, pb);
            } 
            // pa is the big component
            par[pb] = pa;
            compsize[pa] += compsize[pb];
            return false;
        };
        int res{n};
        for (const auto& e : edges){
            if (!uunion(e[0], e[1])){
                res--; // edge already in component, cannot be separate component
            }
        }

        return res;



        





    }
};
