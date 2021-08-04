class RandomizedSet {
    vector<int> nums{};
    map<int,int> m{}; // {val, index in array}
    
public:    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(!m.count(val)){ // if not PRESENT already
            m[val] = nums.size();
            nums.emplace_back(val);
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.count(val)){ // if FOUND
            int idx = m[val];                 // getting index of 'val'
            m[nums[nums.size()-1]] = idx;     // updating index of last element as 'idx'
            nums[idx] = nums[nums.size()-1];  // braing last element to 'idx'
            
            nums.pop_back();    // removing from vector
            m.erase(val);       // removin from map
            // cout<<endl;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int i = rand()%nums.size();
        return nums[i];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
