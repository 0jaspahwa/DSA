class Solution {
public:
    int totalMoney(int n) {
        int loop = n/7;
        int a =1;
        int sum =0;
        for(int i=0; i<loop; i++){
            int prev = (7 * (2*a + 6)) / 2;
            sum += prev;
            a++;
        }
        int rem = n%7;
        for(int i=0; i<rem; i++){
            sum += a + i;
        }
        return sum;
    }
};