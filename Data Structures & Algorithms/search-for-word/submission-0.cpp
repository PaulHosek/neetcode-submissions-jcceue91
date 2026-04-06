class Solution {
public:
    void dfs(const vector<vector<char>>& board, const string& word, bool& res, int lidx, int row, int col, vector<vector<bool>>& path){ 
        if(row > board.size() -1 ||
         col > board[0].size() -1 || 
         col < 0 ||
         row < 0 ||
         res ||
          word[lidx] != board[row][col] ||
          path[row][col] == true){
            return;
        }

        if (lidx == word.length()-1 && word[lidx] == board[row][col]){
            res = true;
            return;
        }

        path[row][col] = true;
        dfs(board, word, res, lidx+1, row+1, col, path);
        dfs(board, word, res, lidx+1, row-1, col, path);
        dfs(board, word, res, lidx+1, row, col+1, path);
        dfs(board, word, res, lidx+1, row, col-1, path);
        path[row][col] = false;




    }
    bool exist(vector<vector<char>>& board, string word) {
        bool res{false};
        vector<vector<bool>> path{board.size(), std::vector<bool>(board[0].size(), false)};
        if (board.empty()){
            return false;
        }
        for (int r = 0; r < board.size(); r++){
            for (int c = 0; c < board[0].size(); c++){
                dfs(board, word, res, 0, r, c, path);
                if (res){
                    return true;
                }
            }
        }
        return res;
        
    }
};
