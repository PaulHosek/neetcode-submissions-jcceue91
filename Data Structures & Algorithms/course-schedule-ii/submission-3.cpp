class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> out(numCourses);
        if (prerequisites.empty()){
            std::iota(out.begin(), out.end(), 0);
            return out;
        }
        vector<int> incon(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        std::queue<int> q{};

        for (const auto& pre : prerequisites){
            adj[pre[1]].push_back(pre[0]);
            incon[pre[0]]++;
        }

        for (int i = 0; i < numCourses; i++){
            if (incon[i] == 0){
                q.push(i);
            }
        }


        int valid{0};
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            valid++;
            out.push_back(cur);
            for (const auto& nei : adj[cur]){
                incon[nei]--;
                if (incon[nei] == 0){
                    q.push(nei);
                }
            }
        }


        if (valid == numCourses){
            return out;
        }
        return {};

    }
};
