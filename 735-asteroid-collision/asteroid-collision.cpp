class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids)
    {
        stack<int> st;
        for (auto& asteroid:asteroids)
        {
            bool flag = true;
            while (!st.empty() && (asteroid<0) && (st.top()>0))
            {
                if (abs(asteroid) > st.top())
                {
                    st.pop();
                }
                else  if (abs(asteroid) == st.top())
                {
                    st.pop();
                    flag = false;
                    break;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                st.push(asteroid);
            }
        }

        vector<int> result;
        while (!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

class Solution2 {
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