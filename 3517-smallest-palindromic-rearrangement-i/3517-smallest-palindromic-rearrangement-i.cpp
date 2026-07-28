class Solution {
public:
    void reve(string &s){
        int low = 0, high = s.size() - 1;
        while(low < high){
            swap(s[low], s[high]);
            low++, high--;
        }
    }

    string smallestPalindrome(string s) {
        if(s.size() <= 1) return s;
        string str1 = "", str2 = "";
        vector<int> store(26, 0);
        char mid = '1';

        for(int i = 0; i < s.size(); i++) store[s[i]-'a']++;
        
        for(int i = 0; i < 26; i++) {
            int start = 0, midi = store[i]/2;
            while(start < midi) {
                str1 += char(i + 'a');
                str2 += char(i + 'a');
                store[i] = store[i] - 2;
                start++;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(store[i] > 0) {
                mid = char(i + 'a');
                break;
            }
        }

        reve(str2);
        if(mid != '1') return str1+mid+str2;
        return str1+str2;
    }
};