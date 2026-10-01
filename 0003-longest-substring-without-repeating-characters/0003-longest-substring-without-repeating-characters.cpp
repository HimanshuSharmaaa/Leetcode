class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, 0);
        int lon = 0, l = 0, r = 0;

        while(r < s.size()){
            while(mpp[s[r]] != 0) {
                mpp[s[l]]--;
                l++;
            }

            lon = max(lon, r-l+1);
            mpp[s[r]]++;
            r++;
        }

        return lon;
    }
};