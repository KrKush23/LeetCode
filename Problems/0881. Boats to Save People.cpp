class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        
        int cnt{0};
        int i=0, j=people.size()-1;
        while(i<=j){
            if(i==j) // BASE CASE
                cnt++, i++;
            else if(people[i] + people[j] <= limit) // CAN BE ADJUSTED IN SAME BOAT
                cnt++, i++, j--;
            else                // NEED ANOTHER BOAT
                cnt++, j--;
        }
        return cnt;
    }
};
