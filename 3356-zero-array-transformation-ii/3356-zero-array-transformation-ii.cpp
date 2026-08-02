class Solution {
public:
    bool checkZero(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> dec(nums.size(), 0);

        for(int i = 0; i < k; i++) {
            dec[queries[i][0]] += queries[i][2];
            if(queries[i][1] + 1 < nums.size()) dec[queries[i][1]+1] -= queries[i][2];
        } 

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0) dec[i] += dec[i-1];
            if(nums[i] - dec[i] > 0) return false;
        }

        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        auto lambda = [](int x) {
            return x == 0;
        };

        if(all_of(nums.begin(), nums.end(), lambda)) return 0;
        int low = 1, high = queries.size(), mid, minQ = INT_MAX;

        while(low <= high) {
            mid = (low + high) / 2;
            if(checkZero(nums, queries, mid)) {
                minQ = min(minQ, mid);
                high = mid - 1;
            } else low = mid + 1;
        }
        
        return minQ == INT_MAX ? -1 : minQ;
    }
};