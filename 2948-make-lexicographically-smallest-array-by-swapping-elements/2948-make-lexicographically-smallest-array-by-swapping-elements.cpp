class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());

        unordered_map<int,list<int>> store;
        unordered_map<int,int> group;
        int n = nums.size(), g = 0;

        group[vec[0]] = g;
        store[g].push_back(vec[0]);

        for(int i = 1; i < n; i++) {
            if(abs(vec[i] - vec[i-1]) > limit) g++;
            group[vec[i]] = g;
            store[g].push_back(vec[i]);
        }
        
        vector<int> result(n);
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            int gNo = group[num];

            result[i] = *store[gNo].begin();
            store[gNo].pop_front();
        }

        return result;
    }
};