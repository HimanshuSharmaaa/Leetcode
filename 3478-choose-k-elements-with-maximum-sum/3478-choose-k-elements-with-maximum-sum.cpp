class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b) { return a[0] < b[0]; }

    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2,int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        vector<long long> result(nums1.size(), 0);
        vector<vector<int>> sp;

        for (int i = 0; i < nums1.size(); i++) sp.push_back({nums1[i], i, nums2[i]});
        sort(sp.begin(), sp.end(), compare);

        int currSum = 0;
        for (int i = 0; i < sp.size(); i++) {
            if (i > 0 && sp[i][0] == sp[i-1][0]) result[sp[i][1]] = result[sp[i-1][1]]; 
            else result[sp[i][1]] = currSum;
            
            pq.push(sp[i][2]);
            currSum += sp[i][2];
            if (pq.size() > k) {
                currSum -= pq.top();
                pq.pop();
            }
        }

        return result;
    }
};