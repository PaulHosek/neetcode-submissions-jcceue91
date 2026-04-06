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
        auto pw = [](auto self, int x, int n)->int{
            if (x == 0) return 0;
            if (n == 0) return 1;

            double res = self(self, x, n /2);
            res = res * res;
            return n % 2 ? x * res : res;

        };

        pw(pw, x, std::abs(n));

        if (n < 0){
            return 1.0 / out;
        }
        return out;
        
    }
};
