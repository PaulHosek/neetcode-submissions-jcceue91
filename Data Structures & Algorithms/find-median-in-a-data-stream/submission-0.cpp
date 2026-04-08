#include <queue>

class MedianFinder {
public:

/*
max heap on left
min heap on right
of the median
- they are only allowed to be different by 1 in size, otherwise pop the top one and push it onto the other one (pop from the larger one until rebalanced)
- 

*/
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (maxheap.empty()){
            maxheap.push(num);
        } else if (num < maxheap.top()){ // smaller than nearst left -> push onto left
            maxheap.push(num);
            while (maxheap.size() > minheap.size()+1){
                minheap.push(maxheap.top());
                maxheap.pop();
            }
        } else { // same but inverse
            minheap.push(num);
            while (minheap.size() > maxheap.size()+1){
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }
        
    }
    
    double findMedian() {
        if (minheap.size() == maxheap.size()){
            double l = minheap.top();
            double r = maxheap.top();
            return l + (r -l) /2;
        }
        if (maxheap.size() > minheap.size()){
            return maxheap.top();
        }
        return minheap.top();
        
        
    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<>> minheap; // right of the median
    std::priority_queue<int, std::vector<int>, std::less<>> maxheap; // left of the median
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */