class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // std::stack<int> neg;
        // std::stack<int> pos;
        const int N = asteroids.size();


        int left=0;
        int right=1;

        while (right < N){

            if ((asteroids[left] < 0) == (asteroids[right] < 0) || (asteroids[left] < 0 && asteroids[right] > 0)){
                left = right;
                right++;
            } else {
                if (std::abs(asteroids[left]) < std::abs(asteroids[right])){
                    asteroids[left] = 0;
                    left--;
                } else if (std::abs(asteroids[left]) > std::abs(asteroids[right])){
                    asteroids[right] = 0;
                    right++;
                } else {
                    asteroids[right] = 0;
                    asteroids[left] = 0;
                    left--;
                    right++;
                }
            }
            // std::cout << std::endl;
            // for (int a : asteroids){
            //     std::cout << a << " ";
            // }


            while (left >= 0 && asteroids[left]==0){
                left--;
            }
            while (right < N && asteroids[right]==0){
                right++;
            }
            if (left < 0){ // shift entire window
                left = right;
                right++;
            }

        }
        
        std::vector<int> out;
        for (int a : asteroids){
            if (a != 0){
                out.push_back(a);
            }
        }
        return out;
    }
};