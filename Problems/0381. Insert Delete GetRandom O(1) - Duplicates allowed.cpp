class RandomizedCollection {
    vector<int> nums{};
    map<int, unordered_set<int>> m{}; // {val, indices in array}
public:    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        m[val].insert(nums.size());
        nums.push_back(val);
        
        return m[val].size() == 1; //if '1' => wasn't present EARLIER
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {        
        if(m.count(val) and m[val].size() > 0 ){ //size of VECTOR should also be > 0
            auto free_pos = *m[val].begin(); // get INDEX
            m[val].erase(m[val].begin());    // remove index from map

            nums[free_pos] = nums.back();    // swap with LAST
            m[nums.back()].insert(free_pos); // add INDEX to LAST's map
            m[nums.back()].erase(nums.size()-1); // erase previous index from LAST's map
            nums.pop_back();                 // remove from vector

            return true;
        }
        return false;        
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        int i = rand()%nums.size();
        return nums[i];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
