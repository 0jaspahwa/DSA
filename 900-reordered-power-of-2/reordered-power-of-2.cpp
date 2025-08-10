class Solution {
public:
    int getnum(int n){
        int num = 0;
        while(n){
            num += pow(10,n%10);
            n /= 10;
        }
        return num;
    }
    bool reorderedPowerOf2(int n) {
        int input = getnum(n);
        for(int p=0; p<=29; p++){
            if(input == getnum(1 << p)){
                return true;
            }
        }
        return false;    
    }
};