class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        int n = inter.size(), count = 0, end;
        sort(inter.begin(), inter.end(), compare);
        end = inter[0][0];

        for(int i = 0; i < inter.size(); i++) {
            if(end <= inter[i][0]) {
                end = inter[i][1];
                count++;
            }
        }

        if(count == 0) return count;
        return n - count;
    }
};