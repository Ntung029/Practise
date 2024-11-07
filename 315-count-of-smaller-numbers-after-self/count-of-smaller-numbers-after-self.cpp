class SegmentTree2{
public:
    SegmentTree2(int n)
    {
        N = n;
        arr.resize(2*N,0);
    }
    /* N = 5;
    //   parent      child
    // 0 1 2 3 4    
       0       
   1        2
     3   4    5
    6 7 8 9 10 11   
    // idx = 1; 6     3    
    */    
    void insert(int idx, int val)
    {
        idx+=N;
        arr[idx] += val;
        while(idx>1)
        {
            idx = idx/2;
            arr[idx] = arr[idx*2] + arr[idx*2+1];
        }
    }

    int query(int a, int b)
    {
        int result = 0;
        int l = a+N;
        int r = b+N;
        while (l<r)
        {
            if (l%2==1)
            {
                result += arr[l];
                l++;
            }
            if (r%2 == 1)
            {
                r--;
                result += arr[r];
            }
            l/=2;
            r/=2;
        }
        return result;
    }

private:
    int N;
    vector<int> arr;
};

class SegmentTree{
    public:
        SegmentTree(int val)
        {
            N = val;
            arr.resize(2*N,0);
        }

        void insert(int idx, int val)
        {
             idx+=N;
             arr[idx] += val;
             while (idx >1)
             {
                 idx /=2;
                 arr[idx] = arr[idx*2] + arr[idx*2+1];
             }
        }

        int query(int a, int b)
        {
           int l = a+N;
           int r = b+N;
           int result = 0;
          // cout << l <<" :" << r << endl;
           while (l<r)
           {
               // left is the right node, move to the right
               
             //  cout << l << " " << arr[l] << " : " << r << " " << arr[r] << endl;
               if (l%2==1)
               {
                result += arr[l];
                l++;
               }

               l/=2;
               
               // right is on the left node, move to the left
                if (r%2==1)
                {
                    r--;
                    result +=arr[r];
                    
                }

                r/=2;
           }
           return result; 
        }
    private:
        int N;
        vector<int> arr;
};


class Solution{
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        vector<int> result(nums.size(),0);
        int offset = 1e4;
        auto st = SegmentTree(2*offset+1);

        for (int i = nums.size()-1; i>=0; i--)
        {
            result[i] = st.query(0, nums[i]+offset);
            st.insert(nums[i]+offset,1);
        }
        return result;
    }
};

class BITree2{
    public:

    // segment Tree


        BITree2(int val)
        { 
            N= val;
            tree.resize(2*N+1,0);
        }
        
        void insert(int idx)
        {
            tree[idx] = 1;
            while (idx > 0)
            {
                idx = idx/2;
                tree[idx] = tree[idx*2] + tree[idx*2+1];
            }
        }

                                    

        int query(int a, int b)
        {
            int result  = 0;
            int l = a+N;
            int r = b+N;
            while (l<r)
            {
                if (l%2 == 1)
                {
                    result += tree[l];
                    l++;
                }

                if (r%2 == 0)
                {
                    result += tree[r];
                    r--;
                }

                l/=2;
                r/=2;
            }
            return result;
        }
    private:
        int N;
        vector<int> tree;


};



class Solution5{
public:
    vector<int> countSmaller(vector<int>& nums)
    {
        // create a BIT tree
        // for each number add to the BIT tree
        // return the query

        int N = 2*1e4+1;
        int offset = 1e4;
        BITree2 T = BITree2(N);
        int n = nums.size();
        vector<int> result(n,0);
        for(int i = n-1; i>=0; i++)
        {
            T.insert(nums[i]+offset+1);
            result[i] =T.query(offset/2,nums[i]+offset/2+1);
        }
        return result;
    }
};

class Solution4 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int offset = 10000;
        int size = 2*offset+2; // plus a dummy node 0
        int N = nums.size();
        vector<int> tree(size,0);
        vector<int> ret(N,0);

        for (int i = N-1; i>=0; i--)
        {
            ret[i] = query(nums[i]+offset,tree);
            update(nums[i]+offset,1,tree,size);
        }
        return ret;

    }

    void update(int index, int val, vector<int>& tree, int size)
    {
        index++; // Binary index tree index starts + 1
        while (index <size)
        {
            tree[index]+=val;
            index+= index & (-index);
        }
    }

    int query(int index, vector<int>& tree)
    {
        int sum = 0;
        while (index > 0)
        {
            sum+=tree[index];
            index-= index & (-index);
        }
        return sum;
    }
};


class Solution2 {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int offset = 1e4;        // offset negative to non-negative
        int size = 2 * 1e4 + 1;  // total possible values in nums
        vector<int> tree(size * 2);
        vector<int> result;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int smaller_count = query(0, nums[i] + offset, tree, size);
            result.push_back(smaller_count);
            update(nums[i] + offset, 1, tree, size);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    // implement segment tree
    void update(int index, int value, vector<int>& tree, int size) {
        index += size;  // shift the index to the leaf
        // update from leaf to root
        tree[index] += value;
        while (index > 1) {
            index /= 2;
            tree[index] = tree[index * 2] + tree[index * 2 + 1];
        }
    }

    int query(int left, int right, vector<int>& tree, int size) {
        // return sum of [left, right)
        int result = 0;
        left += size;  // shift the index to the leaf
        right += size;
        while (left < right) {
            // if left is a right node
            // bring the value and move to parent's right node
            if (left % 2 == 1) {
                result += tree[left];
                left++;
            }
            // else directly move to parent
            left /= 2;
            // if right is a right node
            // bring the value of the left node and move to parent
            if (right % 2 == 0) {
                right--;
                result += tree[right];
            }
            // else directly move to parent
            right /= 2;
        }
        return result;
    }
};