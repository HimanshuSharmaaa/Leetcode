class Solution {
public:
    int scoreOfParentheses(string s) {
        // int score = 0;
        // stack<int> st;

        // for(int i = 0; i < s.size(); i++) {
        //     if(s[i] == '(') {
        //         st.push(score);
        //         score = 0;
        //     } else {
        //         if(s[i-1] == '(') score = 1 + st.top();
        //         else score = (2*score) + st.top();
        //         st.pop();
        //     }
        // }
        // return score;

        int depth = 0, total = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                if(i > 0 && s[i-1] == ')') {
                    total += pow(2, depth);
                    depth = 0;
                }

                depth++;
            } else if(s[i-1] == '(') depth--;                
        }

        total += pow(2, depth);
        return total;
    }
};