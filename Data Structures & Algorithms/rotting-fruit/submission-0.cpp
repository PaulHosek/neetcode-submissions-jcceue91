#include <array>
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()){
            return 0;
        }
        constexpr int ROTTEN{2};
        constexpr int FRUIT{1};
        int fcount{0};

       queue<pair<int,int>> q{};
       for (int r = 0; r< grid.size(); r++){
        for (int c=0; c< grid[0].size(); c++){
            if (grid[r][c] == ROTTEN){
                q.push({r,c});
            }
            if (grid[r][c] == FRUIT){
                fcount++;
                
            }
        }
       }

        std::vector<std::pair<int,int>> directions = {{0, 1}, {0,-1}, {1,0}, {-1,0}};

        int depth{0};
        int qs = q.size();
       while(!q.empty()){
        qs = q.size();
        for (int l = 0; l < qs; l++){
            auto [r,c] = q.front();
            q.pop();
            for (const auto& [nr, nc] : directions){
                int rr = r + nr;
                int cc = c + nc;
                if (rr >= 0 && cc >= 0 && rr < grid.size() && cc < grid[0].size() && grid[rr][cc] == FRUIT){
                    grid[rr][cc] = ROTTEN;
                    fcount--;

                    q.push({rr,cc});
                }
            }
        }
        if (!q.empty()){
            depth++;
        }


       }
       return fcount == 0 ? depth : -1;
        
    }
};
