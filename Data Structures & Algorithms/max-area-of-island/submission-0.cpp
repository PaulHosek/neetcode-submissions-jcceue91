class Solution {
public:

    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& valid, int& cursize, int r, int c){
        if (r < 0 ||
        c < 0 ||
        r > grid.size()-1 ||
        c > grid[0].size()-1 ||
        !valid[r][c]){
            return;
        }
        valid[r][c] = false;
        if (grid[r][c] == 0){
            return;
        }
        // if find island node that has not been visited yet
        cursize++;

        dfs(grid, valid, cursize, r, c+1);
        dfs(grid, valid, cursize, r, c-1);
        dfs(grid, valid, cursize, r+1, c);
        dfs(grid, valid, cursize, r-1, c);

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()){
            return 0;
        }
        int res{};
        vector<vector<bool>> valid(grid.size(), vector<bool>(grid[0].size(), true));
        for (int r = 0; r < grid.size(); r++){
            for (int c = 0; c < grid[0].size(); c++){
                if (grid[r][c] == 1 && valid[r][c]){
                    int cursize{0};
                    dfs(grid, valid, cursize, r, c);
                    res = std::max(cursize, res);
                }
            }
        }
        return res;
    }
};
