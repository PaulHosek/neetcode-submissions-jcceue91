class Solution {
public:
    double myPow(double x, int n) {
        double out{x};
        if (n == 0){
            return 1;
        } else if (n == 1){
            return x;
        }
        for (int i = 0; i< std::abs(n)-1; i++){
            out *= x;
        }
        if (n < 0){
            return 1.0 / out;
        }
        return out;
        
    }
};
