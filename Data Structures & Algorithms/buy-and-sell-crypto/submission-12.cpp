class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int p{0};
        int r{1};
        int l{0};
        while (r < prices.size()){
            auto& pr = prices[r];
            auto& pl = prices[l];
            p = std::max(p, pr-pl);
            if (pr < pl){
                l = r;
            } 
            r++;

        }
        return p;
        
    }
};
