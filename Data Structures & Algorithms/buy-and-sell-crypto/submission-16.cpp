class Solution {
public:
    int maxProfit(vector<int>& prices) {



       int l{};
       int r{};
       int best{};
       while (r < prices.size()){
        if (prices[r] > prices[l]){
            best = std::max(best, prices[r] - prices[l]);
        } else {
            l = r;
        }
        r++;
       }
       return best; 
    }
};
