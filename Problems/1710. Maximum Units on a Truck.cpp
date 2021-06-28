class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int res{0};
        vector<int> bucket(1001, 0);
        
        for(auto i:boxTypes){
            bucket[i[1]] += i[0];
        }
        
        for(int i=1000; truckSize>0 and i>=0; i--){
            if(bucket[i] == 0)
                continue;
            
            int cnt = min(truckSize, bucket[i]);
            res += cnt * i;
            truckSize -= cnt;
        }
        
        return res;
        
        // SORTING ==============================
        /*
        sort(boxTypes.begin(), boxTypes.end(), 
             [](vector<int>& a, vector<int>& b){
                return a[1] > b[1];
             });
            
        int res{};
        for(auto i:boxTypes){
            if(i[0] <= truckSize){
                res += i[0]*i[1];
                truckSize -= i[0];
            }else{
                res += truckSize*i[1];
                break;
            }
        }
        
        return res;
        */
    }
};
