class Solution {
public:
/*
- only forward linear scan allowed

[[2,1,5],[3,3,7]]
cap = 4
0 1 2 3 4 5 6 7
  2 2 2 2 2
      3 3 3 3 3

Q: is the max overlap <= capacity
*/
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // assume trips are sorted by from
        // assume same point is not overlapping 

        auto comp = [](const std::vector<int>& t1, const std::vector<int>& t2){
            return t1[1] < t2[1];
        };
        std::sort(trips.begin(), trips.end(), comp);
        using End_Passengers = std::pair<int,int>;
        std::priority_queue<End_Passengers, std::vector<End_Passengers>, std::greater<>> min_heap_ends;
        
        int size{0};
        for (std::vector<int> const& tr : trips){
            const auto& beg = tr[1];
            const auto& end = tr[2];
            const auto& cur_people = tr[0];

            // Step out before step in on same location (overlap on single value is fine)
            while (!min_heap_ends.empty() && min_heap_ends.top().first <= beg){
                size -= min_heap_ends.top().second;
                min_heap_ends.pop();
            }
            size += cur_people;
            min_heap_ends.emplace(end, cur_people);
            if (size > capacity){
                return false;
            }
        }
        return true;
    }
};