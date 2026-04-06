class Solution {
public:
    int countSubstrings(string s) {
        int res {};
        res += palic(s, 0, 0);
        for (int i=1; i < s.length(); i++){
            res += palic(s, i-1, i);
            res += palic(s, i, i);
        }
        return res;
    }

    int palic(const string& s, int l, int r){
        // cerr << l << " " << r << ":";
        int count{0};
        while(l >=0 && r <= s.length() && s[l] == s[r]){
            count++;
            l--;
            r++;
        }
        // cerr << count << "|";

        return count;
    }
};
