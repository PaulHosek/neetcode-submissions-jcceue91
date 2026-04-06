class Solution {
public:
    string decodeString(string s) {
        // on closing bracket, we pop one from the stack and add the current char to the front and then replicate it that nr times
        std::stack<std::pair<int,string>> stk;
        // string out;
        string ks;
        stk.push({0,""});
        for (int i = 0; i < s.length(); i++){
            char cur = s[i];
            if (cur == '['){
                // ks must hold something -> strings are guaranteed to be well formed
                stk.push({std::stoi(ks), ""});
                ks.clear();
            } else if (cur == ']'){
                // take the staging string replicate it with the popped top element on the stack and make that the new staging element if the stack not empty
                auto old = stk.top();
                stk.pop();
                while (old.first--){
                    stk.top().second.append(old.second);
                }

            } else if (cur >= 'a' && cur <= 'z'){

                stk.top().second.push_back(cur);
                
            } else if (cur >= '0' && cur <= '9'){
                ks.push_back(cur);
            } 
        }
        return stk.top().second;
    }
};