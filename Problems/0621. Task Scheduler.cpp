#define ic pair<int, char>
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // SIMPLER APPROACH
        vector<int> count(26, 0);
        int cnt{0};
        for(auto task: tasks){
            count[task - 'A']++;
            cnt = max(cnt, count[task - 'A']);
        }
        
        int res = (cnt-1) * (n+1); //n+1 -> 'n' gap plus 1 to do task
        for(auto c:count){
            if(c == cnt)
                res++;
        }
        
        return max((int)tasks.size(), res);
        
        // REORDER STRING 'K' DISTANCE APART APPROACH (SLOW IN THIS QUESTION as return is INT)
        // ============================================
        /*
        if(n==0)
            return tasks.size();
        
        map<char, int> count;   // map
        for(auto task: tasks)
            count[task]++;
        
        priority_queue<ic> pq;  // MAX HEAP
        for(auto i:count)
            pq.push({i.second, i.first});
        
        int cnt{0};
        while(!pq.empty()){
            int k = n+1;
            vector<ic> temp{};
            while(k>0 and !pq.empty()){
                temp.push_back(pq.top());
                pq.pop();
                temp.back().first--;
                k--;
                cnt++;
            }
            
            for(auto i:temp){
                if(i.first > 0)
                    pq.push(i);
            }
            
            if(pq.empty())
                break;
            cnt += k; // if k>0 ... we need to remain idle
        }
        return cnt;
        */
    }
};
