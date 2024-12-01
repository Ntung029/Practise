class Solution {
public:
    bool isDigit(char ch)
    {
        return ((ch>='0') && (ch<='9'));
    }

    int calculate(string s) {
        stack<int> st;
        std::string::iterator end_pos = std::remove(s.begin(), s.end(), ' ');
        s.erase(end_pos, s.end());

        int num = 0;
        char prevSign = '+';
        for (int i = 0; i< s.length(); i++)
        {
            auto ch = s[i];

            if (isDigit(ch))
            {
                num = num*10+(ch-'0');
            }

            if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/') || (i == s.length()-1))
            {
                cout << i << endl;
                if (prevSign == '+')
                {
                    st.push(num);
                }
                else if (prevSign == '-')
                {
                    st.push(-num);
                }
                else if (prevSign == '*')
                {
                    if (st.empty())
                    {
                        return INT32_MIN;
                    }
                     
                    int val = st.top()*num;
                    st.pop();
                    st.push(val);
                } else if (prevSign == '/')
                {
                    if (st.empty())
                    {
                        return INT32_MIN;
                    } 
                    int val = st.top()/num;
                    st.pop();
                    st.push(val);
                }
                prevSign = ch;
                num = 0;
            }
            else if (!isDigit(ch))
            {
                return INT32_MIN;
            }
        }

        int result = 0;
        while (!st.empty())
        {
            result += st.top();
            st.pop();
        }
        return result;
    }
};