class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy{0};
        int sell{0};
        int res{0};

        // both start at 0
        // make l = r if vr < vl -> cheaper buy price
        // otherwise move r
        // stop when r at end
        for (; sell < prices.size(); sell++){
            if (prices[buy] > prices[sell]){
                buy = sell;
            }
            res = std::max(res, prices[sell] - prices[buy]);
        }
        return res;
    }
};
