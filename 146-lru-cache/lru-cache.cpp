struct Node{
    int key;
    int val;
    Node(int k, int v) : key(k), val(v){};
    Node(){};
};

class LRUCache{
    public:
        LRUCache(int capacity)
        {
            cap = capacity;
        }

        void put(int key, int val)
        {
            // not in the cache
        

            if (mp.end() == mp.find(key))
            {
                // check if exceeding capacity
                if (li.size()>=cap)
                {
                    // remove last element
                    auto it = li.back();
                    li.pop_back();
                    mp.erase(it.key);
                }
            }
            else
            {
                // in the cache, remove element from the cache
                li.erase(mp[key]);
            }

            // insert key,val
            li.push_front(Node(key,val));
            mp[key] = li.begin();
        }

        int get(int key)
        {
            if (mp.end() == mp.find(key))
            {
                return -1;
            }

            auto it = *mp[key];
            li.erase(mp[key]);
            li.push_front(it);
            mp[key] = li.begin();
            return it.val;
        }
    private:
        int cap;
        list<Node> li;
        unordered_map<int,list<Node>::iterator> mp;
};


class LRUCache11{
    public:
        LRUCache11 (int v)
        {
            cap = v;
        }
    
    
        // put, get
        int get(int key)
        {
            // key is in the cache
            // key is not in the cache
            if (mp.end() != mp.find(key))
            {
                auto it = *mp[key];
                // bring this key-val to the begining of the cache
                li.erase(mp[key]);
                li.push_front(it);
                mp[key] = li.begin();
                return (it.val);
            }
            return -1;
        }
    
        void put(int key, int val)
        {
            if (mp.end() == mp.find(key))
            {
                if (li.size() >= cap)
                {
                    // remove last element
                    auto it = li.back();
                    li.pop_back();
                    mp.erase(it.key);
                }
            }
            else
            {
                li.erase(mp[key]);
            }
            
            li.push_front(Node(key,val));
            mp[key] = li.begin();
    
        }
    private:
        int cap;
        list<Node> li;
        unordered_map<int,list<Node>::iterator> mp;
};

class LRUCache13{
    public:
        LRUCache13(int capacity):cap(capacity){};
        int get(int key)
        {
            // key is not in the cache
            if (mp.end() == mp.find(key))
            {
                return -1;
            }
            
            // key is in cache
            // move the key to the front of the list
            
            auto it = *mp[key];
            li.erase(mp[key]);
            li.push_front(it);
            mp[key] = li.begin();
            
            return it.val;
        }
    
        void put(int key, int value)
        {
            // key is in the cache
            // remove key from the cache
            if (mp.end() != mp.find(key))
            {
                li.erase(mp[key]);
            }
            // key is not in the cache
            else
            {
                if (li.size() >= cap)
                {
                    // remove the last element in the list
                    auto it = li.back();
                    mp.erase(it.key);
                    li.pop_back();
                }
            }
            
            // add key and value to the front of the list
            li.push_front(Node(key,value));
            mp[key] = li.begin();
        }
    private:
        list<Node> li;
        unordered_map<int,list<Node>::iterator> mp;
        int cap;
        
};


class LRUCache7{
public:
  int get(int key)
  {
      if (mp.end() != mp.find(key))
      {
          // key is in the cache
          // get node from the list
          auto it = *mp[key];
          // remove note from the list
          dq.erase(mp[key]);
          //push node to the front of the list
          dq.push_front(it);
          // update key position in the list
          mp[key] = dq.begin();
          return it.val;
      }
      return -1; // not found error code
  }
    
  void put(int key, int value)  
  {
      // key in the cache
        //remove key from the cache
      // key is not in the cache
        //check for capacity
      if (mp.end() != mp.find(key))
      {
          dq.erase(mp[key]);
      }
      else
      {
          if (dq.size() >= cap)
          {
              auto it = dq.back();
              
              // erase last element from the dq (cache invalidate)
              mp.erase(it.key);
              dq.pop_back();
          }
      }
      
      dq.push_front(Node(key,value));
      mp[key] = dq.begin();
  }
    
  LRUCache7(int capacity)  
  {
      cap = capacity;
  }
    
    
private:
    list<Node> dq;
    unordered_map<int, list<Node>::iterator> mp;
    int cap;
};














class LRUCache6 {
public:
    LRUCache6(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        /*
            key is in cache
                add key to the top of the cache
                return key value
            key is not in cache
                return -1
        */
        if (mp.end() != mp.find(key))    
        {
            // key is in the cache
            // get the val; move key to the top of the list
            auto it = *mp[key];
            lt.erase(mp[key]);
            lt.push_front(it);
            mp[key] = lt.begin();
            return it.val;
        }
        return -1;

    }
    
    void put(int key, int value) {
        /*
        if key in in cache
            delete it from the cache
        if key is not in cache
            if cache size> cap
                Remove last element
        add key val into the top of the cache 
        */

       if (mp.end() != mp.find(key))
       {
           lt.erase(mp[key]);
       }
       else
       {
           
           if (lt.size() >= cap)
           {
               mp.erase(lt.back().key);
               lt.pop_back();
           }
       }
       lt.push_front(Node(key,value));
       mp[key] = lt.begin(); 
       
    }
private:
    int cap;
    list<Node> lt;
    unordered_map<int, list<Node>::iterator> mp;
};




class LRUCache5 {
public:
    LRUCache5(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        /*
            key is in cache
                add key to the top of the cache
                return key value
            key is not in cache
                return -1
        */

        if (ma.end() != ma.find(key))
        {
            auto it = *ma[key];
            dq.push_front(it);
            dq.erase(ma[key]);
            ma[key] = dq.begin();
            return it.val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        /*
        if key in in cache
            delete it from the cache
        if key is not in cache
            if cache size> cap
                Remove last element
        add key val into the top of the cache 
        */

        if (ma.end() != ma.find(key))
        {
            dq.erase(ma[key]);
        }
        else
        {
            if (dq.size() >= cap)
            {
                ma.erase(dq.back().key);
                dq.pop_back();
            }
        }
        
        dq.push_front(Node(key,value));
        ma[key] = dq.begin();
        
    }
private:
    list<Node> dq;
    unordered_map<int,list<Node>::iterator> ma;
    int cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */