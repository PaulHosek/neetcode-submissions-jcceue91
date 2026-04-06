



class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if (amount == 0){
            return 0;
        }

        // reccurance relation: find coins to make up small amount
        vector<int> nrcoins(amount+1, amount+1);
        nrcoins[0] = 0;
        for (int a = 1; a <=amount; a++){
            for (int c : coins){
                if (c <= a){
                    // +1 if want to use the coin from below
                    nrcoins[a] = std::min(nrcoins[a], nrcoins[a - c] + 1);
                }
            }
        }
        return nrcoins[amount] == amount+1 ? -1 : nrcoins[amount];
        
    }
};

















