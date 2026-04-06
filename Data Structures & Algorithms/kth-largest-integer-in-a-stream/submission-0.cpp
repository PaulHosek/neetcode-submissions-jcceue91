#include <queue>
class KthLargest {
public:

    KthLargest(int k, vector<int>& nums) : 
     k_(k),
     min_heap_(nums.begin(), nums.end())
    {}
    
    int add(int val) {
        min_heap_.push(val);

        if (k_ > min_heap_.size()){
            return 0;
        }
        while (k_ < min_heap_.size()){
            min_heap_.pop();
        }
        return min_heap_.top();
        
    }
private:    
    int k_;
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap_;
};
