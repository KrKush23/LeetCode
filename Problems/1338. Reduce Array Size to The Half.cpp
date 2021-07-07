class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int res=0, cnt=0;
        unordered_map<int, int> freq;
        for(auto i:arr) freq[i]++;
        
        // MULTISET ========================
        /*
        multiset<int, greater<int>> s;
        for(auto i:freq)   s.insert(i.second);
        
        for(auto i:s){
            res++;
            cnt+=i;
            if(cnt*2 >= n)
                break;
        }
        */
        
        // PRIORITY_QUEUE =================
        priority_queue<int> pq;
        for(auto i:freq) pq.push(i.second);
        
        while(cnt*2 < n and !pq.empty()){
            res++;
            cnt += pq.top();
            pq.pop();
        }
        
        return res;
    }
};
