class Solution {
public:

    int maxScore(string s) {
        // score is counting the 1s
        // prefix sum -> zeros count
        // suffix sum -> 1s count
        std::vector<int> prefix(s.length(), 0);
        prefix[0] = static_cast<int>(s[0] == '0');
        for (int i = 1; i< s.length(); i++){
            prefix[i] = prefix[i-1] + static_cast<int>(s[i] == '0'); 
        }

        std::vector<int> suffix(s.length(), 0);
        suffix[s.length()-1] = static_cast<int>(s[s.length()-1] == '1');
        for (int i = s.length()-2; i >= 0; i--){
            suffix[i] = suffix[i+1] + static_cast<int>(s[i] == '1');
        }

        int best{prefix[0] + suffix[1]};
        for (int i = 1; i < s.length()-1; i++){
            best = std::max(prefix[i] + suffix[i+1], best);
        }
        return best;
        

    }
};