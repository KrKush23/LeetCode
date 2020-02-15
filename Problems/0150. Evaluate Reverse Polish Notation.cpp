class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st{};
        int t1{},t2{},res{};
        for(auto i:tokens){
            if(i!="+" and i!="-" and i!="*" and i!="/")
                st.push((stoi(i)));
            else{
                t1=st.top();    st.pop();
                t2=st.top();    st.pop();
                if(i=="+")
                    res=t1+t2;
                else if(i=="-")
                    res=t2-t1;
                else if(i=="*")
                    res=t1*t2;
                else
                    res=t2/t1;
                st.push(res);
            }
        }
        return st.top();
    }
};
