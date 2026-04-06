/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* parent, Node* out, vector<Node*>& visited){
        if(!parent){
            return;
        }

        visited[parent->val] = out;
        for (const auto& n : parent->neighbors){
            if (visited[n->val]){
                // cloned already, only link up
                out->neighbors.push_back(visited[n->val]);
            } else{
                // create child node, add parent as its neighbor and add it as neigbor to parent
                Node* child = new Node(n->val);
                out->neighbors.push_back(child);
                dfs(n, child, visited);
            }
        }

    }
    Node* cloneGraph(Node* node) {
        if (!node){
            return nullptr;
        }
        Node* out = new Node(node->val);

        vector<Node*> visited(101, nullptr);

        dfs(node, out, visited);
        return out;
        
    }
};
        // vector<bool> visited{100, false}; // assume val is unique identifier of node
        // visited[node.val] = true;