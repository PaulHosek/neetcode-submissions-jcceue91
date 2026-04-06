class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        vector<unordered_set<int>> req(numCourses);
        unordered_set<int> vis{};
        for (const auto& v : prerequisites){
            req[v[0]].insert(v[1]);
        }

        for (int i =0; i< numCourses; i++){
            if (!req[i].empty()){
                if (!dfs(req, vis, i)){
                    return false;
                }
            }
            vis.clear();
        }

        return true;
        
    }

    bool dfs(vector<unordered_set<int>>& req,unordered_set<int>& vis, int idx){
        // base case: if find nothing, pop from all upstream

        if (req[idx].empty()){
            return true;
        } else if (vis.count(idx)){
            return false; // cycle
        }
        vis.insert(idx);


        vector<int> pop_list{};
        
        for (const auto& pre : req[idx]){
            bool pop_prev = dfs(req, vis, pre);
            if (pop_prev){
                pop_list.push_back(pre);
            }
        }

        for (const auto& v : pop_list){
            req[idx].erase(v);
        }

        return req[idx].empty();
    }
};
