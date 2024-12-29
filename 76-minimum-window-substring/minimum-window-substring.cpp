class Solution{
public:
    string minWindow(string s, string t)
    {
        if (t.length() > s.length())      return "";
        
        unordered_map<char, int> mp;
        for (auto ch:t)
        { 
            mp[ch]++;
        }
        
        int count = mp.size(); // number of distinct chars
        int left = -1;
        int start = 0;
        int result = INT32_MAX;
        
        for (int i = 0; i<s.length(); i++)
        {
            mp[s[i]]--;
            if (mp[s[i]] == 0)
            {
                count--;
            }    
            while (count == 0)
            {
                if (result > i - start+1)
                {
                    result = i-start+1;
                    left = start;
                    
                }
                
                mp[s[start]]++;
                if (mp[s[start]] >0)
                {
                    count++;
                }
                start++;
            }
                
            
        }
        
        return left == -1 ? "" : s.substr(left,result);
    }
};



class Solution15{
public:
    string minWindow(string s, string t)
    {
        
        if (t.length() > s.length()) return "";
        unordered_map<char,int> mp;
        for (auto ch:t)
        {
            mp[ch]++;
                
        }
        int count = mp.size();
        int start = 0;
        int minLen = INT32_MAX;
        int idx = -1;
        
        for (int i = 0; i<s.length(); i++)
        {
           
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    count--;
                }
                
                while ((count == 0) && (start<=i))
                {
                    if (i-start+1 < minLen)
                    {
                        minLen =i-start+1;
                        idx = start;
                    }
                    mp[s[start]]++;
                    if (mp[s[start]] >0 ) count++;
                    start++;
                }
        }
        string result;
        return (idx == -1) ? result: s.substr(idx,minLen);
    }
};






class Solution13{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char,int> mp;
        int count = 0;
        for (const auto& ch:t)
        {
            mp[ch]++;
        }
        count = mp.size();
        int l = 0;
        
        int result = INT32_MAX;
        int startIdx = 0;
        
        for (int i = 0; i< s.length(); i++)
        {
            mp[s[i]]--;
            if (mp[s[i]] == 0) count--;
            while ((count == 0) && (l<=i))
            {
                if ((i-l+1) < result)
                {
                    result = i-l+1;
                    startIdx = l;
                }
                // shorten the windows from the left side
                mp[s[l]]++;
                if (mp[s[l]] > 0) count++;
                l++;
            }
        }
        
        if (result == INT32_MAX)
        {
            return "";
        }
        else
        {
            return s.substr(startIdx,result);
        }
        
    }
};


class Solution2 {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> charT;
        int count = 0;
        
        for (const auto& ch:t)
        {
            if (charT.end() == charT.find(ch)) count++;
            charT[ch]++;
        }
        

        int l = 0;
        int ret = INT32_MAX;
        int start = 0;
        for (int r = 0; r < s.length(); r++)
        {
            charT[s[r]]--;
            // when a character in t is covered in the range [l,r]
            if (0 == charT[s[r]])
            {
                count--;
            }
            
            // all characters in t is covered in rang [l,r]: try to shorten l
            if (count == 0)
            {
                while ((l<=r) && (count == 0))
                {
                    if (r-l+1 < ret)
                    {
                        ret = r-l+1;
                        start = l;
                    }
                    
                    charT[s[l]]++;
                    if (charT[s[l]]>0)
                    {
                        count++;
                    }
                    l++;
                }
            }
        }
        
        if (ret ==INT32_MAX) return "";
        else
        {
            return s.substr(start,ret);
        }
    }
};