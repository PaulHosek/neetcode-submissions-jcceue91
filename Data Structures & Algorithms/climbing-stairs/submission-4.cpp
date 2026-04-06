class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2){
            return n;
        }
        // can reach state n +1 from last and second to last
        // reverse array same as non reverse
        std::vector<int> nrways_at(n);
        int oneup = 2;
        int twoup = 1;
        for (int i = n-3; i >= 0; i--){

            // new twoup is the old oneup
            // new one up is twoup + oneup
            int temp = oneup; 
            oneup += twoup;
            twoup = temp;
        }
        return oneup;
    }
};

// Version 1
// // can reach state n +1 from last and second to last
// // reverse array same as non reverse
// std::vector<int> nrways_at(n);
// nrways_at[n-1] = 1;
// nrways_at[n-2] = 2;
// for (int i = n-3; i >= 0; i--){
//     nrways_at[i] = nrways_at[i+1] + nrways_at[i+2];
// }
// return nrways_at[0];