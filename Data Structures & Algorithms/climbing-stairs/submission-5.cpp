class Solution {
public:
    int climbStairs(int n) {
        if (n == 1){
            return 1;
        }
        int twodown{1};
        int onedown{2};
        for (int i = 3; i <= n; i++){
            std::swap(onedown, twodown);
            onedown += twodown;
        }
        return onedown;

    }
};