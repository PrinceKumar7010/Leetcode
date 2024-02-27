//{ Driver Code Starts
// Initial Template for C#

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DriverCode {

class GFG {
    static void Main(string[] args) {
        var testCases = Convert.ToInt32(Console.ReadLine());
        while (testCases-- > 0) {
            var N = Convert.ToInt32(Console.ReadLine());
            var elements = new int[N];
            var elements_str = Console.ReadLine().Trim().Split(' ');
            for (int i = 0; i < N; i++) {
                elements[i] = int.Parse(elements_str[i]);
            }
            var obj = new Solution();
            var res = obj.sum(elements, N);
            Console.WriteLine(res);
        }
    }
}
}
// } Driver Code Ends


//User function template for C#
class Solution{
    // function to return sum of elements
    // in an array of size n
    public int sum(int[] arr, int n) {
        int sum=0;
       for(int i=0;i<n;i++){
            sum=sum+arr[i];
    }
    return sum;
    }
}