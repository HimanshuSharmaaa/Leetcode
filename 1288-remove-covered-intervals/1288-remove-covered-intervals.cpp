class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if(a[0] == b[0]) return a[1] > b[1]; 
        return a[0] < b[0]; 
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int skip = 0, maxEnd = -1;

        for(const auto& interval : intervals){
            if(maxEnd < interval[1]) {
                maxEnd = interval[1];
                skip++;
            }
        }

        return skip;
    }
};