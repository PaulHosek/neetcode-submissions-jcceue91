class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res{0};
        for (int i = 0; i < 32; i++){
            // move relevant bit to first position
            // select first bit using & 0001 (1)
            uint32_t placebit = (n>>i) & 1; // take relevant bit and why do &1?
            // shift to correct position back and then do OR to write it unconditionally
            res |= (placebit << (31-i)); 
        }
        return res;
        
    }
};
