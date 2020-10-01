class RecentCounter {
    vector<int> v;
    int l, r;
public:
    RecentCounter() {
        l=0, r=-1;
    }
    
    int ping(int t) {
        v.push_back(t);
        r++;
        while(r<v.size() and v[r]-v[l] > 3000)
            l++;
        return r-l+1;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
