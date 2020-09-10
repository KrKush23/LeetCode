class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1{}, v2{};
        stringstream check1(version1), check2(version2);    //Using string stream
        string str{};
        
        // Getting the nos. from the strings using getline() and stoi()
        while(getline(check1, str, '.')) v1.push_back(stoi(str));   
        while(getline(check2, str, '.')) v2.push_back(stoi(str));
        
        // Resizing smaller string with larger one
        (v1.size() > v2.size()) ? v2.resize(v1.size()) : v1.resize(v2.size());
        
        for(int i=0; i<v1.size(); i++){
            if (v1[i] > v2[i])      return 1;
            else if (v1[i] < v2[i]) return -1;
        }
        return 0;
    }
};
