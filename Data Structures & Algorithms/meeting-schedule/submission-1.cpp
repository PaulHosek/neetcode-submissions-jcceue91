/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // are there overlapping intervals
        std::ranges::sort(intervals, [](auto& iv1, auto& iv2){return iv1.start < iv2.start;});

        int LastEnd = std::numeric_limits<int>::min();
        for (auto& iv : intervals){
            if (LastEnd > iv.start){
                return false;
            }
            LastEnd = iv.end;
        }
        return true;

    }
};
