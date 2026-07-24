class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> st1, st2;

        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                st1.insert(nums[i]^nums[j]);
            }
        }

        for(int i = 0; i < nums.size(); i++){
            for(auto &val : st1) {
                st2.insert(val^nums[i]);
            }
        }

        return st2.size();
    }
};