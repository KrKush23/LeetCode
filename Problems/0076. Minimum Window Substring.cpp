class Solution {
public:
    string minWindow(string s, string t) {
        // ========= Using vector instead of map (FAST) ==============
        
        int l{0}, r{0}, start{-1}, end{-1};
        int pendCnt = t.size();         // keeps track of characters missing from substring needed for making t
        vector<int> tMap(128,0);        // keeps char count using their ascii values
        for(auto i:t)
            tMap[i]++;                  // counts all chars in 't'
        for(;r < s.length();r++){       
            char rChar = s[r];
            if(tMap[rChar]>0)           //if this char is in 't'
                pendCnt--;
            tMap[rChar]--;              // minus means the char is present in s
            while(pendCnt == 0){        // if all char are present in substring
                if(start == -1 || (end-start)>(r-l)){       //when current substring is a better answer
                    start=l;
                    end=r;
                }
                char lChar = s[l];      //to keep track of the char being removed from current substring
                if(tMap[lChar] == 0)    // if an required char is being removed -> 0 means cnt was added in t and then removed in s
                    pendCnt++;
                tMap[lChar]++;;
                l++;                    // sliding the window for better answers
            }
        }
        return (start==-1)? "":s.substr(start,end-start+1);
        
        //======== Using map (SLOW) ===============
        
        // int l{0}, r{0}, start{-1}, end{-1}, pendCnt = t.size();
        // unordered_map<char,int> tMap{};
        // for(auto i:t)
        //     tMap[i]++;
        // for(;r < s.length();r++){
        //     char rChar = s[r];
        //     if(tMap[rChar]>0)
        //         pendCnt--;
        //     tMap[rChar]--;
        //     while(pendCnt == 0){
        //         if(start == -1 || (end-start)>(r-l)){
        //             start=l;
        //             end=r;
        //         }
        //         char lChar = s[l];
        //         if(tMap[lChar] == 0)
        //             pendCnt++;
        //         tMap[lChar]++;;
        //         l++;
        //     }
        // }
        // return (start==-1)? "":s.substr(start,end-start+1);
    }
};
