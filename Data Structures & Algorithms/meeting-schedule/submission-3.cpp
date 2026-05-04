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
        
        auto comp = [](Interval const& iv1, Interval const& iv2){
            return iv1.start < iv2.start;
        };
        std::sort(intervals.begin(), intervals.end(), comp);

        int prevEnd = -1;
        for (const auto& iv : intervals){
            if (iv.start < prevEnd){
                return false;
            }
            prevEnd = std::max(prevEnd, iv.end);
        }
        return true;
    }
};

/*

0 ----- 10------20
    5--------15

prevEnd = -10

*/
