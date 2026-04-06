class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k_(k) {
        for (int n : nums){
            add(n);
        }
    }
    
    int add(int val) {
        // add the int
        // returns the kth largest
        if (min_heap_.empty()){
            min_heap_.push(val);
            return val;
        }

        if (val > min_heap_.top() || min_heap_.size() < k_){
            min_heap_.push(val);
        } 
        if (min_heap_.size() > k_){
            min_heap_.pop();
        }
        return min_heap_.top();
        
    }

private:

    // use the min heap to only push elements that are larger than the current top
    // the min heap will be used to check the least fitting item (e.g., at position k = top)
        
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap_{};
    int k_;


};
