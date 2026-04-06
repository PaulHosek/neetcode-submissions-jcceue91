/*You are given an integer n representing the number of steps to reach the top of a staircase.
 You can climb with either 1 or 2 steps at a time.

- need to go from 0-n
- can go +1 or +2 each time
- paths may overlap
- all paths must end in same position
- all paths must start in same position

Return the number of distinct ways to climb to the top of the staircase.
- count paths
- some paths are the same

First guess: looks like dfs either go 1 or 2 steps, 
    if reach same spot paths from there are always same count
    paths from position i = paths to position i + paths from position i


Inverse: what can I reach from the solution n: How many ways are there from solution n

*/

class Solution {
public:
    int climbStairs(int n) {

        int nrWays_toReach_up1{1};
        int nrWays_toReach_up2{0};
        for (int i = n-1; i>=0; i--){
            // the one from before +1 and the one from 2 before +1
            int cur = nrWays_toReach_up1 + nrWays_toReach_up2;

            nrWays_toReach_up2 = nrWays_toReach_up1;
            nrWays_toReach_up1 = cur;
        }
        return nrWays_toReach_up1;
        
    }
};
