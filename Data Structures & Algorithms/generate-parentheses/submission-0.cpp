class Solution {
public:
    // opening = +1, closing = -1
    // if negative at any point or does not end in 0 => invalid combination
    void dfs(int n, vector<string>& res, int valid, int depth, string& tmp){
        if (valid < 0){
            return;
        }
        if (depth == 2*n){
            if (valid == 0){ // valid if 0
                res.push_back(tmp);
            }
            return;
        }

        tmp += "(";
        dfs(n, res, valid+1, depth+1, tmp);
        tmp.pop_back();
        tmp += ")";
        dfs(n, res, valid-1, depth+1, tmp);
        tmp.pop_back(); // not needed I don't think;



    }
    vector<string> generateParenthesis(int n) {
        vector<string> res{};
        string tmp{};
        dfs(n, res, 0, 0, tmp);
        return res;

        


    }
};
