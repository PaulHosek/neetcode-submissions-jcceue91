class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        std::vector<std::vector<int>> grid(n+1, std::vector<int>(m+1, 0));
        for (int r = 1; r<= n; r++){
            for (int c =1; c<=m; c++){
                if (text1[r-1] == text2[c-1]){
                    grid[r][c] = grid[r-1][c-1] + 1;
                } else{
                    grid[r][c] = std::max(grid[r-1][c], grid[r][c-1]);
                }
            }
        }
        return grid[n][m];


    }
};
