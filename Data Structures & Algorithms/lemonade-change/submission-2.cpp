class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c20 = 0;
        int c10 = 0;
        int c5 = 0;

        for (int b : bills){
            if (b == 5){
                c5++;
            } else if (b == 10){
                c10++;
                c5--;
                if (c5 < 0){
                    return false;
                }
            } else if (b == 20){
                c20++;
                if (c10 >= 1 && c5 >= 1){
                    c5 -= 1;
                    c10--;
                } else if (c5 >= 3) {
                    c5 -= 3;
                } else {
                    return false;
                }
            }


        }
        return true;
        
    }
};