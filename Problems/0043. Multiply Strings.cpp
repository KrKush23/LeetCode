class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" or num2 == "0")
            return "0";
        
        int n = num1.length(), m = num2.length();
        reverse(begin(num1), end(num1));
        reverse(begin(num2), end(num2));
        
        vector<int> res(n+m);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                int digit = (num1[i]-'0') * (num2[j]-'0');
                
                res[i+j]   += digit;            // add as it is
                res[i+j+1] += (res[i+j] / 10);  // add carry
                res[i+j] = res[i+j] % 10;       // % 10 now
            }
        }
        
        int end = n+m-1;
        while(end>=0 and res[end] == 0)
            end--;
        
        string ans{};
        while(end>=0)
            ans += res[end--]+'0';
        
        return ans;
    }
};
