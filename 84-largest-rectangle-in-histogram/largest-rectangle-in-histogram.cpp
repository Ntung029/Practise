class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int result = -1;


        for (int i = 0; i<heights.size(); i++)
        {
            while ((st.top() != -1) && (heights[st.top()]>=heights[i])) 
            {
                // i to st.top() is retangular with height of heights[st.top()];
                int h = heights[st.top()];
                st.pop();
                result = max(result,h*(i-1-st.top()));
            }
            st.push(i);
        }
        int n = heights.size();
        while ((st.top() != -1))
        {
            // i to st.top() is retangular with height of heights[i];
            int r = st.top();
            st.pop();
            result = max(result,heights[r]*(n-1-st.top()));
        }
        return result;
    }
};



class Solution15 {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*  
            
            0 1 2 3 4 5 
            2 1 5 6 2 3

            1 5  2   
        */
        stack<pair<int,int>> st;
        int result = 0;
        st.push({0,-1});
        for (int i = 0; i<heights.size(); i++)
        {
            while ((!st.empty()) && (heights[i] < st.top().first))
            {
                auto h = st.top().first;
                st.pop();
                result = max(result,h * (i-1-st.top().second));
            }
            st.push({heights[i],i});
        }

        while ((!st.empty()) && (st.top().second !=-1))
        {
            auto h = st.top().first;
            st.pop();
            result = max(result,h * ((int)heights.size()-1-st.top().second));
        }

        return result;
    }
};
class Solution13 {
public:
    int largestRectangleArea(vector<int>& heights) {
    // using an increasing stack
    // 1233
    /*            x 
        0 1 2 3 4 5 
        1 2 3 4 2 1

        st: 0 5 
        i: 5
        1 1:  
        4
        12
        6
        1
        4

    */
    stack<int> st;
    st.push(-1);
    int result = 0;
    int n = heights.size();
    for (int i = 0; i< heights.size(); i++)
    {
        if (st.top() == -1)
        {
            st.push(i);
            continue;
        }
        while ((st.top() != -1) &&(heights[i] <= heights[st.top()]))
        {
            int h = heights[st.top()];
            st.pop();
            result = max(result, h* (i-1-st.top()));
        }
        st.push(i);
    }

    while (st.top() != -1)
    {
        int h = heights[st.top()];
          st.pop();
        result = max(result, h* (n-1-st.top()));
      
    }

    return result;
    }
};









class Solution11 {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
        12335   1
        */

        stack<int> st;
        st.push(-1);
        int maxArea = 0;
        for (int i = 0; i <heights.size(); i++)
        {
            if (st.top() == -1)
            {
                st.push(i);
            }
            else
            {
                while ((st.top() != -1) && (heights[st.top()] >= heights[i]))
                {
                    int currHeight = heights[st.top()];
                    st.pop();
                    maxArea = max(maxArea,currHeight*(i-1-st.top()));
                }
            }
            st.push(i);
        }
        int N = heights.size();
        while (st.top() != -1)
        {
             int currHeight = heights[st.top()];
             st.pop();
             maxArea = max(maxArea,currHeight*(N-1-st.top()));   
        }
        return maxArea;
    }
};




class Solution7 {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        st.push(-1);
        int maxArea = 0;

        for (int i = 0; i<heights.size(); i++)
        {
            while ((-1 != st.top()) && (heights[i] <= heights[st.top()]))
            {
                // area is from index st.top()-1 to (i-1) ( exclude heights[i])
                // minHeight is at the start index, which is st.top() 
                int currMinHeight = heights[st.top()];
                st.pop();
                maxArea = max(maxArea,(int) (currMinHeight * (int)(i-1-st.top())));
            }
            st.push(i);
        }
        while (-1!=st.top())
        {
            int currMinHeight = heights[st.top()];
            st.pop();
            maxArea = max(maxArea, (int)(currMinHeight * (heights.size()-1-st.top())));
        }
        return maxArea;
    }
};