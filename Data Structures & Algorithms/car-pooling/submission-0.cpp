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
        // assume same point is not overlapping 

        std::array<int,1001> diff;
        diff.fill(0);

        for (std::vector<int> const& tr : trips){
            const auto& cur_people = tr[0];
            const auto& beg = tr[1];
            const auto& end = tr[2];

            diff[beg] += cur_people;
            diff[end] += -cur_people;
        }

        int size{0};
        for (int v : diff){
            size += v;

            if (size > capacity){
                return false;
            }
        }
        return true;
    }
};
