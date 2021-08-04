#define F first
#define S second
class TimeMap {
    unordered_map<string, vector<pair<int, string>>> m;
    
public:    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!m.count(key))   // check presence of KEY
            return "";
        
        auto data = &m[key]; // pointer, cz copying gives TLE
        
        // BINARY SEARCH
        int l=0, r=data->size()-1, mid;
        while(l<r){
            mid = (l+r+1)/2; // +1 to prevent infinite loop
            
            if((*data)[mid].F <= timestamp)
                l = mid;
            else
                r = mid-1;
        }
        return ((*data)[l].F > timestamp) ? "" : (*data)[l].S;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
