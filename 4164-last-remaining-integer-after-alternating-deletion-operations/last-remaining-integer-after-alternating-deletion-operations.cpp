class Solution {
public:
    typedef long long ll;
    long long lastInteger(long long n) {
        ll a =1;
        ll d =1;
        ll length =n;
        while(length>1){
            if(length>1){
                length =(length+1)/2;
                d *= 2;
            }
            if(length%2 == 0){
                a += d;
            }
            length = (length+1)/2;
            d *= 2;    
        }
        return a;
    }
};