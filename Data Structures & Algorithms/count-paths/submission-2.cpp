
class Solution {
public:
    int uniquePaths(int m, int n) {
        // m rows, n columns
        std::vector<int> row(n, 1);
        for (int j = 1; j<m; j++){
            for (int i = 1; i<n; i++){
                row[i] += row[i-1];
            }
        }
        return row.back();
    }
};
    // int uniquePaths(int m, int n) {
    //    std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));
    //    // first row and first column are 1
    //    for (auto i = 0u; i < m; i++){
    //     grid[i][0] = 1;
    //    }
    //    for (auto j = 0u; j < n; j++){
    //     grid[0][j] = 1;
    //    }
       
    //    for (auto ii = 1u; ii < m; ii++){
    //     for (auto jj = 1u; jj < n; jj++){
    //         grid[ii][jj] = grid[ii -1][jj] + grid[ii][jj-1];
    //     }
    //    }
    //    return grid[m-1][n-1];
    // }