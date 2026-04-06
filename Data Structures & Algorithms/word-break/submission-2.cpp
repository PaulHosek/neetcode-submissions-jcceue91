/*Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of dictionary words.
- if set is empty s must be empty for it to be valid




You are allowed to reuse words in the dictionary an unlimited number of times. You may assume all dictionary words are unique.
- have infinite number of words in dict -> can reuse
- set has unique words only
- set is unsorted

Summary:
 - get a string and a set of substrings, see if there exits a combination of substrings in set wordDict that make up string


Example:
s = "applepenapple", wordDict = ["apple","pen","ape"]

Find combination of words in ["apple","pen","ape", "ap"] that make up string "applepenapple"
Find combination of words in wordDict that make up string s

Decisions:


// for ith letter s[i], check if there is a word that starts with s[i]

for ith letter s[i], check if there is a word that starts with s[i]
for candidate c in wordDict
    if c matches s[i:j] 
        Take c, continue to end i + len(c)
    Skip automatically by considering next canidate

State:
    - current index i in string

How to find valid canidates efficiently:
- 


Sketch space:
- prefixes tree (trie) may be good
- first letter must be beginning of a word in the set
*/


class Solution {
public:
    void findValidCandidate_moveUpString(const string& s, const unordered_set<string>& words, int l, bool& valid, vector<bool>& cache){
        if (valid || cache[l]){
            return;
        }
        if (l == s.length()){
            valid = true;
            return;
        }
        for (int curlen = 1; curlen <= s.length()-l; curlen++){
            const string& sv = s.substr(l,curlen);
            if (words.count(sv)){
                cache[l] = true;
                findValidCandidate_moveUpString(s, words, l+curlen,valid, cache);
            }
        }

    }

    bool wordBreak(string s, vector<string>& wordDict) {
        bool res{false};
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<bool> cache(s.length(), false);
        findValidCandidate_moveUpString(s, words, 0, res, cache);
        return res;
        
    }
};
