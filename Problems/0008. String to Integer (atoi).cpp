class Solution {
public:
    int myAtoi(string str) {
        int i{0}, sign{1}, res{0};
        int n=str.length();
        
        if(n==0) return 0;
        
        //Discarding whitespaces at the beginning
        while(i<n and str[i] == ' ')
            i++;
        
        //Check for sign if present
        if(i<n and (str[i]=='+' or str[i]=='-'))
            sign = (str[i++]=='-')? -1:1;
        
        //Get the number and check for OVERFLOW/UNDERFLOW condition
        while(i<n and str[i]>='0' and str[i]<='9'){
            if(res > INT_MAX/10 || (res==INT_MAX/10 and str[i]-'0' > INT_MAX%10)){
                return (sign==1)? INT_MAX : INT_MIN;
            }
            res = res*10 + (str[i++] - '0');
        }
        return res * sign;
    }
};
