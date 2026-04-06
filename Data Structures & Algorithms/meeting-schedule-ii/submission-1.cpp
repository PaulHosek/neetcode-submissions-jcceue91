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
    int minMeetingRooms(vector<Interval>& intervals) {
        
        std::ranges::sort(intervals, [](auto& iv1, auto& iv2){return iv1.start < iv2.start;}); 

        int lastEnd = std::numeric_limits<int>::min();
        int maxOverlap{1};
        int curOverlap{1};

        std::priority_queue<int, std::vector<int>, std::greater<>> endtimes_active_meetings; // min heap


        for (const auto& iv : intervals){

            if (!endtimes_active_meetings.empty() && endtimes_active_meetings.top() <= iv.start){
                endtimes_active_meetings.pop();
            }

            endtimes_active_meetings.push(iv.end);

        }
        return endtimes_active_meetings.size();
    }
};
