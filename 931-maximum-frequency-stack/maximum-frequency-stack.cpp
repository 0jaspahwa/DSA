class FreqStack {
public:
    unordered_map<int,int> mp;
    priority_queue<pair<int,pair<int,int>>>pq;
    int p =0;
    FreqStack() {
        
    }
    
    void push(int val) {
        mp[val]++;
        p++;
        pq.push({mp[val],{p,val}});
    }
    
    int pop() {
        auto x = pq.top();
        pq.pop();
        int val = x.second.second;
        mp[val]--;
        return val;

    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */