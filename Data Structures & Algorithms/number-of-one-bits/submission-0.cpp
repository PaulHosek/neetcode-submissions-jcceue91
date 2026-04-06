// shift is devision by 2
// if 1 on the left end then is uneven
// count every time the number is uneven, shifting until 0

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count{0};
        while (n != 0){
            if (n % 2 == 1){
                count++;
            }
            n = n >> 1;
        }
        return count;

    }
};
