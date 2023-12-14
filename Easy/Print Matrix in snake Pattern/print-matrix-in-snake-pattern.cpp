//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > m)
    { 
        vector<int> v;
        int c=0;
        for(int i=0;i<m.size();i++){
            if(c%2==0){
            for(int j=0;j<m[i].size();j++){
              v.push_back(m[i][j]);
            }
                c++;
            }
            else if(c%2!=0){
            for(int j=m[i].size()-1;j>=0;j--){
            v.push_back(m[i][j]);
            }
                c++;
            }
        }
        return v;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.snakePattern(matrix);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends