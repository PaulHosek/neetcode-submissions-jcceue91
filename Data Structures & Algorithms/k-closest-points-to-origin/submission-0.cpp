#include <queue>
#include <cmath>
struct OriginDist{
    double dist_orig(const int x, const int y){
        return std::sqrt(std::pow(x, 2) + std::pow(y,2));
    }
    // bool smaller_dist(const std::vector<int>& p1, const std::vector<int>& p2){
    //     return dist_orig(p1[0], p1[1]) > dist_orig(p2[0], p2[1]);
    // }
    bool operator()(const std::vector<int>& p1, const std::vector<int>& p2){
        return dist_orig(p1[0], p1[1]) < dist_orig(p2[0], p2[1]);
    }
};
class Solution {
public:
    


    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // NOTE: since want multiple ones red-black tree may be better for large sets?
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, OriginDist> distqueue{};
        for (const auto& p : points){
            distqueue.push(p);
            if (distqueue.size() > k){
                distqueue.pop();
            }
        }
        std::vector<std::vector<int>> out(k);
        for (int i = 0; i < k; i++){
            out[i] = (distqueue.top());
            distqueue.pop();
        }
        return out;



    



    }
};
