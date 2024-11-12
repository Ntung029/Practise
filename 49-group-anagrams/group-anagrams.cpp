class Solution {
    public:
         
        string encode(const auto& s)
        {
            int arr[26]{0};
            for (const auto ch:s)
            {
                arr[ch-'a']++;
            }
            string result;
            for (int i = 0; i<26; i++)
            {
                
                result+="#" + to_string(arr[i]);
            }
            return result;
        }
        vector<vector<string>> groupAnagrams(vector<string>& strs)
         {
             unordered_map<string,vector<string>> mp;
             for (const auto& s:strs)
             {
                 auto encodeS = encode(s);
                 mp[encodeS].push_back(s);
             }
             
             vector<vector<string>> result;
             for (const auto& it:mp)
             {
                 result.push_back(it.second);
             }
             return result;
         }
};

class Solution23 {
public:
    string encode(const string& str)
    {
        int arr[26]{};
        for (auto ch:str)
        {
            arr[ch-'a']++;
        }

        string encodeStr;
        for (int i = 0; i<26; i++)
        {
            encodeStr = encodeStr + "#" + to_string(arr[i]);
        }
        return encodeStr;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string,vector<string>> mp;
        for (const auto& str:strs){
            auto encodeStr = encode(str);
            mp[encodeStr].push_back(str);
        }

        vector<vector<string>> result;
        for (const auto& it:mp)
        {
            result.push_back(it.second);
        }
        return result;
    }
};

class Solution15 {
public:
    static constexpr int N = 27;
    string encode(const string& s)
    {
        int arr[27]{0};
        for (const auto& ch:s)
        {
            arr[ch-'a']++;
        }
        string encodeS;
        for(int i = 0; i<N; i++)
        {
            encodeS+='#';
            if (arr[i] >0)
            {
                encodeS+=to_string(i);
            }
        }
        return encodeS;
    }
    
    
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string,int> mp;
        vector<vector<string>> result;
        for (const auto& str:strs)
        {
            auto encodeS = encode(str);
            if (mp.end() == mp.find(encodeS))
            {
                result.push_back({str});
                mp[encodeS] = result.size()-1;
            }
            else
            {
                result[mp[encodeS]].push_back(str);
            }
        }
        return result;
    }
};


class Solution13 {
public:
    static constexpr int N = 27;
    string encode(const string& str)
    {
        vector<int> arr(N,0);
        for (const auto& ch:str)
        {
            arr[ch-'a']++;
        }
        string result;
        for (const auto& num:arr)
        {
            result+= '#' + to_string(num);
        }
        return result;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> mp;
        vector<vector<string>> result;
        int i  = 0;
        for (const auto& str:strs)
        {
            auto encodeStr = encode(str);
            if (mp.find(encodeStr) == mp.end())
            {
                result[mp[encodeStr]].push_back(str);
            }
            else
            {
                mp[encodeStr] = i;
                result.push_back({str});
                i++;
            }
        }
        return result;
    }
};