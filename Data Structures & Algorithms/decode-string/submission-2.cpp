class Solution {
public:
    string decodeString(string s) {
        std::stack<std::pair<int, string>> stk;
        stk.push({0, ""}); // Base accumulator
        
        int k = 0; // Track the multiplier directly as an int
        
        for (char cur : s) {
            if (cur == '[') {
                stk.push({k, ""});
                k = 0; // Reset k for the next nested bracket
            } else if (cur == ']') {
                auto old = stk.top();
                stk.pop();
                
                // Append the expanded string to the new top of the stack
                while (old.first--) {
                    stk.top().second.append(old.second);
                }
            } else if (std::isalpha(cur)) {
                stk.top().second.push_back(cur);
            } else if (std::isdigit(cur)) {
                // Shift existing digits left by 1 decimal place and add the new one
                k = k * 10 + (cur - '0'); 
            } 
        }
        
        return stk.top().second;
    }
};