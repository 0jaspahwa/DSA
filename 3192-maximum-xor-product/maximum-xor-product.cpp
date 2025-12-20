class Solution {
public:
    typedef long long ll;
    int maximumXorProduct(long long a, long long b, int n) {
        ll xXora =0;
        ll xXorb = 0;
        int M = 1e9+7;

        for(int i=49; i>=n; i--){
            bool a_bit = ((a >> i) & 1) >0;
            bool b_bit = ((b >> i) & 1) >0;  

            if(a_bit == true){
                xXora = xXora ^ (1ll << i);
            }
            if(b_bit == true){   
                 xXorb = xXorb ^ (1ll << i);
            }    
        }

        for(int i=n-1; i>=0; i--){
            bool a_bit = ((a >> i) & 1) >0;
            bool b_bit = ((b >> i) & 1) >0;  
            
            if(a_bit == b_bit){
                xXora = xXora ^ (1ll<<i);
                xXorb = xXorb ^ (1ll<<i);
                continue;
            }

            if(xXora > xXorb){
                xXorb = xXorb ^ (1ll << i);
            }
            else{
                xXora = xXora ^ (1ll<<i);
            }
        }
        xXora = xXora % M;
        xXorb = xXorb % M;
        return (xXora * xXorb)%M;
    }
};