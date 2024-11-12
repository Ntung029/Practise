class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.length()<p.length())
        {
            return result;
        }

        vector<int> mp(26,0);
        vector<int> ms(26,0);
        for (const auto& ch:p)
        {
            mp[ch-'a']++;
        }

        for (int i = 0; i < p.length(); i++)
        {
            ms[s[i]-'a']++;
        }

        if (mp == ms)
        {
            result.push_back(0);
        }

        for (int r = p.length();r<s.length(); r++)
        {
            int l = r - p.length();
            ms[s[r]-'a']++;
            //cout << s[r] << " " << mp[s[r]-'a'] << endl;
            //cout << s[l] << " " << mp[s[l]-'a'] << endl;
            ms[s[l]-'a']--;
            if (mp == ms)
            {
                result.push_back(l+1);
            }
        }
        return result;
    }
};