class RandomizedSet {
    public:
        RandomizedSet(){};
    
        bool insert(int val){
            if (mp.end() == mp.find(val))
            {
                arr.push_back(val);
                mp[val] = arr.size()-1;
                return true;
            }
            return false;
        }
    
    
        bool remove(int val)
        {
            if (mp.end() == mp.find(val))
            {
                return false;
            }
            
            arr[mp[val]] = arr.back();
            mp[arr.back()] = mp[val];
            arr.pop_back();
            mp.erase(val);
            return true;
            
        }
    
    
        int getRandom()
        {
            return arr.empty() ? -1: arr[rand() % arr.size()];
        }
    
    private:
        vector<int> arr;
        unordered_map<int,int> mp;
};

class RandomizedSet5 {
public:
    RandomizedSet5() {
        
    }
    
    bool insert(int val)
    {
        // Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
        if (mp.end() == mp.find(val))
        {
            arr.push_back(val);
            mp[val] = arr.size()-1;
            return true;
        }
        return false;
    }
    
    bool remove(int val)
    {
        //Removes an item val from the set if present. Returns true if the item was present, false otherwise.
        if (mp.end() != mp.find(val))
        {
            arr[mp[val]] = arr.back();
            mp[arr.back()] = mp[val];
            mp.erase(val);
            arr.pop_back();
            
            
            return true;
        }
        return false;
    }
    
    int getRandom()
    {
        return arr.empty() ? -1: arr[rand() % arr.size()];
    }
private:
    vector<int> arr;
    unordered_map<int,int> mp;
};


class RandomizedSet2 {
public:
    RandomizedSet2() {
        
    }
    
    bool insert(int val) {
        if (mp.end() == mp.find(val))
        {
            arr.push_back(val);
            mp[val] = arr.size()-1;
            return true;
        }
        return false;
        
    }
    
    bool remove(int val) {
        if (mp.end() != mp.find(val))
        {
            mp[*arr.rbegin()] = mp[val];
            arr[mp[val]]=*arr.rbegin();// override the val element with the last element in the arr   
            mp.erase(val);
            arr.pop_back();
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return arr.empty() ? -1: arr[rand() % arr.size()];
    }
private:
    vector<int> arr; // store the value of elements
    unordered_map<int,int> mp; // store value and index of the element in the array;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */