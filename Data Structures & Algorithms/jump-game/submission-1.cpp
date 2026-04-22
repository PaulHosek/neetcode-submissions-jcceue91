class Solution {
public:
    bool canJump(vector<int>& nums) {


        const int N = nums.size();
        if (N == 1){
            return true;
        }

        int next = N-1;
        for (int i = N-2; i >= 0; i--){
            if (nums[i] >= next - i){
                next = i;
            }
        }
        return next == 0;

    }
};
