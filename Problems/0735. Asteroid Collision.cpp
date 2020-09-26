class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s{};
        for (auto i : asteroids) {
            if (s.empty() or i > 0) {
                s.push(i);
            } else {
                while (true) {
                    int peek = s.top();
                    if (peek < 0) {     //same direction
                        s.push(i);
                        break;
                    } else if (peek == -i) {    //equally large
                        s.pop();
                        break;
                    } else if (peek > -i) {     //current is smaller
                        break;
                    } else {                    //current is larger
                        s.pop();
                        if (s.empty()) {        //all asteroids were destroyed
                            s.push(i);
                            break;
                        }
                    }
                }
            }
        }
        vector<int> res{};
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
