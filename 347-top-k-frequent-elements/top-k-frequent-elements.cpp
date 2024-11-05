class Solution{
    public:
        vector<int> topKFrequent(vector<int>& nums, int k)
        {
            for (auto num:nums)
            {
                mapFreq[num]++;
                if (mapFreq[num]>freq.size())
                {
                    freq.push_back(set<int>{});
                }

                freq[mapFreq[num]-1].insert(num);

                if (mapFreq[num]>1)
                {
                    freq[mapFreq[num]-2].erase(num);
                }
            }


            // return the top k elements
            vector<int> result(k,0);
            int count = 0;
            for (int i = freq.size()-1; i>=0; i--)
            {
                for (int num:freq[i])
                {
                    result[count] = num;
                    count++;
                    if (count == k) return result;
                }
            }
            return result;
        }
    private:
        vector<set<int>> freq;    
        unordered_map<int,int> mapFreq;
};

class SolutionA {
    public:
        vector<int> topKFrequent(vector<int>& nums,int k)
        {
              /*
                [1,1,1,2,2,3]
                1: 3
                2: 2
                3: 1
              */
            
                vector<set<int>> freqSet;
                unordered_map<int,int> freq;
                for (const auto num:nums)
                {
                    freq[num]++;
                    if (freq[num] > freqSet.size())
                    {
                        freqSet.push_back(set<int>{});
                    }
                    freqSet[freq[num]-1].insert(num);

                    if (freq[num]>1)
                    {
                        freqSet[freq[num]-2].erase(num);
                    }
                    
                }
            
                // return the top k elements
                vector<int> result(k,0);
                int count = 0;
                for (int i = freqSet.size()-1; i>=0; i--)
                {
                    for (auto num:freqSet[i])
                    {
                        result[count] = num;
                        count++;
                        if (count == k) return result;
                    }
                }
                return result;
        }
};





class Solution3 {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k)
        {
            vector<set<int>> freqList(nums.size());
            unordered_map<int,int> freq;

            int maxFreq = -1;
            
            for (const auto num:nums)
            {
                freq[num]++;
                freqList[freq[num]-1].insert(num);
                if (freq[num]>1)
                {
                    // erase num in the previous frequent list
                    freqList[freq[num]-2].erase(num);
                }
            
            }

            vector<int> result(k,0);
            int count = 0;
            for (int i = freqList.size()-1; i>=0; i--)
            {
                for (auto num:freqList[i])
                {
                    result[count]=num;
                    count++;
                    if (count == k) return result;
                }
            }
            return result;

        }
};


// O NlogN
class Solution2 {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (const auto& num:nums)
        {
            freq[num]++;
        }

        vector<pair<int,int>> s;

        for (const auto& it:freq)
        {
            s.push_back({it.second,it.first});
        }

        sort(s.begin(),s.end(),greater<pair<int,int>>());
        vector<int> result (k,0);
        for (int i = 0; i<k; i++)
        {
            result[i] = s[i].second;
        }
        return result;
    }
};

// map of int, set: 
