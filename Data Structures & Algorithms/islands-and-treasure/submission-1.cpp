class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {

        if (grid.empty()){
            return;
        }
        static constexpr int LAND{2147483647};
        static constexpr int TREASURE{0};
        static constexpr int WATER{-1};
        queue<pair<int,int>> q{};
        vector<pair<int,int>> directions = {{0,1}, {0,-1},
                                            {1,0}, {-1,0}};


        for (int r = 0; r < grid.size(); r++){
            for (int c = 0; c < grid[0].size(); c++){
                if (grid[r][c] == TREASURE){
                    q.push({r,c});
                }
            }
        }


        while(!q.empty()){
            std::pair<int,int> cur = q.front();
            q.pop();
            int r = cur.first;
            int c = cur.second;
            int dist = grid[r][c];
            // grid[r][c] = std::min(grid[r][c], depth);
            for (const auto& [dr,dc] : directions){ 
                int rj = dr + r;
                int cj = dc + c;
                if (rj < 0 || cj < 0 || rj >= grid.size() || cj >= grid[0].size() || grid[rj][cj] != LAND){
                    continue;
                }
                grid[rj][cj] = dist + 1;
                // grid[rj][cj] = std::min(depth+1, grid[rj][cj]);
                q.push({rj,cj});
            }
            
        }


        
    }
};
