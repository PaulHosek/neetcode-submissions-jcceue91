class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int total{0};
        auto dfs = [&](auto self, int i, int cur) -> void{
            if (i == nums.size()){
                total += cur;
                return;
            }
            
            self(self, i+1, cur);
            cur ^= nums[i];
            self(self, i+1, cur);
        };
        dfs(dfs, 0, 0);

        return total;
    }
};