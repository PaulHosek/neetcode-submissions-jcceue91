class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        std::vector<std::vector<int>> grid(n+1, std::vector<int>(m+1, 0));
        for(int r = n-1; r>=0; r--){
            for (int c = m-1; c>=0; c--){

                if (text1[r] == text2[c]){
                    grid[r][c] = 1 + grid[r+1][c+1];
                } else{
                    grid[r][c] = std::max(grid[r+1][c], grid[r][c+1]);
                }
            }
        }
        return grid[0][0];

    }
};
