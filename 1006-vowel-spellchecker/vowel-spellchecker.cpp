class Solution {
public:
    unordered_set<string> exactwords;
    unordered_map<string, string> casemap; // lowercase
    unordered_map<string, string> vowelmap;

    string toLower(const string &s){
        string res =s;
        for(char &c : res){
            c=tolower(c);
        }
        return res;
    }

    string maskvowels(const string &s){
        string res =s;
        for(char &c : res){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ){
                c ='*';
            }
        }
        return res;
    }

    string checkformatch(const string& query){
        if(exactwords.count(query)){
            return query;
        }

        string lowerquery = toLower(query);
        if(casemap.count(lowerquery)){
            return casemap[lowerquery];
        }

        string maskedquery = maskvowels(lowerquery);
        if(vowelmap.count(maskedquery)){
            return vowelmap[maskedquery];
        }

        return "";
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        for(string word : wordlist){
            exactwords.insert(word);

            string lowerword = toLower(word);
            if(casemap.find(lowerword) == casemap.end()){
                casemap[lowerword] = word;
            }

            string maskedword = maskvowels(lowerword);
            if(vowelmap.find(maskedword) == vowelmap.end()){
                vowelmap[maskedword] = word;
            }
        }
        vector<string> result;
        for(string query : queries){
            result.push_back(checkformatch(query));
        }
        return result;
    }
};