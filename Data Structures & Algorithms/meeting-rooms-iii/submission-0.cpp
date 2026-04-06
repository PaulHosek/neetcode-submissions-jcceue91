class Solution {
public:
/*

- end not included
- start values unique
- n rooms: 0,..n-1 (100 max)
10^5 -> N log N / N + C

- lowest room number first
- delay meeting if no rooms free
- earlier start time delayed meetings first

Goal: Find Room with the highest meeting count. On tie, find the lowest index one.
*/
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // sort on start date.
        // don't need priority_queue because have sorted input right?
        // have some sort of queue
        // if queue is empty,
            // if there is space, mark the end date for that meeting for a room + update count
            // if there is no space push on queue

        std::vector<int> counts(n, 0);
        std::ranges::sort(meetings);
        std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> endid_heap;
        for (int i = 0; i<n; i++){
            endid_heap.emplace(0, i);
        }

        for (const auto& meeting : meetings){
            // Fast-forward all currently empty rooms to the start time of the new meeting.
            while (!endid_heap.empty() && endid_heap.top().first < meeting[0]) {
                auto room = endid_heap.top();
                endid_heap.pop();
                endid_heap.emplace(meeting[0], room.second);
            }

            // Now, the top room is guaranteed to be either:
            // 1. The lowest ID room available right now.
            // 2. Or the earliest freeing room if all are busy (delayed meeting).
            auto room = endid_heap.top();
            endid_heap.pop();

            long long duration = meeting[1] - meeting[0];
            endid_heap.emplace(room.first + duration, room.second);
            counts[room.second]++;
        }

        int best{0};
        int bestid{0};
        for (int i = n-1; i>=0; i--){
            // should be 1, 2, 2 -> idx 1 wins
            if (counts[i] >= best){
                best = counts[i];
                bestid = i;
            }
        }
        return bestid;
    }
};



