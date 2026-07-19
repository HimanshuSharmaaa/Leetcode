class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool> taken(26, false);
        vector<int> mpp(26, 0);
        string result = "";

        for(int i = 0; i < s.size(); i++) mpp[s[i] - 'a'] = i;

        for(int i = 0; i < s.size(); i++){

            if(taken[s[i]-'a']) continue;

            while(result.size() > 0 && result.back() > s[i] && mpp[result.back()-'a'] > i) {
                taken[result.back()-'a'] = false;
                result.pop_back();
            } 

            taken[s[i] - 'a'] = true;
            result += s[i];
        }   

        return result;
    }
};