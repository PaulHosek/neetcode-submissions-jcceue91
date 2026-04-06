class Solution {
public:

    bool valid_palindrome(const string& s, vector<vector<int>>& valid_p, int start, int end){
        if (valid_p[start][end] == 1){
            return true;
        } else if (valid_p[start][end] == 0){
            return false;
        } // -1 is uncomputed
         
        int l =0;
        int r =s.length()-1;
        while (r > l){
            if (s[l] != s[r]){
                valid_p[start][end] = 0;
                return false;
            }
            l++;
            r--;
        }
        valid_p[start][end] = 1;
        return true;
    
    }

    void dfs(const string& s, vector<vector<string>>& res, vector<string>& tmp, int idx, vector<vector<int>>& valid_p){
        if (idx >= s.length()){
            res.push_back(tmp);
            return;
        }

        string ts;
        for (int j = idx; j<s.length(); j++){
            ts += s[j];
            if(valid_palindrome(ts, valid_p, idx, j)){
                tmp.push_back(ts);
                dfs(s, res, tmp, j+1, valid_p);
                tmp.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res{};
        vector<string> tmp{};
        vector<vector<int>> valid_p(s.length(), vector<int>(s.length(), -1)); // tri-state: -1 uncomputed; 0 false; 1 true
        dfs(s, res, tmp, 0, valid_p);
        return res;
        
    }
};
