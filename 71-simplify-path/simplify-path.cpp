class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        stringstream ss(path);
        string temp;
        while (getline(ss,temp,'/'))
        {
            if (temp == "..")
            {
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else if ((temp != ".") && (!temp.empty()))
            {
                st.push(temp);
            }
        }

        string res;
        while (!st.empty())
        {
            res = "/"+ st.top() + res;
            st.pop();
        }
        if (res.empty())
        {
            return "/";
        }
        return res;
    }
};