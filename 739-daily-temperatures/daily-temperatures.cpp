class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n =temp.size();
        stack<int> st;
        vector<int> result(n);
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && temp[i] >= temp[st.top()]){
                st.pop();
            }
            if(st.empty()){
                result[i] =0;
            }
            else{
                result[i] = st.top() - i;
            }
            st.push(i);

        }
        return result;
    }
};