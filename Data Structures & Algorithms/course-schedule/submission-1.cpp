class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);

        for (const auto& pre : prerequisites){
            adj[pre[0]].push_back(pre[1]);
            indegree[pre[1]]++;
        }

        queue<int> q;
        for(int i =0; i <numCourses; i++){
            if (indegree[i] == 0){ // no requirements on this node
                q.push(i); // push this node
            }
        }

        int finish = 0;
        while (!q.empty()){
            int node = q.front();
            q.pop();
            finish++;
            for (int neigh : adj[node]){
                indegree[neigh]--;
                if (indegree[neigh] == 0){
                    q.push(neigh);
                }
            }

        }

        return finish == numCourses;
    }
};
