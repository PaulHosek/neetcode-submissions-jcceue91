class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> col{};
        unordered_set<int> pDiag{};
        unordered_set<int> nDiag{};

        std::vector<vector<string>> res{};
        vector<string> board(n, std::string(n, '.'));

        dfs(res,board,n, col, pDiag, nDiag,0);
        return res;
    }

    void dfs(std::vector<std::vector<std::string>>& res, vector<string>& board,
        const int n, unordered_set<int>& col, unordered_set<int>& pDiag, unordered_set<int>& nDiag, int r){

        if(r == n){
            res.push_back(board);
            return;
        }

        for (int c = 0; c<n; c++){
            if (col.count(c) ||
            pDiag.count(r+c) ||
            nDiag.count(r-c)){
                continue;
            }
            
            
            col.insert(c);
            pDiag.insert(r+c);
            nDiag.insert(r-c);
            board[r][c] = 'Q';

            dfs(res, board, n, col, pDiag, nDiag, r+1);

            // backtrack
            col.erase(c);
            pDiag.erase(r+c);
            nDiag.erase(r-c);
            board[r][c] = '.';

        }
    }
};
// if (col.find(c) != col.end() ||
//             pDiag.find(r+c) != pDiag.end() ||
//             nDiag.find(r-c) != nDiag.end()){
//                 continue;
//             }