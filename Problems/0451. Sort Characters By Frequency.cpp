#define F first
#define S second
class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(130);
        for(auto i:s)
            freq[i]++;
        vector<pair<char,int>> v {};
        for(int i=0; i<(int)freq.size();i++){
            if(freq[i]){
                v.push_back(make_pair(char(i), freq[i]));
            }
        }
        sort(v.begin(), v.end(), [] (pair<char,int> a, pair<char,int> b){
            return a.S>b.S;
        });
        string ans {};
        for(int i = 0; i< (int)v.size(); i++){
            if(v[i].S>0)
                ans.append(v[i].S, v[i].F);  //append(arg1, arg2) -> appends arg2, arg1 times
        }
        return ans;
    }
};
