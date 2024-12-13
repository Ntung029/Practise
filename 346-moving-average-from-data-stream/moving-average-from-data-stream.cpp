class MovingAverage {
public:
    MovingAverage(int size) {
        cap = size;
        total = 0;
    }
    
    double next(int val) {
        qu.push(val);
        total+=val;
        if (qu.size()>cap)
        {
            total-=qu.front();
            qu.pop();
        }
        return (double)total/qu.size();
    }
private:
    queue<int> qu;
    int cap;
    int total;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */