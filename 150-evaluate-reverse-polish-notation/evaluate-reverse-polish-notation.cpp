class Solution {
private:
    bool isNotOp(string it){
        if(it == "+" || it == "-" || it == "*" || it == "/") return false;
        return true;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto it : tokens){
            if(isNotOp(it)){
                st.push(stoi(it));
            }else{
                int second = st.top();
                st.pop();
                int first = st.top();
                st.pop(); 

                int res;
                if(it == "+") res = ((first)) + ((second));
                if(it == "-") res = ((first)) - ((second));
                if(it == "*") res = ((first)) * ((second));
                if(it == "/") res = ((first)) / ((second));

                st.push((res));
            }
        }
        int ans = st.top();
        return ans;
    }
};