class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        const int n = intervals.size();
        if (intervals.empty()){
            return {};
        }
        std::ranges::sort(intervals, [](auto& intv1, auto& intv2){return intv1[0] < intv2[0];});
        vector<vector<int>> out;
        out.push_back(intervals[0]);

        for (int i = 1; i < n; i++){
            int& prevEnd = out.back()[1];
            const int start = intervals[i][0];
            const int end = intervals[i][1];

            if (prevEnd >= start){
                prevEnd = std::max(prevEnd, end);
            } else {
                out.push_back({start, end});
            }
        }
        return out;



    }
};
