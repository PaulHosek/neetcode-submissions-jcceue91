class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> out;
        int i =0;
        int n = intervals.size();


        // just copy over for all non-overlapping
        while (i < n && intervals[i][1] < newInterval[0]){
            out.push_back(intervals[i]);
            i++;
        }

        // there can be at most 1 overlap, so we can insert and then merge until there is no more overlap
        while (i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = std::min(newInterval[0], intervals[i][0]);
            newInterval[1] = std::max(newInterval[1], intervals[i][1]);
            i++;
        }

        out.push_back(newInterval);

        while (i < n){
            out.push_back(intervals[i]);
            i++;
        }

        return out;






    }
};
