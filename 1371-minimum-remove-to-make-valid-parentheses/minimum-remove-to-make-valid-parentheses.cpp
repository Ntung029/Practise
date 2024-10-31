class Solution {
public:
    string minRemoveToMakeValid(string s)
{
    /*
        (())  ())()((())))
        ()(())()(
    */

    //using left, right
    int left = 0;
    int right = 0;
    vector<bool> isRemove(s.length(),0);
    for (int i = 0; i<s.length(); i++)
    {
        if (s[i] == '(') left++;
        else if (s[i] == ')') right++;
        else continue;
        if (left < right)
        {
            isRemove[i] = true;
            left = 0;
            right = 0;
        }
    }

    left = 0;
    right = 0;
    for (int i = s.length()-1; i>=0; i--)
    {
        if (s[i] == '(') left++;
        else if (s[i] == ')') right++;
        else continue;
        if (left > right)
        {
            isRemove[i] = true;
            left = 0;
            right = 0;
        }
    }

    string result;
    for (int i = 0; i< s.length(); i++)
    {
        if (!isRemove[i])
        {
            result+=s[i];
        }
    }
    return result;
}
};


class Solution2 {
public:


    string minRemoveToMakeValid(string s)
{
  stack<int> st;
  unordered_set<int> result;
  string strResult;

  for (int i = 0; i<s.length(); i++)
  {
    if (s[i] == '(')
    {
      st.push(i);
    }
    else if ( s[i] == ')')
    {
      if (st.empty())
      {
        result.insert(i);
      }
      else
      {
        st.pop();
      }
    }
    else
    {
      continue;
    }
  }
  while (!st.empty())
  {
    result.insert(st.top());
    st.pop();
  }
  for (int i = 0; i<s.length(); i++)
  {
    if (result.end() == result.find(i))
    {
      strResult += s[i];
    }
  }
  return strResult;
}

};