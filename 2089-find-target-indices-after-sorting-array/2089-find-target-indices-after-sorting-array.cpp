class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0, place = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(target == nums[i]) count++;
            else if(nums[i] < target) place++;
        }

        vector<int> result;
        for(int i = 0; i < count; i++) result.push_back(place++);
        return result;
    }
};