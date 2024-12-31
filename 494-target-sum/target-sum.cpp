class Solution {
public:
    void DFS(vector<int>& nums, int i, int target, int sum, int& result)
    {
        if (i == nums.size())
        { 
            if (target == sum)
            {
                result++;
            }
            return;
        }

        DFS(nums,i+1,target,sum+nums[i],result);
        DFS(nums,i+1,target,sum-nums[i],result);
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int result = 0;
        DFS(nums,0,target,0,result);
        return result;
    }
};