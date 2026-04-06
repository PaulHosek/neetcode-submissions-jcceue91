class Solution {
public:

    int numDecodings(string s) {

        int res{};
        dfs(s,res, s.length()-1);
        return res;
    }
    void dfs(const string& s, int& res, int r){
        if (r < 0){
            res++;
            return;
        }
        // either include r or rl
        // append next single
        int w1 = s[r] - '0';
        if (w1 >= 1){
            // res++;
            dfs(s, res, r-1);
        }

        // append next double and skip
        if (r-1 >= 0){
            int r2 = s[r-1] - '0';
            int w2 = w1 + 10*(r2);
            if (w2 <= 26 && r2 > 0){
                // res++;
                dfs(s, res,r-2);
            }
        }
        
    }
};
