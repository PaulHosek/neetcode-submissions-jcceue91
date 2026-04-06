class Node {
public:
    vector<std::unique_ptr<Node>> children;
    bool isleaf;
    Node() : children(26), isleaf(false){}
};

class PrefixTree {
public:
    std::unique_ptr<Node> root;
    PrefixTree() {
        root = std::make_unique<Node>();
        
    }
    
    void insert(string word) {
        Node* cur = root.get();
        for (char c : word){
            int i = c - 'a';
            if (cur->children[i] == nullptr){
                cur->children[i] = std::make_unique<Node>();
            }
            cur = cur->children[i].get();
        }
        cur->isleaf = true;
    }
    
    bool search(string word) {
        Node* cur = root.get(); // unique_ptr.get -> non-owning counterpart (i.e., shared ptr -> weak ptr)
        for (const char c : word){
            int i = c - 'a';
            if (cur->children[i] == nullptr){
                return false;
            }
            cur = cur->children[i].get();
        }
        return cur->isleaf;
    }
    
    bool startsWith(string prefix) {
       Node* cur = root.get();
       for (const char c : prefix) {
            int i = c - 'a';
            if (cur->children[i] == nullptr){
                return false;
            }
            cur = cur->children[i].get();
        }
        return true;        
    }
};
