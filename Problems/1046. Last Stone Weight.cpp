class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(),stones.end()); //converts the container (vector) into a max_heap
        while(stones.size()>1){
            //getiing largest element
            int y = stones.front();         // root value of max_heap
            pop_heap(stones.begin(),stones.end());  //removing from heap
            stones.pop_back();                      //removing from container(vector)
            //getting 2nd largset element
            int x = stones.front();
            pop_heap(stones.begin(),stones.end());
            stones.pop_back();
            if(x!=y){
                stones.push_back(y-x);
                push_heap(stones.begin(),stones.end());     //heapify
            }
        }
        // return (stones.empty())? 0:stones.front(); 
        // or
        return accumulate(stones.begin(),stones.end(),0);
    }
};
