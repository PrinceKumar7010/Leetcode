//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

vector<int> maxleft(int *M,int n)
{
    stack<int>s;
    vector<int>ans(n);
    s.push(-1);
    for(int i=0;i<n;i++)
    {
        while(s.top()!=-1 && M[s.top()]>=M[i])
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
    }
    return ans;
}

vector<int> maxright(int *M,int n)
{
    vector<int>ans(n);
    stack<int>s;
    s.push(-1);
    for(int i=n-1;i>=0;i--)
    {
        while(s.top()!=-1 && M[s.top()]>=M[i])
        {
            s.pop();
        }
        ans[i]=s.top();
        s.push(i);
        
    }
    // reverse(ans.begin(),ans.end());
    return ans;
}

int largestarea(int *M,int n)
{
    vector<int> right(n); 
    right=maxright(M,n);
    vector<int> left(n);  
    left=maxleft(M,n);
    
    int area=INT_MIN;
    for(int i=0;i<n;i++)
    {   int l=M[i];
        if(right[i]==-1)
        right[i]=n;
        int b=right[i]-left[i]-1;
        int newarea=l*b;
        if(area<newarea)
        area=newarea;
    }
    
    return area;
}

 

class Solution{
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        //update matrix;
        int area=largestarea(M[0],m);
        
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(M[i][j]!=0)
                M[i][j]=M[i][j]+M[i-1][j];
               
            }
            int a=largestarea(M[i],m);
            if(area<a)
            area=a;
        }
        
       
        //matrix is updated;
        
        //return the answer;
        return area;
        
    }
};




//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends