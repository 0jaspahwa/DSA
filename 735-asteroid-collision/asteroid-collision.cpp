class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for(auto num : asteroids){
            bool destroyed = false;
            while(!result.empty() && result.back() > 0 && num < 0 ){
                int top = result.back();
                if(top > abs(num)){
                    destroyed = true;
                    break;
                }
                else if(top == abs(num)){
                    result.pop_back();
                    destroyed = true;
                    break;
                }
                else{
                    result.pop_back();
                }
            }
            if(!destroyed){
                result.push_back(num);
            
            }
        }
        return result;
    }
};