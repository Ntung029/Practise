class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for (int i = 0; i<nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                mp[i] = nums[i];
            }
        }
    }

    unordered_map<int,int> getMap()
    {
        return mp;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        auto vecMp = vec.getMap();
        
        int sum = 0;
        for (auto it:mp)
        {
            if (vecMp.end() != vecMp.find(it.first))
            {
                sum += it.second*vecMp[it.first];
            }
        }
        return sum;
    }
private:
    unordered_map<int,int> mp;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);