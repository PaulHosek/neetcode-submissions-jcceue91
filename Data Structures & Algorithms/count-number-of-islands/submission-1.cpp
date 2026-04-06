class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        const int N = grid.size();
        if (N == 0){
            return 0;
        }
        const int M = grid[0].size();
        std::vector<std::vector<bool>> visisted(N, std::vector<bool>(M, false));

        int count{0};
        const vector<std::pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0, 1}};
        for (int i = 0; i < N; i++){
            for (int j =0; j<M; j++){
                if (visisted[i][j] || grid[i][j] == '0'){
                    continue;
                }
                visisted[i][j] = true;
                std::queue<pair<int,int>> q;
                count++;
                q.push({i,j});
                while (!q.empty()){
                    auto p = q.front();
                    int r = p.first;
                    int c = p.second;
                    q.pop();
                    for (auto [rn, cn] : directions){
                        int rr = rn + r;
                        int cc = cn + c;
                        if (rr >=0 && cc >=0 && rr <N && cc <M && (visisted[rr][cc] == false) && (grid[rr][cc] == '1')){
                            q.push(std::make_pair(rr, cc));
                            visisted[rr][cc] = true;
                        }
                        
                    }
                }
            }
        }
        return count;
        
    }
};
