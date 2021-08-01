class MapSum {
    map<string, int> m;
public:
    /** Initialize your data structure here. **/    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int sum = 0;
        int l = prefix.length();
        
        for(auto it = m.lower_bound(prefix); it!=m.end(); it++)
            if(it->first.substr(0, l) == prefix)
                sum += it->second;
            else
                break;
        
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
