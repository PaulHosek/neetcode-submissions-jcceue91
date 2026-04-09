class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<>> minheap;

        for (int v : nums){
            if (minheap.size() < k){
                minheap.push(v);
                continue;
            }

            if (minheap.top() < v){
                minheap.push(v);
                if (minheap.size() > k){
                    minheap.pop();
                }
            }

        } 
        return minheap.top();
    }
};
