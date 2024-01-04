class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int i=0,j=s.length()-1;
while(i<j){
if(s[i]!=s[j]){
    char m=min(s[i],s[j]);
    s[i]=m;
    s[j]=m;
}
i++;
j--;


}
return s;


    }
};