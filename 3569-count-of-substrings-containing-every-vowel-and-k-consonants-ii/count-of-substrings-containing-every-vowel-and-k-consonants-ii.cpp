class Solution {
public:
     bool isvowel(char &ch){
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' ||ch == 'u';
                
        }
    long long countOfSubstrings(string word, int k) {
       

        int n= word.length();
        unordered_map<char, int> mp;

        vector<int> nextconst(n);
        int lastconst = n;
        for(int i = n-1; i>=0; i--){
            nextconst[i] = lastconst;
            if(!isvowel(word[i])){
                lastconst = i;
            }
        }
        int i=0;
        int j=0;
        long long count =0;
        int cons =0;

        while(j < n){
            char ch = word[j];
            if(isvowel(ch)){
                mp[ch]++;
            }
            else{
                cons++;
            }

            while(i < n && cons > k){
                char ch = word[i];
                if(isvowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }    
                }
                else{
                    cons--; 
                }
                i++;
            }

            while( i<n && mp.size() == 5 && cons == k){
                int idx = nextconst[j];
                count += idx - j;
                char ch = word[i];
                if(isvowel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }
                else{
                    cons--;
                }
                i++;
            }
            j++;
        }
        return count;
    }
};