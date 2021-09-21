class MyHashMap {
    vector<list<pair<int, int>>> hash;
    int n = 10000;
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        hash.resize(n);
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        auto &hlist = hash[key % n]; // reference
        
        for(auto &el: hlist){
            if(el.first == key){
                el.second = value;
                return;
            }
        }
        hlist.push_back({key, value});
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        auto &hlist = hash[key % n]; // reference
        
        for(auto &el: hlist){
            if(el.first == key)
                return el.second;
        }
        
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        auto &hlist = hash[key % n]; // reference
        
        hlist.remove_if([key](auto el){ return el.first == key;});
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
