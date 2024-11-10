class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {

        // odd jump: 1,3,5 : i-> j: arr[i] <= arr[j]: 12345367
        // even jump: 2,4,6: i,j: arr[i] >= arr[j]
        int N = arr.size();
        vector<bool> isOddJumpPossible(N,false);
        vector<bool> isEvenJumpPossible(N,false);
        isOddJumpPossible[N-1] = true;
        isEvenJumpPossible[N-1] = true;
        int result = 1;
        map<int,int> idx; // store the index of element in arr; sorted hash map
        idx[arr[N-1]] = N-1;

        for (int i = N-2; i>=0; i--)
        {
            // find the nextElement that can jump from i
            auto nextOddJump = idx.lower_bound(arr[i]); // arr[i] <= nextOddJump
            auto nextEvenJump = idx.upper_bound(arr[i]);
            if (idx.end() != nextOddJump)
            {
                // at idx i can jump to idx at nextOddJump: odd jump to even jump
                isOddJumpPossible[i] = isEvenJumpPossible[nextOddJump->second];
            }

            if (isOddJumpPossible[i]) result++;

            if (idx.begin() != nextEvenJump)
            {
                nextEvenJump--; // arr[i] >= nextEvenJump

                isEvenJumpPossible[i] = isOddJumpPossible[nextEvenJump->second];
            }
                  idx[arr[i]] = i;
        }
  
        return result;

    }
};













class Solution7 {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> isOddJumpPossible(n,false);
        vector<bool> isEvenJumpPossible(n,false);
        map<int,int> idx;

        // we can always jump to the last index    
        int res = 1;
    
        isOddJumpPossible[n-1] = true;
        isEvenJumpPossible[n-1] = true;
        idx[arr[n-1]] = n-1;

        for (int i = n-2; i>=0; i--)
        {
            // find the next element to jump in the odd jump
            // odd jump: jump to higher value
            auto nextElementInOddJump = idx.lower_bound(arr[i]);
            // even jump: jump to the lower value -> upper_bound -1
            auto nextElementInEvenJump = idx.upper_bound(arr[i]);

            // From the current position, take an oddJump to the next position
            // From the next posittion, take an evenJump 
            if (idx.end() != nextElementInOddJump)
            {
                isOddJumpPossible[i] = isEvenJumpPossible[nextElementInOddJump->second];
            }
            // always start with an odd jump
            if (isOddJumpPossible[i]) res++;

            // From the current position, take an evenJump to the next position
            // From the next posittion, take an oddJump 
            if (nextElementInEvenJump != idx.begin())
            {
                nextElementInEvenJump--; // largest lower value is on the left of the upperbound 
                isEvenJumpPossible[i] = isOddJumpPossible[nextElementInEvenJump->second];
            }
            idx[arr[i]] = i;
        }
        return res;
    }
};











class Solution2 {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> isOddJumpPossible(n,false);
        vector<bool> isEvenJumpPossible(n,false);
        map<int,int> mp;
        
        
        // The last index always true
        isOddJumpPossible[n-1] = true;
        isEvenJumpPossible[n-1] = true;
        
        
        mp[arr[n-1]] = n-1;
        
        // last index always count
        int res = 1;
        
        for (int i = n-2; i>=0; i--)
        {
            auto nextElementInOddJump = mp.lower_bound(arr[i]);
            
            
            // The next Element in the Even Jump is the largest smaller
            // number compare to arr[i]
            // in this case, it should be upperBoundOf(arr[i]) -1;
            // nextElementInEvenJump -1;
            auto nextElementInEvenJump = mp.upper_bound(arr[i]);
            
            if (mp.end() != nextElementInOddJump)
            {
                // Check if can jump from this element to the end index
                isOddJumpPossible[i] = isEvenJumpPossible[nextElementInOddJump->second];
            }
            
            if (mp.begin() != nextElementInEvenJump)
            {
                // Here we minus one to get the largest smaller number
                nextElementInEvenJump--;
                
                isEvenJumpPossible[i] = isOddJumpPossible[nextElementInEvenJump->second];
             }
            
            
            if (isOddJumpPossible[i]) res++;
            
            
            mp[arr[i]] = i;
        }
        return res;
    }
};