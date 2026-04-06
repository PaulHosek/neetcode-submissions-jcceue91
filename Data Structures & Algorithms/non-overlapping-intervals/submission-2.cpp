class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        std::ranges::sort(intervals, [](auto& v1, auto& v2){return v1[1] < v2[1];});
        const int n = intervals.size();

        int lastEnd = intervals[0][1];
        int count{0};
        for (int i = 1; i<n; i++){
            const int start = intervals[i][0];
            if (start < lastEnd){
                count++;
            } else {
                lastEnd = intervals[i][1];
            }
        }
        return count;


    
    
    }
};
