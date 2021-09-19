#define F first
#define S second
#define ii pair<int, int>
class Solution {
    
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetArrival = times[targetFriend][0];
        
        sort(begin(times), end(times));
        priority_queue<ii, vector<ii>, greater<ii>> reserved;
        set<int> avail;
        
        for(auto t:times){
            // collect chairs that become empty BEFORE t[0]
            while(!reserved.empty() and reserved.top().first <= t[0]){
                avail.insert(reserved.top().S);
                reserved.pop();
            }
            
            // FRIEND arrives
            if(t[0] == targetArrival)
                break;
            
            // if no avialable seats, give new
            if(avail.empty()){
                reserved.push({t[1], reserved.size()});
            }
            // if available, give smallest no.
            else{
                reserved.push({t[1], *begin(avail)});
                avail.erase(begin(avail));
            }
        }
        
        // if avail empty, give new chair else give smallest empty 
        return (avail.empty()) ? reserved.size() : *begin(avail);
    }
};
