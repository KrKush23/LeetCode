class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res{};

        int lenMin = to_string(low).size();
        int lenMax = to_string(high).size();

        for (int l = lenMin; l <= lenMax; l++) { //generates nums length-wise
            for (int i = 1; i <= 9; i++) {  //starting digit
                int num = 0;
                for (int j = i; j < i + l and j < 10; j++) { 
                    num = num * 10 + j;
                    if (j == i + l - 1 and num >= low and num <= high) //1st condition prevents redundancy
                        res.push_back(num);
                }
            }
        }
        return res;
    }
};
