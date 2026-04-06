class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        const int N = strs.size();
        if (N == 0){
            return "";
        }
        string prefix = strs[0];
        for (int i = 1; i < N; i++){
            int j = 0;
            const string& cur = strs[i];
            while(j < prefix.size() && prefix[j] == cur[j]){
                j++;
            }
            prefix = cur.substr(0, j);
        }
        return prefix;

        
        
    }
};