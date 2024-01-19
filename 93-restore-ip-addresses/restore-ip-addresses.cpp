class Solution {
private:
    // a function to check whether current partition is valid 
    bool isValid(string &t){
        if(t.length()==1)
        return true;

        if(t[0]=='0')
        return false;

        // convert string to number otherwise the string will be compared lexico-
        // graphically
        long long num = 0;

        for(int i=0;i<t.length();i++){
            num += t[i]-'0';
            num = (num%mod * 10)%mod;
        }

        return num/10<=255;
    }

    // count stores the number of dots encountered
    void solve(string &s,int index,vector<string>&ans,int count,string temp){
        // base cases
        int n = s.length();

        if(index>=n && count==4){ // we have reached a possible ans
            temp.pop_back();
            ans.push_back(temp);
            return;
        } 

        if(count>3) //partition becomes invalid 
        return;
        
        // start a for loop for partitioning 
        for(int j=index;j<min(index+3,n);j++){
            // get the left partion upto index j from index "index"
            string str = s.substr(index,j-index+1);

            if(isValid(str)){
                // cout<<str<<" ";
                temp.append(str+".");

                solve(s,j+1,ans,count+1,temp);

                // backtrack (pop the string str from temp string)
                int len1 = temp.length();
                int len2 = str.length();

                temp.erase(len1-len2-1);

                // 255.255.11.
                // 255.255.
            }
        }
    }
public:
    int mod = 1e9+7;

    vector<string> restoreIpAddresses(string s) {
        // use the method of front partitioning here
        vector<string> ans;
        solve(s,0,ans,0,"");

        return ans;
    }
};