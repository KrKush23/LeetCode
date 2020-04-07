class Solution {
public:
    int countElements(vector<int>& arr) {
        map<int,int> m{};
        int cnt{0};
        for(auto i:arr)
            m[i]++;
        for(auto i:m){
            x:
            bool changes{0};
            if(i.second>0 and m.find(i.first+1)!=m.end()){
                cnt++;
                i.second--;
                changes=1;
            }
            if(changes) goto x;
        }
        return cnt;
    }
};
