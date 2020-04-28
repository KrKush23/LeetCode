class FirstUnique {
    queue<int> q{};
    map<int,int> freq{};
public:
    FirstUnique(vector<int>& nums) {
        for(auto i:nums){
            freq[i]++;
            if(freq[i]==1)
                q.push(i);
        }
    }
    
    int showFirstUnique() {
        if(q.empty())
            return -1;
        int temp = q.front();
        while(freq[temp]>1 and !q.empty()){
            q.pop();
            if(q.empty())
                return  -1;
            temp=q.front();
        }
        return temp;
    }
    void add(int value) {
        freq[value]++;
        if(freq[value]==1)
            q.push(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
