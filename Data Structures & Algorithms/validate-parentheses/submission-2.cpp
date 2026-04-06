class Solution {
public:
    bool isValid(string s) {
        stack<char> brackets_stack;
        for (const auto& c : s){
            switch(c){
                case '{':
                    brackets_stack.push('}');
                    break;
                case '[':
                    brackets_stack.push(']');
                    break;
                case '(':
                    brackets_stack.push(')');
                    break;
                default:
                // if any closing brace type
                    if (brackets_stack.size() == 0 || brackets_stack.top() != c){
                        return false;
                    } else { // matches top one on stack
                        brackets_stack.pop();
                    }
            }
        }
        return brackets_stack.empty(); // if any left, than not valid

        
    }
};