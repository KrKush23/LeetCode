class RandomizedSet {
    vector<int> nums{};
    map<int,int> m{};
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(m.find(val)==m.end()){
            nums.emplace_back(val);
            m[val] = nums.size()-1;
            return 1;
        }
        return 0;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(m.find(val)!= m.end()){
            int i = m[val];
            m[nums[nums.size()-1]] = i;
            nums[i] = nums[nums.size()-1];
            nums.pop_back();
            m.erase(val);
            cout<<endl;
            return 1;
        }
        return 0;
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
