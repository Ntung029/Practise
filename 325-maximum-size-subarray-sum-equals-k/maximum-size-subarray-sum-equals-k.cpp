class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        // 1  0  5 3 6
        //   -1  4 2 5

        long long total = 0;
        unordered_map<long long,long long> mp;
        long long result = 0;
        for (long long i = 0; i< nums.size(); i++)
        {
            total += nums[i];
            if (total == k)
            {
                result = max(result, i+1);
            }
            if (mp.end() != mp.find(total-k))
            {
                result = max(result, i-mp[total-k]);
            }

            if (mp.end() == mp.find(total))
            {
                mp[total] = i;
            }
        }
        return result;
    }
};