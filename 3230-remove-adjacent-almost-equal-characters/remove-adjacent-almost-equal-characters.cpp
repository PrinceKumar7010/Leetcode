class Solution {
public:
    int removeAlmostEqualCharacters(string s) {

     int i=0,j=1,c=0;
    while(i<s.length() && j<s.length()){
if(abs(s[i]-s[j])<=1){
    s[j]='*';
    c++;}
    if(i<s.length())i++;
    if(j<s.length())j++;
}
if(c==0)return 0;
return c;

    }
};