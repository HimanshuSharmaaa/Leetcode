class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = shifts.size(), m = s.size();
        vector<int> freq(m, 0);

        for(int i = 0; i < n; i++) {
            if(shifts[i][2] == 0) {
                freq[shifts[i][0]]--;
                if(shifts[i][1] + 1 < m) freq[shifts[i][1] + 1]++;
            } else {
                freq[shifts[i][0]]++;
                if(shifts[i][1] + 1 < m) freq[shifts[i][1] + 1]--;
            }
        }

        for(int i = 0; i < m; i++) {
            if(i > 0) freq[i] += freq[i-1];
            s[i] = char(((s[i] - 'a' + (freq[i] % 26) + 26) % 26) + 'a');
        }
        return s;
    }
};