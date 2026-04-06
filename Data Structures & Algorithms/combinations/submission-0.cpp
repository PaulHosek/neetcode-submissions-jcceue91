class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> out;
        std::vector<int> temp;
        auto dfs = [&](auto self, int i, std::vector<int>& cur){
            if (cur.size() == k){
                out.push_back(cur);
                return;
            }
            if (i == n+1){
                return;
            }

            cur.push_back(i);
            self(self, i+1, cur);
            cur.pop_back();
            self(self, i+1, cur);

            
        };

        dfs(dfs, 1, temp);
        return out;
    }
};