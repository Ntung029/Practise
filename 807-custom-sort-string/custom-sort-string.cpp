class Solution {
public:
    string customSortString(string order, string s) {
        unordered_set<char> st;
        unordered_map<char,int> mp;
        for (auto ch: order)
        {
            st.insert(ch);
        }

        string result;
        for (auto ch:s)
        {
            if (st.end() == st.find(ch))
            {
                result+=ch;
            }
            else
            {
                mp[ch]++;
            }
        }


        for (auto ch:order)
        {
            if (mp.end() != mp.find(ch))
            {
                for (int i = 0; i<mp[ch]; i++)
                {
                    result+=ch;
                }
            }
        }
        return result;
    }
};