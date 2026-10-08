class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int open = 0;

        for(int i = 0; i < s.size(); i++) {
            if(open == 0) open++;
            else {
                if(s[i] == '(') {
                    ans += s[i];
                    open++;
                } else {
                    open--;
                    if(open != 0) ans += s[i];
                }
            }
        }

        return ans;
    }
};