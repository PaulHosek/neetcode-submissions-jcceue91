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



/*

Goal: Find the maximum number of overlap at any timepoint.
Earlier endpoints can lead to reuse of a room.
*/

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        std::priority_queue<int,std::vector<int>, std::greater<>> min_ends; // min heap

        // if min end > cur, need another room -> push 
        // if min end <= cur, not another room -> overlap on same point no problem
        std::ranges::sort(intervals.begin(), intervals.end(), [](auto& i1, auto& i2){return i1.start < i2.start;});
        int max_rooms{};
        for (const auto& inv : intervals){
            if(min_ends.empty() || min_ends.top() > inv.start){
                min_ends.push(inv.end);
                int s = min_ends.size();
                max_rooms = std::max(max_rooms, s);
                continue;
            }

            min_ends.pop();
            min_ends.push(inv.end);

        }
        return max_rooms;


    }
};














