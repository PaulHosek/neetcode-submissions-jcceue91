// You are given a 2-D grid of integers matrix, 
// where each integer is greater than or equal to 0.
// Return the length of the longest strictly increasing path within matrix.
// From each cell within the path, you can move either horizontally or vertically. 
// You may not move diagonally.

// - matrix is n*m matrix
// - all values >=0
// - find longest strictly increasing path
// - only up left right down



class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()){
            return 0;
        }
        const int n = matrix.size();
        const int m = matrix[0].size();

        int gMax{0};
        std::vector<std::pair<int, int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        std::vector<std::vector<int>> maxLen_perCell(n, std::vector<int>(m, -1));


        std::function<int(int, int)> dfs = [&](int r, int c) -> int{
            // int valid_neighbours{4};
            // TODO make sure r c not OOB
            if (r < 0 || c < 0 || r >= n || c >= m){
                return 0;
            }
            if (maxLen_perCell[r][c] != -1){
                return maxLen_perCell[r][c];
            }
            int curlen = 1;
            for (const auto& [rdir,cdir] : directions){
                
                int rr = rdir + r;
                int cc = cdir + c;
                if (rr < 0 || cc < 0 || rr >= n || cc >= m || matrix[r][c] >= matrix[rr][cc]){
                    // valid_neighbours--;
                    continue;
                }

                // do DFS until not possible anymore then set values on backtrack
                curlen = std::max(curlen, dfs(rr,cc)+1);
            }  
            // if (valid_neighbours == 0){
            //     maxLen_perCell[r][c] = 1;
            //     return 1;
            // }
            maxLen_perCell[r][c] = curlen;
            return maxLen_perCell[r][c];
        };

        for (int r = 0; r<n; r++){
            for (int c = 0; c<m; c++){
                // check values of all neighbours if have been already
                // if have been already do 1+ that cell and then the max over all neighbours
                // update gMax if needed
                // TODO mark const static to make faster
                gMax = std::max(dfs(r, c), gMax);

            }
        }
        return gMax;

    }
};
