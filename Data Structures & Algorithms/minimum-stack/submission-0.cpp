class MinStack {
public:
    MinStack() {
        }
    
    void push(int val) {
        if (mins_.empty()) [[unlikely]]{
            mins_.push_back(val);
        } else {
            mins_.push_back(std::min(mins_.back(),val));
        }   

        data_.push_back(val);
    }
    
    void pop() {
        data_.pop_back();
        mins_.pop_back();
    }
    
    int top() {
        return data_.back();
    }
    
    int getMin() const {
        return mins_.back();
    } 

private:
    std::vector<int> data_{};
    std::vector<int> mins_{};
};
