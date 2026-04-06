class Solution {
public:
    void dfs(const vector<vector<char>>& grid, vector<vector<bool>>& valid, int r, int c){
        if ( r < 0 ||
        c < 0 ||
        r > grid.size()-1||
        c > grid[0].size()-1 ||
        !valid[r][c]
        ){ 
            return;
        }

        valid[r][c] = false; // node now visitied
        if (grid[r][c] == '0'){
            return;
        }

        dfs(grid, valid, r,c+1);
        dfs(grid, valid, r, c-1);
        dfs(grid, valid, r+1, c);
        dfs(grid, valid, r-1, c);

        
    }


    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()){
            return 0;
        }
        int res{0};
        vector<vector<bool>> valid(grid.size(), vector<bool>(grid[0].size(), true));
        for (int r = 0; r < grid.size(); r++) {
            for (int c = 0; c <grid[0].size(); c++){
                if (grid[r][c] == '0' || !valid[r][c]){
                    valid[r][c] = false;
                    continue;
                }
                res++; // new island
                dfs(grid, valid, r,c);
            }
        }
        return res;
        
    }
};
