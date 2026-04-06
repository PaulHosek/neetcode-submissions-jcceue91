#include <queue>
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int, std::vector<int>, std::less<int>> maxheap(stones.begin(), stones.end());

        while (maxheap.size() > 1){
            int x = maxheap.top();
            maxheap.pop();
            int y = maxheap.top();
            maxheap.pop();
            int res = std::abs(y - x);
            if (res){
                maxheap.push(res);
            }
        }

        if (maxheap.size()){
            return maxheap.top();
        }
        return 0;
    }

};
