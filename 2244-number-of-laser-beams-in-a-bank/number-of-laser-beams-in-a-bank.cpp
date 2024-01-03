class Solution {
public:
    int numberOfBeams(vector<string>& b) {
        vector<int> v;
     
     for(int i=0;i<b.size();i++){
        string a=b[i];
        int c=0;
        for(int j=0;j<a.length();j++){
            if(a[j]=='1')c++;
           
        }
        //  cout<<c<<" ";
        // cout<<endl;
        v.push_back(c);
     }
int p=0,mu=0,sum=0;
for(int i=0;i<v.size();i++){
    
 if((v[i]!=0)&&(v[p]!=0)&&(i!=p)){
   
    mu=v[i]*v[p];
    sum+=mu;
    p=i;
    
}
if(v[p]==0)p++;

}

    return sum;



    }
};