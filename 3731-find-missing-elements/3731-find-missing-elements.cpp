class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int largest = INT_MIN, smallest = INT_MAX;
        unordered_map<int,int> mpp;
        vector<int> result;

        for(int i = 0; i < nums.size(); i++) {
            smallest = min(smallest, nums[i]);
            largest = max(largest, nums[i]);
            mpp[nums[i]]++;
        }

        while(smallest < largest) {
            if(mpp.find(smallest) == mpp.end()) result.push_back(smallest);
            smallest++;
        }

        return result;
    }
};