class Solution {
public:
    int maxArea(vector<int>& heights) {
        int begin {0};
        int end {static_cast<int>(heights.size())-1};
        int best {0};
        int cur {0};
        while (begin < end){
            cur = min(heights[begin], heights[end]) * (end-begin);
            best = max(best, cur);
            if (heights[begin] >= heights[end]){
                end--;
            } else {
                begin++;
            }
        }
        return best;
    }
};
