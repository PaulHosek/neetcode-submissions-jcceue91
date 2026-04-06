class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int maxP = 0;
        int l = 0;
        int r = 0;
        while (r < prices.size()){
            if (prices[r] > prices[l]){
                maxP = max(maxP, prices[r]-prices[l]);
            } else {
                l = r;
            }
            r++;
        }
        return maxP;
        
    }
};


// [4,2,3,55,2,52]
