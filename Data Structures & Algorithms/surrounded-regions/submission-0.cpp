#include <iostream>
#include <vector>
#include <deque>
#include <utility>

class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        if (board.empty()) {
            return;
        }
        int n = board.size();
        int m = board[0].size();
        std::deque<std::pair<int, int>> q{};
        std::vector<std::pair<int, int>> captured{};
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
        
        const std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        auto bfs = [&]() {
            while (!q.empty()) {
                auto [r, c] = q.front();
                q.pop_front();
                for (const auto& [nr, nc] : directions) {
                    int rr = nr + r;
                    int cc = nc + c;
                    if (rr >= 0 && cc >= 0 && rr < n && cc < m && !visited[rr][cc]) {
                        visited[rr][cc] = true;
                        if (board[rr][cc] == 'O') {
                            captured.push_back({rr, cc});
                            q.push_back({rr, cc});
                        }
                    }
                }
            }
        };

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (board[r][c] == 'O' && !visited[r][c]) {
                    bool is_surrounded = true;
                    visited[r][c] = true;
                    if (r == 0 || r == n - 1 || c == 0 || c == m - 1) {
                        is_surrounded = false;
                    }
                    captured.push_back({r, c});
                    q.push_back({r, c});
                    bfs();
                    for (const auto& [i, j] : captured) {
                        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                            is_surrounded = false;
                        }
                    }
                    if (is_surrounded && !captured.empty()) {
                        for (const auto& [i, j] : captured) {
                            board[i][j] = 'X';
                        }
                    }
                    captured.clear();
                }
            }
        }
    }
};