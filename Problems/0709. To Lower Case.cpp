class Solution {
public:
    string toLowerCase(string str) {
        // transform(str.begin(),str.end(),str.begin(),::tolower);
        
        for(auto &i:str)
            if(i >= 65 and i <= 90)
                i ^= 32;
        return str;
    }
};
