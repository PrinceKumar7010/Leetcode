class Solution {
public:
    string removeStars(string s) {
     stack<char> st;
       string ans="";
       int i=0;
       int n=s.length();
       while(i < n) {
           if(s[i] != '*')
               st.push(s[i]);
           else {
               if(!st.empty())
                   st.pop();
           }
           i++;
       }

       while(!st.empty()) {
           ans += st.top();
           st.pop();
       }

       reverse(ans.begin(), ans.end()); 

       return ans;
    }
};