class LRUCache {
public:
    LRUCache(int capacity) : capacity_(capacity){
        
    }
    
    int get(int key) {
        if (!map_.contains(key)){
            return -1;
        }

        auto nodecpy = *map_[key];
        nodes_.erase(map_[key]);
        nodes_.push_front(nodecpy);
        map_[key] = nodes_.begin();

        return nodes_.front().second;
    }
    
    void put(int key, int value) {
        if (map_.contains(key)){
            nodes_.erase(map_[key]);
        }

        if (nodes_.size() >= capacity_){
            remove_last();
        }

        nodes_.push_front({key, value});
        map_[key] = nodes_.begin();
    }
private:
    void remove_last(){
        const auto& key_last = nodes_.back().first;
        map_.erase(key_last);
        nodes_.pop_back();
    }
    using Node = std::pair<int,int>; // 

    std::list<Node> nodes_;
    std::unordered_map<int, std::list<Node>::iterator> map_; // Know keys will be ints 
    size_t capacity_;

};
