class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size(), flag{n/4};
        for(int i=0;i<n;i++){
            if(arr[i] == arr[i+flag])
                return arr[i];
        }
        return -1;
    }
};
