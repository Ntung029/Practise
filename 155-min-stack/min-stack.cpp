class MinStack {
    public:
        void push(int val){
            st.push(val);
            // update min stack
            if (minSt.empty())
            {
                minSt.push({val,1});
                return;
            }
            int minVal = minSt.top().first;
            if (val == minVal)
            {
                minSt.top().second++;
            }
            else if (val <minVal)
            {
                minSt.push({val,1});
            }
        }

        void pop()
        {
            if (st.empty()) return;
            int value = st.top();
            st.pop();
            if (value == minSt.top().first)
            {
                minSt.top().second--;
                if (minSt.top().second == 0) minSt.pop();
            }
        }

        int top()
        {
            if (st.empty()) return INT32_MIN;
            return st.top();
        }

        int getMin()
        {
            if (st.empty()) return INT32_MIN;
            return minSt.top().first;
        }

        MinStack(){};

    private:
        stack<int> st;
        stack<pair<int,int>> minSt;    
};

class MinStack5 {
    public:
        void push(int val)
        {
            if (st.empty())
            {
                minVal.push_back(val);
            }
            else
            {
                if (val<minVal.back())
                {
                    minVal.push_back(val);
                }
                else
                {
                    minVal.push_back(minVal.back());
                }
            }
            
            st.push(val);
        }
    
        void pop()
        {
            // remove the last element
            if (!st.empty())
            {
                st.pop();
                minVal.pop_back();
            }
        }
    
        int getMin()
        {
            if (!minVal.empty())
            {
                return minVal.back();
            }
            return INT32_MIN;
        }
    
        int top()
        {
            if (!st.empty())
            {
                return st.top();
            }
            return INT32_MIN;
        }
    
    private:
        stack<int> st;
        vector<int> minVal;    
};


class MinStack3 {
    
    /*
        push, pop, top, getMin:
        4 5 3 6 7
        4 5 3 6 7  
        4 4 3 3 3
        4 5 3 6 3 7  
        4,1 3,2
        
    */
    public:
        void push(int n)
        {
            st.push(n);
            if (minVal.empty())
            {
                minVal.push({n,1});
            }
            else
            {
                auto currMin = minVal.top().first;
                if (currMin > n)
                {
                    minVal.push({n,1});
                } 
                else if (currMin == n)
                {
                    minVal.top().second++;
                }
            } 
        }
    
        void pop()
        {
            if ((st.empty()) || (minVal.empty()))
            {
                return;
            }
            
            int n = st.top();
            st.pop();
            
            auto currMin = minVal.top().first;
            if (n==currMin)
            {
                minVal.top().second--;
                if (minVal.top().second == 0)
                {
                    minVal.pop();
                }
            }
        }
    
        int top()
        {
            if ((st.empty()) || (minVal.empty()))
            {
                return INT32_MIN;
            }
            return st.top();
        }
    
    
        int getMin()
        {
            if ((st.empty()) || (minVal.empty()))
            {
                return INT32_MIN;
            }
            return minVal.top().first;
        }
    private:
        stack<int> st;
        stack<pair<int,int>> minVal;
};


class MinStack2 {
public:
    MinStack2() {
        
    }
    
    void push(int val) {
        st.push(val);
        if (minSt.empty()) minSt.push({val,1});
        else
        {
           if (minSt.top().first > val)
           {
               minSt.push({val,1});
           }
           else if (minSt.top().first == val)
           {
               // increase the number of val in the min Stack
               minSt.top().second++;
           }
        }
            
    }
    
    void pop() {
        //
        int val = st.top();
        st.pop();
        if (val == minSt.top().first)
        {
            minSt.top().second--;
            if (0 == minSt.top().second)
            {
                minSt.pop();
            }
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top().first;
    }

    
private:
    std::stack<int> st;
    std::stack<pair<int,int>> minSt;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */