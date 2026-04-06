class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity) {}

    int get(int key) {
        if (!map_.contains(key)) {
            return -1;
        }
        auto it = map_[key];                    // copy iterator first (safer)
        if (it != nodes_.begin()) {             // <-- this is the fix
            nodes_.splice(nodes_.begin(), nodes_, it);
        }
        map_[key] = nodes_.begin();             // now guaranteed to be front
        return nodes_.front().second;
    }

    void put(int key, int value) {
        if (!map_.contains(key)) {
            nodes_.push_front({key, value});
            map_[key] = nodes_.begin();
            if (nodes_.size() > capacity_) {
                remove_last();
            }
        } else {
            auto it = map_[key];
            if (it != nodes_.begin()) {         // <-- also guard the update path
                nodes_.splice(nodes_.begin(), nodes_, it);
            }
            map_[key] = nodes_.begin();
            map_[key]->second = value;          // or nodes_.front().second = value;
        }
    }

private:
    void remove_last() {
        int key_last = nodes_.back().first;     // copy by value (tiny safety)
        map_.erase(key_last);
        nodes_.pop_back();
    }

    using Node = std::pair<int, int>;
    std::list<Node> nodes_;
    std::unordered_map<int, std::list<Node>::iterator> map_;
    size_t capacity_;
};