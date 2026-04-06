class Solution {
public:



    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {


        // for pacific, atlantic
        // 
        // PACIFIC:
            // 1. add all border nodes to the queue
            // 2. do BFS on valid where valid height[new] >= height[cur]
            // save to 2d array for now, incremenbt by 1, do same for atlantic and then count the nr of 2s

        if (heights.empty()){
            return {};
        }
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> reachable(m, vector<int>(n, 0));
        vector<vector<int>> visited_pac(m, vector<int>(n, 0));
        vector<vector<int>> visited_atl(m, vector<int>(n, 0));

        std::queue<std::pair<int,int>> q1{};
        std::queue<std::pair<int,int>> q2{};


        for (int r = 0; r < m; r++) {
            int c = 0;
            if (visited_pac[r][c] == 0) {
                visited_pac[r][c] = 1;
                reachable[r][c]++;
                q1.push({r, c});
            }
        }
        for (int c = 0; c < n; c++) {
            int r = 0;
            if (visited_pac[r][c] == 0) {
                visited_pac[r][c] = 1;
                reachable[r][c]++;
                q1.push({r, c});
            }
        }

        for (int r = 0; r < m; r++) {
            int c = n - 1;
            if (visited_atl[r][c] == 0) {
                visited_atl[r][c] = 1;
                reachable[r][c]++;
                q2.push({r, c});
            }
        }
        for (int c = 0; c < n; c++) {
            int r = m - 1;
            if (visited_atl[r][c] == 0) {
                visited_atl[r][c] = 1;
                reachable[r][c]++;
                q2.push({r, c});
            }
        }

        auto bfs = [&](std::queue<std::pair<int,int>>& q, std::vector<vector<int>>& visited){
            std::vector<std::pair<int,int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};
            while(!q.empty()){
                auto [r,c] = q.front();
                q.pop();
                for (const auto& [rn,cn] : directions){
                    int rr = rn + r;
                    int cc = cn + c;
                    if (rr >= 0 && cc >= 0 && rr < m && cc < n &&
                        visited[rr][cc] == 0 && heights[rr][cc] >= heights[r][c]) {
                        visited[rr][cc] = 1;
                            reachable[rr][cc]++;
                            q.push({rr,cc});
                        }
                    }
                }
        };

        bfs(q1,visited_pac);
        bfs(q2,visited_atl);

        vector<vector<int>> out{};
        for (int r = 0; r < reachable.size(); r++){
            for (int c =0; c< reachable[0].size(); c++){
                if (reachable[r][c] == 2){
                    out.push_back({r,c});
                }
            }
        }
        return out;



        
    }
};
