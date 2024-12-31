class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2,nums1);
        int m = nums1.size();
        int n = nums2.size();
        
        int l = 0;
        int r = m;
        
        while (l<=r)
        {
            int midA = (l+r)/2;
            int midB = (m+n+1)/2-midA;
            
            int maxLeftA = midA == 0? INT32_MIN : nums1[midA-1];
            int minRightA = midA == m? INT32_MAX : nums1[midA];
            
            int maxLeftB = midB == 0? INT32_MIN : nums2[midB-1];
            int minRightB = midB == n? INT32_MAX : nums2[midB];
            
            
            if ((maxLeftA <= minRightB) && (maxLeftB <= minRightA))
            {
                if ((m+n) %2 == 0)
                {
                    return (max(maxLeftA,maxLeftB) + min(minRightA,minRightB))/2.0;
                }
                else
                {
                    return max(maxLeftA,maxLeftB);
                }
            } 
            else if (maxLeftA > minRightB)
            {
                r = midA-1;
            }
            else
            {
                l = midA+1;
            }
            
        }
        
        return 0.0;
    }
};

class Solution2 {
public:
    int p1 = 0, p2 = 0;

    // Get the smaller value between nums1[p1] and nums2[p2] and move the pointer forward.

    int getMin(vector<int>& nums1, vector<int>& nums2) {
        if (p1 < nums1.size() && p2 < nums2.size()) {
            return nums1[p1] < nums2[p2] ? nums1[p1++] : nums2[p2++];
        } else if (p1 < nums1.size()) {
            return nums1[p1++];
        } else if (p2 < nums2.size()) {
            return nums2[p2++];
        } 
        return -1;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = int(nums1.size()), n = int(nums2.size());
        
        if ((m + n) % 2 == 0) {
            for (int i = 0; i < (m + n) / 2 - 1; ++i) {
                int _ = getMin(nums1, nums2);
            }
            return (double)(getMin(nums1, nums2) + getMin(nums1, nums2)) / 2;
        } else {
            for (int i = 0; i < (m + n) / 2; ++i) {
                int _ = getMin(nums1, nums2);
            }
            return getMin(nums1, nums2);
        }
            
        return -1;
    }
};

class Solution3 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2,nums1);
        }
        
        
        int m = nums1.size();
        int n = nums2.size();
        
        int l = 0;
        int r = m;
        while (l<=r)
        {
            int midA = (l+r)/2;
            int midB = (n+m+1)/2-midA;

            int maxLeftA = (midA == 0) ? INT_MIN : nums1[midA-1];
            int minRightA = (midA == m) ? INT_MAX : nums1[midA];

            int maxLeftB = (midB == 0) ? INT_MIN : nums2[midB-1];
            int minRightB = (midB == n) ? INT_MAX : nums2[midB];

            if ((maxLeftA <= minRightB) && (maxLeftB <= minRightA))
            {
                if ((m+n) % 2 == 0)
                {
                    return (max(maxLeftA,maxLeftB) + min(minRightA,minRightB))/2.0;
                }
                else
                {
                    return max(maxLeftA,maxLeftB);
                }
            }
            else if (maxLeftA > minRightB)
            {
                r = midA-1;
            }
            else
            {
                l = midA+1;
            }
        }

            return 0.0;
    }
};