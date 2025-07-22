class MedianFinder {
public:
    priority_queue<int> leftmaxheap;
    priority_queue<int, vector<int>, greater<int>> rightminheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(leftmaxheap.empty() || num < leftmaxheap.top()){
            leftmaxheap.push(num);
        }
        else{
            rightminheap.push(num);
        }

        if(abs((int)leftmaxheap.size() - (int)rightminheap.size()) > 1){
            rightminheap.push(leftmaxheap.top());
            leftmaxheap.pop();
        }
        else if(leftmaxheap.size() < rightminheap.size()){
            leftmaxheap.push(rightminheap.top());
            rightminheap.pop();
        }

        
    }
    
    double findMedian() {
        if(leftmaxheap.size() == rightminheap.size()){
            return (double) (leftmaxheap.top() + rightminheap.top()) /2;
          
        }
        else{
            return leftmaxheap.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */