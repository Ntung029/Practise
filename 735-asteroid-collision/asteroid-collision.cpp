class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // 1 3 5

        int n = asteroids.size();
        // using stack
        stack<int> st;
        
        for (auto asteroid:asteroids)
        {
            bool flag = true;
            while (!st.empty() && (st.top()>0) && (asteroid<0))
            {
                if (abs(st.top())<abs(asteroid))
                {
                    st.pop();
                    continue;
                }
                else if (abs(st.top())==abs(asteroid))
                {
                    st.pop();
                }
                flag = false;
                break;
            }
            if (flag)
            {
                st.push(asteroid);
            }
        }

        vector<int> result(st.size());
        int k = st.size()-1;
        while (!st.empty())
        {
            result[k] = st.top();
            st.pop();
            k--;
        }
        return result;
    }
};