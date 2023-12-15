//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}

// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int a[],int n)
{
   int sum =0,sumEl=0;
    for(int i =0;i<n;i++){
        sum+=i*a[i];
        sumEl+=a[i];
    }
  
    int maxSum=0,temp=0,max=sum;
    for(int i =0;i<n;i++){
        sum=sum-sumEl+a[i]*n;
        if(sum>max){
            max=sum;
        }
    }
    return max;




}