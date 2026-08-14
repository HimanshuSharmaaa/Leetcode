class Solution {
public:
    int maximumLengthSubstring(string s) {
        int j = 0, maxLon = 0, i = 0;
        vector<int> mpp(26, 0);

        while(j < s.size()) {
            mpp[s[j] - 'a']++;

            while(mpp[s[j] - 'a'] > 2) {
                mpp[s[i] - 'a']--;
                i++;
            }

            maxLon = max(maxLon, j - i + 1);
            j++;
        }

        return maxLon;
    }
};