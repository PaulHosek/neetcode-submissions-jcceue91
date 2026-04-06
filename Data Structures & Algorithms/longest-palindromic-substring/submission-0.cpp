class Solution {
public:
    string palindrome(const string& cs, int i, int j){
        int curlen = 1 ? i == j : 2;
        while (i >=0 && j < cs.length() && cs[i] == cs[j]){
            j++;
            i--;
            curlen += 2;
        }
        return string{cs.begin()+i+1, cs.begin()+j}; // endpoint not inclusive 
        
    }
    string longestPalindrome(string s) {

        string res =  palindrome(s, 0, 0);
        for (int i=0; i< s.length()-1; i++){
            string x = palindrome(s, i, i+1);
            string y =  palindrome(s,i+1, i+1);
            if (x.length() > res.length()){
                res = x;
            }
            if (y.length() > res.length()){
                res = y;
            }
        }
        
        return res;

    }
};
