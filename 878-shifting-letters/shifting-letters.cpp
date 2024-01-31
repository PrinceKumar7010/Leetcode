class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        vector<int> suf(n, 0);
        int sum = 0;
        for(int i=n-1;i>=0;i--){
            sum+=shifts[i]%26;
            suf[i] = sum;
        }
        for(int i=0;i<n;i++){
            s[i] = 'a' + (s[i] - 'a' + suf[i]) % 26;
        }
        return s;
    }
};