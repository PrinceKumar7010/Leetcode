class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN)
        {
            if(divisor==-1) return INT_MAX;
            else if(divisor==1) return INT_MIN;
        }
        int sign = dividend^divisor;
        long long dividend_p = abs(dividend);
        //cout<<"dividend_p="<<dividend_p<<"\n";
        long long divisor_p = abs(divisor);
        if(dividend_p<divisor_p) return 0;
        int l=1, r=33;
        long long ans = 0;
        while(l<=r)
        {
            long long m = l+(r-l)/2;
            long long ret = divisor_p<<m;
            if(ret<dividend_p)
            {
                ans = max(ans, m);
                l=m+1;
            }
            else if(ret > dividend_p)
            {
                r=m-1;
            }
            else if(ret == dividend_p)
            {
                ans = m;
                break;
            }

        }

        long long ret = 1<<ans;

        ret+=divide(dividend_p-(divisor_p<<ans), divisor_p);

        return (sign<0)?-ret:ret;
        
    }
};