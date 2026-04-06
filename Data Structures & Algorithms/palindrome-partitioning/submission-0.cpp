class Solution {
public:

    bool valid_palindrome(const string& s){
        int l =0;
        int r =s.length()-1;
        while (r > l){
            if (s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    
    }

    void dfs(const string& s, vector<vector<string>>& res, vector<string>& tmp, int idx){
        if (idx >= s.length()){
            res.push_back(tmp);
            return;
        }

        string ts;
        for (int j = idx; j<s.length(); j++){
            ts += s[j];
            if(valid_palindrome(ts)){
                tmp.push_back(ts);
                dfs(s, res, tmp, j+1);
                tmp.pop_back();
            }
        }

    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res{};
        vector<string> tmp{};
        dfs(s, res, tmp, 0);
        return res;
        
    }
};
