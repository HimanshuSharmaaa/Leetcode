class Solution {
public:
    bool checkPalindrome(string& s, int i, int j){
        if(i > j) return true;
        if(s[i] != s[j]) return false;
        return checkPalindrome(s, i+1, j-1);
    }

    bool isPalindrome(string s) {
        if(s.size() <= 1) return true;
        int start = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
                s[start] = tolower(s[i]);
                start++;
            } else if(s[i] >= '0' && s[i] <= '9') {
                s[start] = s[i];
                start++;
            }
        }

        return checkPalindrome(s, 0, start-1);
    }
};