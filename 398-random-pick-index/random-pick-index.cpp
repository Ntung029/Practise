class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i<nums.size(); i++)
        {
            if (mp.end() == mp.find(nums[i]))
            {
                mp.insert({nums[i],vector<int>{}});
            }
            mp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int n = mp[target].size();
        int idx = rand() % n;
        return mp[target][idx];
    }
private:
    unordered_map<int,vector<int>> mp;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */