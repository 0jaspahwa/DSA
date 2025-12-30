class Solution {
public:
    typedef long long ll;
    ll minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll c1 = cost1;
        ll c2 = cost2;
        ll cBoth = costBoth;
        ll n1 = need1;
        ll n2 = need2;


        cBoth = min(cBoth, c1 + c2);
        c1 = min(c1, cBoth);
        c2 = min(c2, cBoth);

        ll totalCost = 0;

        
        ll common = min(n1, n2);
        totalCost += common * cBoth;
        if (n1 > n2) {
            totalCost += (n1 - n2) * c1;
        } else {
            totalCost += (n2 - n1) * c2;
        }

        return totalCost;
    }
};