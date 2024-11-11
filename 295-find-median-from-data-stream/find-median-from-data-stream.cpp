class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (minSt.empty())
        {
            minSt.push(num);
        }
        else if (num<= minSt.top())
        {
            minSt.push(num);
        }
        else
        {
            greSt.push(num);
        }
        balanceHeaps();
    }
    
    
    
    double findMedian() {
        if (minSt.size() == greSt.size())
        {
            return (double)(minSt.top() + greSt.top())/ 2.0;
        }
        else
        {
            return minSt.top();
        }
    }
    
private:
    priority_queue<int> minSt;
    priority_queue<int,vector<int>,greater<int>> greSt;
    
    void balanceHeaps()
    {
        if (minSt.size() > greSt.size() +1)
        {
            greSt.push(minSt.top());
            minSt.pop();
        }
        else if (minSt.size() < greSt.size())
        {
            minSt.push(greSt.top());
            greSt.pop();
        }
            
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */