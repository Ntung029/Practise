class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        arr = nums;
    }

    vector<int> getArr()
    {
        return arr;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        auto vecArr = vec.getArr();
        if (arr.size() != vecArr.size())
        {
            return INT32_MIN;
        }
        int sum = 0;
        for (int i = 0; i<vecArr.size(); i++)
        {
            sum += arr[i]*vecArr[i];
        }
        return sum;
    }
private:
    vector<int> arr;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);