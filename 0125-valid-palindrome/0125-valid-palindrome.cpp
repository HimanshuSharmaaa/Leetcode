class Solution {
public:
    bool checkPalindrome(string& s, int i, int j){
        if(i > j) return true;
        if(s[i] != s[j]) return false;
        return checkPalindrome(s, i+1, j-1);
    }

    bool isPalindrome(string s) {
        if(s.size() <= 1) return true;
        string str = "";

        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z') {
                str += tolower(s[i]);
            } else if(s[i] >= '0' && s[i] <= '9') {
                str += s[i];
            }
        }

        return checkPalindrome(str, 0, str.size()-1);
    }
};