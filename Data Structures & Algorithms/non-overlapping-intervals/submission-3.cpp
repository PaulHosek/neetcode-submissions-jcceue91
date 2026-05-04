class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
       std::ranges::sort(intervals);

       int res = 0;
       int prevEnd = intervals[0][1];
       for (int i =1;i<intervals.size(); i++){
        const auto& iv = intervals[i];
        if (prevEnd > iv[0]){
            prevEnd = std::min(prevEnd, iv[1]);
            res++;
        } else {
            prevEnd = iv[1];
        }
       } 
       return res;
    }
};
