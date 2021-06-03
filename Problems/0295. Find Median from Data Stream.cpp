class MedianFinder {
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    double median;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        median = 0;
    }
    
    void addNum(int num) {
        if(left.size() > right.size()){
            if(num < median){
                right.push(left.top());
                left.pop();
                left.push(num);
            }else{
                right.push(num);
            }
            median = (double)(left.top() + right.top())/ 2.0;
        } else if (left.size() < right.size()){
            if(num > median){
                left.push(right.top());
                right.pop();
                right.push(num);
            }
            else{
                left.push(num);
            }
            median = (double)(right.top() + left.top()) / 2.0;
        } else {
            //if num if < median push left
            if( num < median){
                left.push(num);
                median = (double)left.top();
            }
            //if num if > median push right
            else{
                right.push(num);
                median = (double)right.top();
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
