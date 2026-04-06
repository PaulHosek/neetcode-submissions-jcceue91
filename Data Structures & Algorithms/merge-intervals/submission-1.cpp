class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()){
            return {};
        }
        std::ranges::sort(intervals);


        std::vector<std::vector<int>> out;
        out.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++){
            auto& old_iv = out.back();
            if (old_iv[1] >= intervals[i][0]){ 
                old_iv[1] = std::max(intervals[i][1], old_iv[1]); 
            } else {
                out.push_back(intervals[i]);
            }
        }
        return out;
    }
};