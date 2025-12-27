class Solution {
public:
    int bestClosingTime(string cust) {
        int n = cust.size();
        int cur_p = count(cust.begin(),cust.end(),'Y');
        int min_p = cur_p;
        int h = 0;
        
        for(int i=0; i<n; i++){    
            if(cust[i] == 'Y'){
                cur_p -= 1;
            }
            else{
                cur_p += 1;   
            }
            
            if(cur_p < min_p){
                min_p = cur_p;
                h = i+1;
                
            }
        }
        return h;
    }
};