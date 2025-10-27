#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> visited;
        string ans = s;
        
        q.push(s);
        visited.insert(s);
        
        while(!q.empty()) {
            string cur = q.front();
            q.pop();
            
            // Update answer if current string is smaller
            ans = min(ans, cur);
            
            // --- Operation 1: Add 'a' to digits at odd indices ---
            string added = cur;
            for (int i = 1; i < (int)added.size(); i += 2) {
                added[i] = ((added[i] - '0' + a) % 10) + '0';
            }
            if (!visited.count(added)) {
                visited.insert(added);
                q.push(added);
            }

            // --- Operation 2: Rotate by 'b' ---
            string rotated = cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);
            if (!visited.count(rotated)) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }
        return ans;
    }
};
