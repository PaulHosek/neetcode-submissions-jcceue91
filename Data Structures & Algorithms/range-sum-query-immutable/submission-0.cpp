class NumArray {
public:
    NumArray(vector<int>& nums) : prefix_sum_(nums.size()), nums_(nums){
        prefix_sum_[0] = nums[0];
        for (int i = 1; i<nums.size(); i++){
            prefix_sum_[i] = prefix_sum_[i-1] + nums[i];
        }


    }
    
    int sumRange(int left, int right) {
        // inclusive and may overlap
        return prefix_sum_[right] - prefix_sum_[left] + nums_[left];

    }
private:
std::vector<int> prefix_sum_;
std::vector<int> nums_;

};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */