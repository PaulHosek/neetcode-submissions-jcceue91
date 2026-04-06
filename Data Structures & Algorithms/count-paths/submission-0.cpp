// // There is an m x n grid where you are allowed to move either down or to the right at any point in time.
// - down or right only
// - m x n

// // Given the two integers m and n, return the number of possible unique paths that can be taken from the top-left corner 
// // of the grid (grid[0][0]) to the bottom-right corner (grid[m - 1][n - 1]).
// - nr unique paths -> at least one different field

// // You may assume the output will fit in a 32-bit integer.
// - assume signed is meant. seeing signature

 

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 0 || n == 0 ){
            return 0;
        }
        // TODO: what happens at 1xN?

        // fill bottom row and right most column with 1
        std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));
        for (int i = 0; i<m; i++){
            grid[i][n-1] = 1;
        }
        for (int j = 0; j<n; j++){
            grid[m-1][j] = 1;
        }
        // for case >= 2x2
        int r = m-2;
        while(r >= 0){
            int c = n-2;
            while (c >= 0){
                grid[r][c] = grid[r+1][c] + grid[r][c+1]; // start one in
                c--;
            }
            r--;

        }
        return grid[0][0];

    }
};
