class MyHashSet {
    vector<list<int>> hash;
    int n = 1000;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        hash.resize(n);
    }
    
    void add(int key) {
        if(!contains(key)){
            auto &hset = hash[key % n];
            hset.push_back(key);
        }
    }
    
    void remove(int key) {
        auto &hset = hash[key % n];
        hset.remove_if([key](auto el){return el == key;});
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        auto &hset = hash[key % n];
        
        for(auto i:hset){
            if(i == key)
                return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
