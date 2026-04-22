class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        const int N = arr.size();


        int best{1};
        int cur_down{1};
        int cur_up{1};
        
        for (int i = 1; i<N;i++){
            if (arr[i-1] < arr[i]){
                cur_up = cur_down +1;
                cur_down = 1;
            } else if (arr[i-1] > arr[i]){
                cur_down = cur_up +1;
                cur_up = 1;
            } else {
                cur_down = 1;
                cur_up =1;
            }
            best = std::max({cur_down, cur_up, best});

        }
        return best;

    }


};