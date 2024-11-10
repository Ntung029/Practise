class Solution {
public:

    void DFS(int start, const string& s, unordered_set<string>& st, int& result, int count)
    {
          if (start>=s.length())
          {
            result = max(result,count);
            return;
          }

          for (int end = start+1; end <= s.length(); end++)
          {
            string str = s.substr(start,end-start);
            if (st.end() == st.find(str))
            {
                st.insert(str);
                count++;
                DFS(end,s,st,result,count);
                count--;
                st.erase(str);
            }
          }
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        int result = 0;
        DFS(0,s,st,result,0);
        return result;
    }
};