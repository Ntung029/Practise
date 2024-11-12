class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {   /*
            x  
        0123456    
        2345643
            2346345
        */

          if (nums.size() < 2)
        {
            return;
        }

        int i = nums.size()-1;
        while ((i>0) && (nums[i]<=nums[i-1]))
        {
            i--;
        }

        if (i == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // find the element to swap with
        int j = nums.size()-1;
        while ((j>i) && (nums[i-1] >= nums[j])) j--;
        swap(nums[i-1],nums[j]);
        reverse(nums.begin()+i, nums.end());
    }
};

class Solution7 {
public:
    void nextPermutation(vector<int>& nums)
    {
        /*
               x               
            1435872: num[i] < num[i-1]
               i j
            1437852: swap num[i] vs num[j] if num[i] < num[j-1]
            47654
        */

        int N = nums.size();
        if (N<2) return;

        int i = N-1;
        while ((i>0) && (nums[i] <=nums[i-1]))
        {
            i--;
        }

        // special case: i=0; 9876543 -> 3456789
        if (i == 0)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // find the swap position
        int j = N-1;
        while ((j>i) && (nums[j] <=nums[i-1]))
        {
            j--;
        }
        swap(nums[i-1], nums[j]);
        reverse(nums.begin()+i, nums.end());
    }
};

class Solution17 {
public:
    void nextPermutation(vector<int>& nums)
    {
        /*
           x 
        123423
        123423
          x  
        1234432
        1244332
        1242334
        */
        if (nums.size() < 2)
        {
            return;
        }
        
        int i = nums.size()-1;
        while ((i>0) && (nums[i] <= nums[i-1])) i--;
        


        // handle special case : 987654321
        cout << i << endl;
        if (i>0)
        {
            // i-1 is the position that nums[i] < nums[i+1]

            int j = nums.size()-1;
            while ((j>i) && (nums[i-1]>=nums[j])) j++;
            cout << j << endl;
            swap(nums[i-1],nums[j]);
            reverse(nums.begin()+i, nums.end());
        }
    }
};

class Solution4 {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n-1;
        while ((i>0) && (nums[i]<=nums[i-1]))
        {
            i--;
        }
      //  cout << i << endl;
        // 8965
        
        if(i > 0)
        {
            int k = n-1;
            while (nums[k]<=nums[i-1])
            {
                k--;
            }
            swap(nums[k],nums[i-1]);
        }
        std::reverse(nums.begin()+i,nums.end());    
    }
};