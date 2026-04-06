class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int Nrow = grid.size();
        if (Nrow == 0){
            return 0;
        }
        const int Mcol = grid[0].size();
        std::vector<int> dp(Mcol, 0);
        
        dp[0] = grid[0][0];
        for (int i = 1; i<Mcol; i++){
            dp[i] = dp[i-1] + grid[0][i];
        }

        for (int r = 1; r < Nrow; r++){
            dp[0] += grid[r][0];
            for (int c = 1; c < Mcol; c++){
                // can either come from the top or from the left
                // c-1 is already updated and c not yet
                dp[c] = std::min(dp[c-1], dp[c]) + grid[r][c];
            }
        }
        return dp.back();
    }
};