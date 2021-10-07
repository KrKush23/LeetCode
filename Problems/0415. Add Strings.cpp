class Solution {
public:
    string addStrings(string num1, string num2) {
        string res{};
        
        int i = num1.length() - 1;
        int j = num2.length() - 1;
        int carry{};
        
        while(i >= 0 or j >= 0){
            int sum {carry};
            if(i>=0)
                sum += num1[i--] - '0';
            if(j>=0)
                sum += num2[j--] - '0';
            
            carry = sum / 10;
            res += sum % 10 + '0';
        }
        
        if(carry)
            res += carry + '0';
        
        reverse(res.begin(), res.end());
        return res;
    }
};
