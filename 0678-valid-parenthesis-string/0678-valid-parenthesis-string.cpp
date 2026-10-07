class Solution {
public:
    // bool checkValidString(string s) {
    //     int open = 0, asterisk1 = 0, close = 0, asterisk2 = 0;

    //     for(char c : s) {
    //         if(c == '(') open++;
    //         else if(c == '*') asterisk1++;
    //         else {
    //             if(open > 0) open--;
    //             else if(asterisk1 > 0) asterisk1--;
    //             else return false;
    //         }
    //     }

    //     if(asterisk1 < open) return false;

    //     for(int i = s.size()-1; i > -1; i--) {
    //         if(s[i] == ')') close++;
    //         else if(s[i] == '*') asterisk2++;
    //         else {
    //             if(close > 0) close--;
    //             else if(asterisk2 > 0) asterisk2--;
    //             else return false;
    //         }
    //     }

    //     if(asterisk2 < close) return false;
    //     return true;
    // }

    bool checkValidString(string s){
        stack<int> open, asterisk;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') open.push(i);
            else if(s[i] == '*') asterisk.push(i);
            else {
                if(!open.empty()) open.pop();
                else if(!asterisk.empty()) asterisk.pop();
                else return false;
            }
        }

        while(!open.empty() && !asterisk.empty()) {
            if(open.top() > asterisk.top()) return false;
            open.pop(), asterisk.pop();
        }

        return open.empty();
    }
};