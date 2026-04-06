class Solution {
public:
    int nrbits(int k){
        int c{0};
        while (k != 0){
            k &= k-1;
            c++;
        }
        return c;
    }
    vector<int> countBits(int n) {
        std::vector<int> res(n+1,0);
        for (int i = 1; i <= n; i++){
            res[i] = nrbits(i);
        }
        return res;
    }
};
