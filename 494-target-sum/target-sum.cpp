class Solution {
public:
    int total;
    int DFS(vector<int>& nums, int i, int target, int sum, vector<vector<int>>& memo)
    {
        if (i == nums.size())
        { 
            if (target == sum)
            {
                return 1;
            }
            return 0;
        }
      
        if (memo[i][total+sum] != INT32_MIN)
        {
            return memo[i][total+sum];
        }
        else
        {
            int add = DFS(nums,i+1,target,sum+nums[i],memo);
            int substract = DFS(nums,i+1,target,sum-nums[i],memo);
            memo[i][sum+total] = add+substract;
        }
        return memo[i][sum+total];
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        total = 0;
        for (auto num:nums)
        {
            total+=num;
        }
        
        vector<vector<int>> memo(nums.size(),vector<int>(2*total+1,INT32_MIN));
        return DFS(nums,0,target,0,memo);
    }
};