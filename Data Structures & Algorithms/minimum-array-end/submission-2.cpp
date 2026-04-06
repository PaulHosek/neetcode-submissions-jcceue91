class Solution {
public:

/*



Goal: Find the min last value

Binary search + greedy backwards

00010
00011
00110

Greedy match

Find the least significant position that has a 1, that should be only set on the first one.
k & k+1 = only 1 bit set, the most significant one

00001
00110 XOR -> 00111

00010
00110
00100


Must all have at least these bits set.
Make x, then increment but those bits cannot be flipped to 0 so flip back.

*/
    long long minEnd(int n, int x) {
        long long last = static_cast<long long>(x);
        for (int i = 1; i<n ;i++){
            last = (last +1 | x);
        }
        return last;
        
    }
};