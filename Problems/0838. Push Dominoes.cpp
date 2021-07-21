class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> forces(n);
        
        // Calculating force from L to R
        int force = 0;
        for(int i=0; i<n; i++){
            if(dominoes[i] == 'R')
                force = n;
            else if(dominoes[i] == 'L')
                force = 0;
            else 
                force = max(force-1, 0);
            forces[i] += force;
        }
    
        // Calculating force from R to L
        force = 0;
        for(int i=n-1; i>=0; i--){
            if(dominoes[i] == 'L')
                force = n;
            else if(dominoes[i] == 'R')
                force = 0;
            else 
                force = max(force-1, 0);
            forces[i] -= force;
        }
        
        //creating strng based on forces
        string res{};
        for(auto i:forces){
            if(i>0)
                res += "R";
            else if(i<0)
                res += "L";
            else
                res += ".";
        }
        return res;
    }
};
