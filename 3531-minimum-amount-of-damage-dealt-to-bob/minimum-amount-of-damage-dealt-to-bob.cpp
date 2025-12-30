class Solution {
public:
    struct enemy{
        int damage;
        int time;
    };
    typedef long long ll;
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();
        vector<enemy> enemies;
        ll totaldamage =0;

        for(int i=0; i<n; i++){ //creating a single of damage and health
            int t = (health[i] + power -1) / power;
            enemies.push_back({damage[i],t});
            totaldamage += damage[i];
        }
        auto lambda = [](const enemy& a, const enemy& b){
            return (ll) a.damage * b.time > (ll) b.damage * a.time;
        };
        sort(enemies.begin(),enemies.end(), lambda);

        ll ans =0;
        for(auto &i : enemies){
            ans += totaldamage * i.time;
            totaldamage -= i.damage;
        }
        return ans;
    }
};