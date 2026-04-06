#include <array>
#include <memory>
#include <string>

class TrieNode {
public:
    std::array<std::unique_ptr<TrieNode>, 26> children{}; // Assuming lowercase English letters 'a' to 'z'
    bool isEndOfWord = false;
};

class PrefixTree {
public:
    std::unique_ptr<TrieNode> root;

    PrefixTree() : root(std::make_unique<TrieNode>()) {}

    void insert(const std::string& word) {
        TrieNode* cur = root.get();
        for (char c : word) {
            int i = c - 'a'; 
            if (i < 0 || i >= 26) {
                throw std::invalid_argument("Must be lower case letter a-z.");
            }
            if (!cur->children[i]) {
                cur->children[i] = std::make_unique<TrieNode>();
            }
            cur = cur->children[i].get();
        }
        cur->isEndOfWord = true;
    }

    bool search(const std::string& word) {
        TrieNode* cur = root.get();
        for (char c : word) {
            int i = c - 'a';
            if (i < 0 || i >= 26 || !cur->children[i]) {
                return false;
            }
            cur = cur->children[i].get();
        }
        return cur->isEndOfWord;
    }

    bool startsWith(const std::string& prefix) {
        TrieNode* cur = root.get();
        for (char c : prefix) {
            int i = c - 'a';
            if (i < 0 || i >= 26 || !cur->children[i]) {
                return false;
            }
            cur = cur->children[i].get();
        }
        return true;
    }
};