class NumArray{
public:
    NumArray(vector<int>& nums)
    {
        N = nums.size();
        arr.resize(2*N,0);
        for (int i = 0; i<N;i++)
        {
            //arr[i+N] = nums[i];
            update(i,nums[i]);
        }
    }

    int sumRange(int l, int r)
    {
        l+=N;
        r+=N;
        int result = 0;
        while (l<=r)
        {
            // left is right node
            if (l%2==1)
            {
                result+=arr[l]; 
                l++;
            }

            if (r%2==0)
            {
                result+=arr[r];
                r--;
            }
            l/=2;
            r/=2;
        }
        return result;
    }

    void update(int idx, int val)
    {
        idx+=N;
        arr[idx] = val;
        while (idx>0)
        {
            idx/=2;
            arr[idx] = arr[2*idx]+arr[2*idx+1];
        }
    }   

private:
    int N;
    vector<int> arr;
};


class NumArray2 {
public:
    vector<int> tree;
    int size;
    int N;
    NumArray2(vector<int>& nums) {
        N = nums.size();
        size = 2*N;
        tree.resize(size);
        for (int i = 0; i<N; i++)    
        {
            tree[i+N] = nums[i];
            //update(i,nums[i]);
        }

        for (int i = N - 1; i > 0; --i)
        {
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
    
    void update(int index, int val) {
        index +=N;
        tree[index] = val;
        while (index>0)
        {
            index = index/2;
            tree[index] = tree[index*2] + tree[index*2+1];
        }
    }
    
    int sumRange(int left, int right) {
        int ret = 0;
        left+=N;
        right+=N;
        while (left <=right)
        {
            // left is the right child node, move to the right one node
            if (left%2 == 1)
            {
                ret+=tree[left];
                left++;
            }
            left/=2;
            // right is the left child node, move to the left one node
            if (right%2 == 0)
            {
                ret+=tree[right];
                right--;
            }
            right/=2;
        }
        return ret;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */