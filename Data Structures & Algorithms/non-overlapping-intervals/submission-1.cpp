class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::ranges::sort(intervals, [](auto& v1, auto& v2){return v1[0] < v2[0];});
        const int n = intervals.size();

        int lastEnd = intervals[0][1];
        int count{0};
        for (int i = 1; i<n; i++){
            // auto& lastEnd = out.back()[1];
            const int start = intervals[i][0];
            const int end = intervals[i][1];

            if (start < lastEnd){
                lastEnd = std::min(lastEnd, end);
                count++;
            } else {
                lastEnd = end;
            }
        }
        return count;


    
    
    }
};
