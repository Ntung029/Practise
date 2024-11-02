class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_set<char> isUsed;
        unordered_map<char,int> lastPos;
        for (int i = 0; i<s.length(); i++)
        {
            lastPos[s[i]] = i; // last position of charactor
        }
        stack<char> st;


        // bcabc
        // bca

        for (int i = 0; i<s.length(); i++ )
        {
            if (isUsed.end() == isUsed.find(s[i]))
            {
                // char at i is not used
                // remove characters in the stack if it is greater than
		        // the current character and last position is after
                // the current character
                
                while (!st.empty() && (s[i] < st.top()) && (lastPos[st.top()] >i))
                {
                    isUsed.erase(st.top());
                    st.pop();
                }
                st.push(s[i]);
                isUsed.insert(s[i]);
            }
        }

        string result;
        while (!st.empty())
        {
            result = st.top()+result;
            st.pop();
        }
        return result;
    }
};



class Solution2 {
public:
    string removeDuplicateLetters(string s) {
        unordered_set<char> isUsed;
        unordered_map<char,int> lastPos;
        int N = s.length();
        for (int i = 0; i<N; i++)
        {
            lastPos[s[i]] = i;
        }

        stack<char> st;
        for (int i = 0; i<N; i++)
        {
            
            cout << s[i] << endl;
            if (isUsed.end() == isUsed.find(s[i]))
            {
                // char at i is not used
                // remove characters in the stack if it is greater than
                // the current character and last position is after
                // the current character
                while ((!st.empty()) && (s[i] < st.top()))
                {
                    if (lastPos[st.top()] >  i)
                    {
                        // remove st top
                        isUsed.erase(st.top());
                        st.pop();
                    }
                    else
                    {
                        break;
                    }
                }
                
                st.push(s[i]);
                isUsed.insert(s[i]);
            }
        }

        string result;
        while (!st.empty())
        {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};