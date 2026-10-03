class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, result1 = 0, result2 = 0;

        for(char c : s) {
            if(c == '(') open++;
            else close++;

            if(close > open) {
                close = 0;
                open = 0;
            }

            if(open == close) result1 = max(result1, open+close);
        }

        open = 0, close = 0;

        for(int i = s.size()-1; i >= 0; i--) {
            if(s[i] == '(') open++;
            else close++;

            if(open > close) {
                close = 0;
                open = 0;
            }

            if(open == close) result2 = max(result2, open+close);
        }

        return max(result1, result2);
    }
};