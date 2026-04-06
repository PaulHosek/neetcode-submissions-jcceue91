#include <string_view>
class Solution {
public:
    inline static const vector<string> mapping {
                "",
                "",
                "abc",
                "def",
                "ghi",
                "jkl",
                "mno",
                "pqrs",
                "tuv",
                "wxyz"
            };
    void dfs(string_view digits, vector<string>& res, string& tmp, int idx){
    
        if (idx == digits.length()){
            res.push_back(tmp);
            return;
        }


        const string& cs = mapping[digits[idx] - '0'];
        for (const char& c : cs) {
            tmp += c;
            dfs(digits, res, tmp, idx+1);
            tmp.pop_back();
        }

    }

    
    vector<string> letterCombinations(string digits) {
        if (digits.empty()){
            return {};
        }
        vector<string> res{};
        string tmp{};
        dfs(digits, res,tmp, 0);
        return res;
        
    }
};
