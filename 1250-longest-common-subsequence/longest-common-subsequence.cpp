class Solution {
public:
    int t=0;

    int longestCommonSubsequence(string s1, string s2) {
        int n=s1.length()-t;
        int m=s2.length()-t;
        t++;
       int dp[1001][1001];
        
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
               
                if(i==0||j==0)
                dp[i][j]=0;     
                
                else if (s1[i-1] == s2[j-1])        
                dp[i][j] = dp[i-1][j-1] + 1; 
                
                else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]); 
            }
        }
        
    
        return dp[n][m];  
    }
};