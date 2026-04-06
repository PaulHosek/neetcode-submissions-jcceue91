class Solution {
public:
    void dfs(int& res, int pos){
        if(pos <= 0){
            if(pos == 0){
                res++;
            }
            return;
        }

        dfs(res, pos-1);
        dfs(res, pos-2);
    }

    int climbStairs(int n) {
        int res{0};
        dfs(res, n);
        return res;
        
    }
};
