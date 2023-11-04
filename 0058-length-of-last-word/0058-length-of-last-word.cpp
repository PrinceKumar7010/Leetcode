class Solution {
public:
    int lengthOfLastWord(string s) {
int c=0;
bool r=false;
for(int i=s.length()-1;i>=0;i--)
{
if(s[i]!=' '){
    c++;
    r=true;
}
else if(r){
    return c;
} }
return c;


    }
};