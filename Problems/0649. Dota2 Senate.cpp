class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q{};
        vector<int> people(2, 0), bans(2, 0);
        //0 -> DIRE and 1-> RADIANT

        // Counting people and adding to the queue
        for (auto ch : senate) {
            int idx = (ch == 'R') ? 1 : 0;
            people[idx]++;
            q.push(idx);
        }

        while (people[0] > 0 and people[1] > 0) {
            int idx = q.front();
            q.pop();
            //ban is used by previous senator
            if (bans[idx] > 0) {
                bans[idx]--;
                people[idx]--;
            } else {             //no bans left for this senator
                bans[idx ^ 1]++;
                q.push(idx);
            }
        }
        return (people[1] > 0) ? "Radiant" : "Dire";
    }
};
