class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> compressed{};
        for(auto i:arr)
            compressed[i];
        int cnt{1};
        for(auto &i:compressed)
            i.second = cnt++;
        for(auto &i:arr)
            i=compressed[i];
        return arr;
    }
};
