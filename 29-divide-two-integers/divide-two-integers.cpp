class Solution {
public:
    int divide(int dividend, int divisor) {

        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == divisor) return 1;
        
        bool sign = true;
        if(dividend >= 0 && divisor <0) sign = false;
        if(dividend < 0 && divisor > 0) sign = false;
        
        long n = abs((long)dividend);
        long d = abs((long)divisor);
        long long ans=0;

        while(n >= d){
            long long cnt =0;
            while(n >= d << (cnt+1)){
                cnt++;
            }
            ans += 1LL << cnt;
            n = n - (d << cnt);
        }

        return sign ? ans : -ans;
    }
};